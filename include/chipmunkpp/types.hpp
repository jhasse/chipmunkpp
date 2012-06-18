#pragma once

#include <chipmunk.h>

namespace cp {
	typedef cpFloat Float;
	typedef cpGroup Group;
	typedef cpCollisionType CollisionType;
	typedef cpDataPointer DataPointer;
	typedef cpLayers Layers;

	constexpr Layers ALL_LAYERS = CP_ALL_LAYERS;
	constexpr Group NO_GROUP = CP_NO_GROUP;
}
