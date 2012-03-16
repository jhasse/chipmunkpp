#include "shape.hpp"

namespace cp {
	Shape::Shape(cpShape* shape) : shape(shape) {
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
}
