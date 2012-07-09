#pragma once

#include "types.hpp"

namespace cp {
	struct SegmentQueryInfo {
		SegmentQueryInfo() : t(0) {}
		Float t; // The normalized distance along the query segment in the range [0, 1].
		Vect n;  // The normal of the surface hit.

		inline Vect hitPoint(Vect start, Vect end) {
			return vlerp(start, end, t);
		}

		inline Float hitDist(Vect start, Vect end) {
			return vdist(start, end)*t;
		}
	};
}
