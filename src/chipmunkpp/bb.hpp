#pragma once

#include "vect.hpp"

namespace cp {
/// Axis-aligned 2D bounding box type
class BB {
public:
	/// left
	Float l;
	/// bottom
	Float b;
	/// right
	Float r;
	/// top
	Float t;

	/// Convenience constructor for making a cp::BB fitting a circle at position p with radius r.
	static BB forCircle(Vect p, Float r);

	/// Returns true if bb contains v.
	bool contains(Vect v) const;
};
} // namespace cp
