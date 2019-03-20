#pragma once

#include <chipmunk.h>

namespace cp {
typedef cpFloat Float;
typedef cpCollisionType CollisionType;
typedef cpDataPointer DataPointer;

class Layers {
public:
	Layers();                     // no layers
	Layers(unsigned int layerNr); // one layer
	Layers operator~() const;
	Layers operator|(Layers rhs) const;
	explicit operator cpBitmask() const;

private:
	cpBitmask l;
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
