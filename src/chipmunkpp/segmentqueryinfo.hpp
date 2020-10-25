#pragma once

#include "types.hpp"
#include "vect.hpp"

namespace cp {
/// Segment query info struct
struct SegmentQueryInfo {
	/// The normalized distance along the query segment in the range [0, 1].
	Float t = 0;

	/// The normal of the surface hit.
	Vect n;

	inline Vect hitPoint(Vect start, Vect end) const {
		return Vect::lerp(start, end, t);
	}

	inline Float hitDist(Vect start, Vect end) const {
		return Vect::dist(start, end) * t;
	}
};
} // namespace cp
