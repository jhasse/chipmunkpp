#pragma once

#include "shape.hpp"
#include "body.hpp"
#include "vect.hpp"

namespace cp {
	class SegmentShape : public Shape {
	public:
		SegmentShape(std::shared_ptr<Body>, Vect a, Vect b, Float radius);
	};
}
