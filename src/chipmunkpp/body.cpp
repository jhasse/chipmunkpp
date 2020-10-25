#include "body.hpp"

namespace cp {
	Body::Body(cpFloat mass, cpFloat inertia) : body(cpBodyNew(mass, inertia)), owning(true) {
	}

	Body::Body(Body&& other) noexcept : body(other.body), owning(other.owning) {
		other.body = nullptr;
		other.owning = false;
	}

	Body::~Body() {
		if (owning) {
			cpBodyFree(body);
		}
	}

	Body::Body(cpBody* body) : body(body), owning(false) {
	}

	Body::operator cpBody*() const {
		return body;
	}

	void Body::setPos(Vect p) {
		cpBodySetPos(body, p);
	}

	Vect Body::getPos() const {
		return cpBodyGetPos(body);
	}

	Vect Body::getVel() const {
		return cpBodyGetVel(body);
	}

	void Body::setVel(Vect velocity) {
		cpBodySetVel(body, velocity);
	}

	Float Body::getVelLimit() const {
		return cpBodyGetVelLimit(body);
	}

	void Body::setVelLimit(Float limit) {
		cpBodySetVelLimit(body, limit);
	}

	DataPointer Body::getUserData() const {
		return cpBodyGetUserData(body);
	}

	void Body::setUserData(DataPointer p) {
		cpBodySetUserData(body, p);
	}
}
