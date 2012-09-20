#include "body.hpp"

namespace cp {
	Body::Body(cpFloat mass, cpFloat inertia) : body(cpBodyNew(mass, inertia)), freeBody(true) {
	}

	Body::~Body() {
		if (freeBody) {
			cpBodyFree(body);
		}
	}

	Body::Body(cpBody* body) : body(body), freeBody(false) {
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
