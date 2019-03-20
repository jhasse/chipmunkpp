#pragma once

#include <chipmunk.h>

namespace cp {

using Float = cpFloat;
using CollisionType = cpCollisionType;
using DataPointer = cpDataPointer;

class Layers {
public:
	Layers();                              // no layers
	explicit Layers(unsigned int layerNr); // one layer
	Layers operator~() const;
	Layers operator|(Layers rhs) const;
	explicit operator cpLayers() const;

private:
	cpLayers l;
};
const static Layers ALL_LAYERS(~(Layers()));

class Group {
public:
	Group(cpGroup);
	explicit operator cpGroup() const;

private:
	cpGroup g;
};
const static Group NO_GROUP(CP_NO_GROUP);

} // namespace cp
