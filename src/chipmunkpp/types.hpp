#pragma once

#include <chipmunk.h>

#pragma GCC visibility push(default)
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
#pragma GCC visibility pop