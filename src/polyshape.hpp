#pragma once

#include "shape.hpp"
#include "body.hpp"

#include <vector>

namespace cp {
	class PolyShape : public Shape {
	public:
		PolyShape(Body&, const std::vector<cpVect>& verts, Vect offset = Vect(0, 0));
		int getNumVerts() const;
	};
}
