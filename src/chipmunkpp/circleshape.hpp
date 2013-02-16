#pragma once

#include "shape.hpp"
#include "body.hpp"

#ifndef _MSC_VER
#pragma GCC visibility push(default)
#endif
namespace cp {
	/// Perfect circle shape
	class CircleShape : public Shape {
	public:
		CircleShape(std::shared_ptr<Body>, Float radius, Vect offset = Vect(0, 0));
	};
}
#ifndef _MSC_VER
#pragma GCC visibility pop
#endif