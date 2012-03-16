#pragma once

#include <space.hpp>
#include <body.hpp>
#include <vect.hpp>
#include <segmentshape.hpp>
#include <types.hpp>
#include <circleshape.hpp>
#include <polyshape.hpp>

namespace cp {
	Float momentForCircle(Float m, Float r1, Float r2, Vect offset = Vect(0, 0));
}
