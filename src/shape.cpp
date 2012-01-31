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
}
