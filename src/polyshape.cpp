#include "polyshape.hpp"

namespace cp {
	PolyShape::PolyShape(Body& body, const std::vector<cpVect>& verts, Vect offset)
		: Shape(cpPolyShapeNew(body, static_cast<int>(verts.size()), const_cast<cpVect*>(&verts[0]), offset)) {
	}
}
