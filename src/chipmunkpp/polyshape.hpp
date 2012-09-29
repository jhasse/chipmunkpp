#pragma once

#include "shape.hpp"
#include "body.hpp"

#include <vector>

#pragma GCC visibility push(default)
namespace cp {
	class PolyShape : public Shape {
	public:
		PolyShape(std::shared_ptr<Body>, const std::vector<Vect>& verts, Vect offset = Vect());
		int getNumVerts() const;
		cp::Vect getVert(int);
	};
}
#pragma GCC visibility pop