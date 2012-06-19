#include "chipmunkpp/types.hpp"

namespace cp {
	Group::Group(cpGroup g) : g(g) {
	}

	cpGroup Group::get() const {
		return g;
	}

	Layers::Layers(cpLayers l) : l(l) {
	}

	cpLayers Layers::get() const {
		return l;
	}
}
