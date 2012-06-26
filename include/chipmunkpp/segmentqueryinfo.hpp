#pragma once

#include "types.hpp"

namespace cp {
	struct SegmentQueryInfo {
		SegmentQueryInfo() : t(0) {}
		Float t; // The normalized distance along the query segment in the range [0, 1].
		Vect n;  // The normal of the surface hit.
	};
}
