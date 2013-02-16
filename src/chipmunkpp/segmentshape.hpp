#pragma once

#include "shape.hpp"
#include "body.hpp"
#include "vect.hpp"

#ifndef _MSC_VER
#pragma GCC visibility push(default)
#endif
namespace cp {
	/// Beveled (rounded) segment shape
	class SegmentShape : public Shape {
	public:
		SegmentShape(std::shared_ptr<Body>, Vect a, Vect b, Float radius);
	};
}
#ifndef _MSC_VER
#pragma GCC visibility pop
#endif