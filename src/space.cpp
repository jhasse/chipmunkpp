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
	
	const Shape& Space::addShape(const Shape& shape) {
		cpSpaceAddShape(space, shape);
		return shape;
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
