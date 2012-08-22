#include "types.hpp"

#include <cassert>

namespace cp {
	Layers::Layers() : l(0) {
	}

	Layers::Layers(unsigned int layerNr) : l(1 << layerNr) {
		assert(0 <= layerNr && layerNr <= 31);
	}

	Layers::operator cpLayers() const {
		return l;
	}

	Layers Layers::operator~() const {
		Layers tmp;
		tmp.l = ~l;
		return tmp;
	}

	Layers Layers::operator|(Layers rhs) const {
		Layers tmp;
		tmp.l = l | rhs.l;
		return tmp;
	}

	Group::Group(cpGroup g) : g(g) {
	}

	Group::operator cpGroup () const {
		return g;
	}
}
