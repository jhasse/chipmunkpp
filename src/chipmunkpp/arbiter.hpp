#pragma once

#include "body.hpp"

#include <chipmunk.h>

namespace cp {
class Arbiter {
public:
	Arbiter(cpArbiter*); // NOLINT
	Body getBodyA();
	Body getBodyB();

private:
	cpArbiter* arbiter;
};
} // namespace cp
