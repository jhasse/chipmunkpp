#pragma once

#include "shape.hpp"
#include "body.hpp"

namespace cp {
	class CircleShape : public Shape {
	public:
		CircleShape(Body&, Float radius, Vect offset = Vect(0, 0));
	};
}
