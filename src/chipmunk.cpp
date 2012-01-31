#include "chipmunk.hpp"

namespace cp {
	Float momentForCircle(Float m, Float r1, Float r2, Vect offset) {
		return cpMomentForCircle(m, r2, r2, offset);
	}
}
