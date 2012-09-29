#pragma once

#include "shape.hpp"
#include "body.hpp"
#include "vect.hpp"

#pragma GCC visibility push(default)
namespace cp {
	class SegmentShape : public Shape {
	public:
		SegmentShape(std::shared_ptr<Body>, Vect a, Vect b, Float radius);
	};
}
#pragma GCC visibility pop