#pragma once

#include "types.hpp"
#include "vect.hpp"

namespace cp {
	/// Segment query info struct
	struct SegmentQueryInfo {
		SegmentQueryInfo() : t(0) {}
		Float t; // The normalized distance along the query segment in the range [0, 1].
		Vect n;  // The normal of the surface hit.

		inline Vect hitPoint(Vect start, Vect end) {
			return Vect::lerp(start, end, t);
		}

		inline Float hitDist(Vect start, Vect end) {
			return Vect::dist(start, end)*t;
		}
	};
}
