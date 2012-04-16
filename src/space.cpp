#include "chipmunkpp/space.hpp"

#include <algorithm>

namespace cp {	
	Space::Space() : space(cpSpaceNew()), staticBody(space->staticBody) {
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
		shapes.erase(std::find(std::begin(shapes), std::end(shapes), shape));
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
		bodies.erase(std::find(std::begin(bodies), std::end(bodies), body));
	}

	void Space::step(Float t) {
		cpSpaceStep(space, t);
	}
}
