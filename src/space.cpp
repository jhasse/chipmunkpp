#include "chipmunkpp/space.hpp"
#include "chipmunkpp/body.hpp"

#include <algorithm>
#include <cassert>

namespace cp {
	Space::Space() : space(cpSpaceNew()), staticBody(std::make_shared<Body>(space->staticBody)) {
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

	void Space::add(std::shared_ptr<Shape> shape) {
		cpSpaceAddShape(space, *shape);
		shapes.push_back(shape);
	}

	void Space::remove(std::shared_ptr<Shape> shape) {
		cpSpaceRemoveShape(space, *shape);
		shapes.erase(std::find(shapes.begin(), shapes.end(), shape));
	}

	void Space::setGravity(const Vect& vect) {
		cpSpaceSetGravity(space, vect);
	}

	void Space::add(std::shared_ptr<Body> body) {
		cpSpaceAddBody(space, *body);
		bodies.push_back(body);
	}

	void Space::remove(std::shared_ptr<Body> body) {
		cpSpaceRemoveBody(space, *body);
		bodies.erase(std::find(bodies.begin(), bodies.end(), body));
	}

	void Space::step(Float t) {
		cpSpaceStep(space, t);
	}

	std::shared_ptr<Shape> Space::findPtr(cpShape* shape) const {
		if (!shape) {
			return nullptr;
		}
		auto it = std::find_if(shapes.begin(), shapes.end(),
			[&shape](const std::shared_ptr<Shape>& s){
				return *s == shape;
			});
		assert(it != shapes.end());
		return *it;
	}

	void Space::segmentQueryFunc(cpShape* shape, cpFloat t, cpVect n, void* data) {
		auto d = reinterpret_cast<SegmentQueryData*>(data);
		d->func(d->self->findPtr(shape), t, n);
	}

	void Space::segmentQuery(Vect a, Vect b, Layers layers, Group group,
	                         SegmentQueryFunc func) const {
		SegmentQueryData data = { this, func };
		cpSpaceSegmentQuery(space, a, b, layers.get(), group.get(), segmentQueryFunc, &data);
	}

	std::shared_ptr<Shape> Space::segmentQueryFirst(Vect a, Vect b, Layers layers, Group group, SegmentQueryInfo* const info) const {
		cpSegmentQueryInfo i;
		auto rtn = cpSpaceSegmentQueryFirst(space, a, b, layers.get(), group.get(), &i);
		if (info) {
			info->t = i.t;
			info->n = i.n;
		}
		return findPtr(rtn);
	}

	std::shared_ptr<Shape> Space::pointQueryFirst(Vect p, Layers layers, Group group) const {
		return findPtr(cpSpacePointQueryFirst(space, p, layers.get(), group.get()));
	}
}
