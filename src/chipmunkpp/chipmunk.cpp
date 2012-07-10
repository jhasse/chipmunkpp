#include "chipmunk.hpp"

namespace cp {
	Float momentForCircle(Float m, Float r1, Float r2, Vect offset) {
		return cpMomentForCircle(m, r2, r2, offset);
	}

	Float areaForPoly(const std::vector<cp::Vect>& vects) {
		return cpAreaForPoly(static_cast<int>(vects.size()),
		                     reinterpret_cast<const cpVect*>(&vects[0]));
	}
}
