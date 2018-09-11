#pragma once

#include "chipmunkpp/memory.hpp"
#include "chipmunkpp/space.hpp"
#include "chipmunkpp/body.hpp"
#include "chipmunkpp/vect.hpp"
#include "chipmunkpp/segmentshape.hpp"
#include "chipmunkpp/types.hpp"
#include "chipmunkpp/circleshape.hpp"
#include "chipmunkpp/polyshape.hpp"
#include "chipmunkpp/bb.hpp"
#include "chipmunkpp/arbiter.hpp"

namespace cp {
	Float momentForCircle(Float m, Float r1, Float r2, Vect offset = Vect(0, 0));
	Float areaForPoly(const std::vector<cp::Vect>&);
}
