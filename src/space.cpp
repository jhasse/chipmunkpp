#include "space.hpp"

namespace cp {
	Space::Space() : space(cpSpaceNew()), staticBody(space->staticBody) {
	}
	
	Space::~Space() {
		cpSpaceFree(space);
	}
	
	Space::operator cpSpace*() {
		return space;
	}
	
	Shape& Space::addShape(Shape& shape) {
		cpSpaceAddShape(space, shape);
		return shape;
	}
	
	void Space::removeShape(Shape& shape) {
		cpSpaceRemoveShape(space, shape);
	}

	void Space::setGravity(const Vect& vect) {
		cpSpaceSetGravity(space, vect);
	}

	void Space::addBody(const Body& body) {
		cpSpaceAddBody(space, body);
	}

	void Space::step(Float t) {
		cpSpaceStep(space, t);
	}
}
