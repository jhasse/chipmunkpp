#include "chipmunkpp/shape.hpp"
#include "chipmunkpp/body.hpp"

namespace cp {
	Shape::Shape(cpShape* s, std::shared_ptr<Body> b) : body(b), shape(s) {
	}

	Shape::~Shape() {
		cpShapeFree(shape);
	}

	Shape::operator cpShape*() const {
		return shape;
	}
	
	bool Shape::pointQuery(Vect p) const {
		return cpShapePointQuery(shape, p);
	}

	void Shape::setFriction(Float f) {
		cpShapeSetFriction(shape, f);
	}
	
	void Shape::setElasticity(Float f) {
		cpShapeSetElasticity(shape, f);
	}
	
	void Shape::setGroup(Group g) {
		cpShapeSetGroup(shape, g);
	}
	
	void Shape::setCollisionType(CollisionType t) {
		cpShapeSetCollisionType(shape, t);
	}
	
	void Shape::setUserData(DataPointer p) {
		cpShapeSetUserData(shape, p);
	}
	
	DataPointer Shape::getUserData() const {
		return cpShapeGetUserData(shape);
	}
	
	void Shape::setBody(std::shared_ptr<Body> b) {
		cpShapeSetBody(shape, *b);
		body = b;
	}
}
