#include "circleshape.hpp"

namespace cp {
	CircleShape::CircleShape(Body& body, Float radius, Vect offset)
		: Shape(cpCircleShapeNew(body, radius, offset)) {
	}
}
