#include "chipmunkpp/circleshape.hpp"

namespace cp {
	CircleShape::CircleShape(std::shared_ptr<Body> body, Float radius, Vect offset)
		: Shape(cpCircleShapeNew(*body, radius, offset), body) {
	}
}
