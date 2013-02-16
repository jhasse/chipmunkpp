#pragma once

#include <chipmunk.h>

#ifndef _MSC_VER
#pragma GCC visibility push(default)
#endif
namespace cp {
	typedef cpFloat Float;
	typedef cpCollisionType CollisionType;
	typedef cpDataPointer DataPointer;

	class Layers {
	public:
		Layers(); // no layers
		Layers(unsigned int layerNr); // one layer
		Layers operator~() const;
		Layers operator|(Layers rhs) const;
#ifdef _MSC_VER
		operator cpLayers() const;
#else
		explicit operator cpLayers() const;
#endif
	private:
		cpLayers l;
	};
	const static Layers ALL_LAYERS(~(Layers()));

	class Group {
	public:
		Group(cpGroup);
#ifdef _MSC_VER
		operator cpGroup() const;
#else
		explicit operator cpGroup() const;
#endif
	private:
		cpGroup g;
	};
	const static Group NO_GROUP(CP_NO_GROUP);
}
#ifndef _MSC_VER
#pragma GCC visibility pop
#endif