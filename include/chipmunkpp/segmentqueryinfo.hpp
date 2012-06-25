#pragma once

#include "types.hpp"

#include <functional>

namespace cp {
	class Shape;

	struct SegmentQueryInfo {
		// The shape that was hit, NULL if no collision occured.
		std::shared_ptr<Shape> shape;

		// The normalized distance along the query segment in the range [0, 1].
		Float t;

		// The normal of the surface hit.
		Vect n;
	};
}