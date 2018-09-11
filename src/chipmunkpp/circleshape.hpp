#pragma once

#include "shape.hpp"
#include "body.hpp"

namespace cp {
	/// Perfect circle shape
	class CircleShape : public Shape {
	public:
		CircleShape(std::shared_ptr<Body>, Float radius, Vect offset = Vect(0, 0));
	};
}
