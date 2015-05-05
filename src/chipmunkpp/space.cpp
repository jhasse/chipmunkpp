#include "space.hpp"
#include "body.hpp"
#include "arbiter.hpp"

#include <algorithm>
#include <cassert>

using namespace std;

namespace cp {
	Space::Space() : space(cpSpaceNew()), staticBody(make_shared<Body>(cpSpaceGetStaticBody(space))) {
	}

	Space::~Space() {
		for (auto& shape : shapes) {
			cpSpaceRemoveShape(space, *shape);
		}
		shapes.clear();
		cpSpaceFree(space);
	}

	Space::operator cpSpace*() {
		return space;
	}

	void Space::add(shared_ptr<Shape> shape) {
		cpSpaceAddShape(space, *shape);
		shapes.push_back(shape);
	}

	void Space::remove(shared_ptr<Shape> shape) {
		cpSpaceRemoveShape(space, *shape);
		shapes.erase(find(shapes.begin(), shapes.end(), shape));
	}

	Vect Space::getGravity() const {
		return cpSpaceGetGravity(space);
	}

	void Space::setGravity(const Vect& vect) {
		cpSpaceSetGravity(space, vect);
	}

	void Space::add(shared_ptr<Body> body) {
		cpSpaceAddBody(space, *body);
		bodies.push_back(body);
	}

	void Space::remove(shared_ptr<Body> body) {
		cpSpaceRemoveBody(space, *body);
		bodies.erase(find(bodies.begin(), bodies.end(), body));
	}

	void Space::step(Float t) {
		cpSpaceStep(space, t);
	}

	shared_ptr<Shape> Space::findPtr(cpShape* shape) const {
		if (!shape) {
			return shared_ptr<Shape>((Shape*)0);
		}
		auto it = find_if(shapes.begin(), shapes.end(),
			[&shape](const shared_ptr<Shape>& s){
				return *s == shape;
			});
		assert(it != shapes.end());
		return *it;
	}

	void Space::segmentQueryFunc(cpShape* shape, cpVect point, cpVect normal, cpFloat alpha, void* data) {
		auto d = reinterpret_cast<SegmentQueryData*>(data);
		d->func(d->self->findPtr(shape), alpha, normal);
	}

	void Space::segmentQuery(Vect a, Vect b, Layers layers, Group group,
	                         SegmentQueryFunc func) const {
		SegmentQueryData data = { this, func };
		cpShapeFilter filter{static_cast<cpGroup>(group),
		                     static_cast<cpBitmask>(layers),
		                     static_cast<cpBitmask>(layers)};
		cpSpaceSegmentQuery(space, a, b, 0, filter, segmentQueryFunc, &data);
	}

	shared_ptr<Shape> Space::segmentQueryFirst(Vect a, Vect b, Layers layers, Group group,
	                                           SegmentQueryInfo* const info) const {
		cpSegmentQueryInfo i;
		cpShapeFilter filter{static_cast<cpGroup>(group),
		                     static_cast<cpBitmask>(layers),
		                     static_cast<cpBitmask>(layers)};
		auto rtn = cpSpaceSegmentQueryFirst(space, a, b, 0, filter, &i);
		if (info) {
			info->t = i.alpha;
			info->n = i.normal;
		}
		return findPtr(rtn);
	}

	shared_ptr<Shape> Space::pointQueryFirst(Vect p, Layers layers, Group group) const {
		cpShapeFilter filter{static_cast<cpGroup>(group),
		                     static_cast<cpBitmask>(layers),
		                     static_cast<cpBitmask>(layers)};
		cpPointQueryInfo i;
		return findPtr(cpSpacePointQueryNearest(space, p, 100, filter, &i));
	}

	int Space::helperBegin(cpArbiter* arb, cpSpace* s, void* d) {
		CallbackData& data = *reinterpret_cast<CallbackData*>(d);
		return data.begin(arb, data.self);
	}

	int Space::helperPreSolve(cpArbiter* arb, cpSpace* s, void* d) {
		CallbackData& data = *reinterpret_cast<CallbackData*>(d);
		return data.preSolve(arb, data.self);
	}

	void Space::helperPostSolve(cpArbiter* arb, cpSpace* s, void* d) {
		CallbackData& data = *reinterpret_cast<CallbackData*>(d);
		return data.postSolve(arb, data.self);
	}

	void Space::helperSeparate(cpArbiter* arb, cpSpace* s, void* d) {
		CallbackData& data = *reinterpret_cast<CallbackData*>(d);
		return data.separate(arb, data.self);
	}

	void Space::addCollisionHandler(CollisionType a, CollisionType b,
	                                std::function<int(Arbiter, Space&)> begin,
	                                std::function<int(Arbiter, Space&)> preSolve,
	                                std::function<void(Arbiter, Space&)> postSolve,
	                                std::function<void(Arbiter, Space&)> separate) {
		auto data = new CallbackData(begin, preSolve, postSolve, separate, *this);
		callbackDatas[std::make_pair(a, b)] = std::unique_ptr<CallbackData>(data);
		/*cpSpaceAddCollisionHandler(space, a, b,
		                           begin == nullptr ? nullptr : helperBegin,
		                           preSolve == nullptr ? nullptr : helperPreSolve,
		                           postSolve == nullptr ? nullptr : helperPostSolve,
		                           separate == nullptr ? nullptr : helperSeparate,
		                           data);*/
	}

}
