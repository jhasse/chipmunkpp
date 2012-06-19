#pragma once

#include <chipmunk.h>

namespace cp {
	typedef cpFloat Float;
	typedef cpCollisionType CollisionType;
	typedef cpDataPointer DataPointer;

	class Layers {
	public:
		Layers(cpLayers);
		cpLayers get() const;
	private:
		cpLayers l;
	};

	class Group {
	public:
		Group(cpGroup);
		cpGroup get() const;
	private:
		cpGroup g;
	};

	const static Layers ALL_LAYERS(CP_ALL_LAYERS);
	const static Group NO_GROUP(CP_NO_GROUP);
}
