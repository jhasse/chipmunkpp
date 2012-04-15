#pragma once

#include "chipmunkpp/space.hpp"
#include "chipmunkpp/body.hpp"
#include "chipmunkpp/vect.hpp"
#include "chipmunkpp/segmentshape.hpp"
#include "chipmunkpp/types.hpp"
#include "chipmunkpp/circleshape.hpp"
#include "chipmunkpp/polyshape.hpp"

namespace cp {
	Float momentForCircle(Float m, Float r1, Float r2, Vect offset = Vect(0, 0));
}
