#include "chipmunkpp/space.hpp"
#include "chipmunkpp/body.hpp"

#include <algorithm>
#include <cassert>

namespace cp {
	Space::Space() : space(cpSpaceNew()), staticBody(std::make_shared<Body>(space->staticBody)) {
	}

	Space::~Space() {
		cpSpaceFree(space);
	}

	Space::operator cpSpace*() {
		return space;
	}

	void Space::addShape(std::shared_ptr<Shape> shape) {
		cpSpaceAddShape(space, *shape);
		shapes.push_back(shape);
	}

	void Space::removeShape(std::shared_ptr<Shape> shape) {
		cpSpaceRemoveShape(space, *shape);
		shapes.erase(std::find(shapes.begin(), shapes.end(), shape));
	}

	void Space::setGravity(const Vect& vect) {
		cpSpaceSetGravity(space, vect);
	}

	void Space::addBody(std::shared_ptr<Body> body) {
		cpSpaceAddBody(space, *body);
		bodies.push_back(body);
	}

	void Space::removeBody(std::shared_ptr<Body> body) {
		cpSpaceRemoveBody(space, *body);
		bodies.erase(std::find(bodies.begin(), bodies.end(), body));
	}

	void Space::step(Float t) {
		cpSpaceStep(space, t);
	}

	void Space::segmentQueryFunc(cpShape* shape, cpFloat t, cpVect n, void* data) {
		auto d = reinterpret_cast<SegmentQueryData*>(data);
		auto it = std::find_if(d->shapes.begin(), d->shapes.end(),
			[&shape](const std::shared_ptr<Shape>& s){
				return *s == shape;
			});
		assert(it != d->shapes.end());
		d->func(*it, t, n);
	}

	void Space::segmentQuery(Vect a, Vect b, Layers layers, Group group,
	                         SegmentQueryFunc func) {
		SegmentQueryData data{ shapes, func };
		cpSpaceSegmentQuery(space, a, b, layers.get(), group.get(), segmentQueryFunc, &data);
	}
}
