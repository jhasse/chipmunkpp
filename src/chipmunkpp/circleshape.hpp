#pragma once

#include "shape.hpp"
#include "body.hpp"

#pragma GCC visibility push(default)
namespace cp {
	class CircleShape : public Shape {
	public:
		CircleShape(std::shared_ptr<Body>, Float radius, Vect offset = Vect(0, 0));
	};
}
#pragma GCC visibility pop