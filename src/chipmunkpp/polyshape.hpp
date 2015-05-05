#pragma once

#include "shape.hpp"
#include "body.hpp"

#include <vector>

#ifndef _MSC_VER
#pragma GCC visibility push(default)
#endif
namespace cp {
	/// Convex polygon shape
	class PolyShape : public Shape {
	public:
		PolyShape(std::shared_ptr<Body>, const std::vector<Vect>& verts);
		int getNumVerts() const;
		cp::Vect getVert(int);
	};
}
#ifndef _MSC_VER
#pragma GCC visibility pop
#endif
