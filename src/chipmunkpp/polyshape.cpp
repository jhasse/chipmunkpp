#include "polyshape.hpp"

namespace cp {
	PolyShape::PolyShape(std::shared_ptr<Body> body, const std::vector<Vect>& verts)
		: Shape(cpPolyShapeNewRaw(*body, static_cast<int>(verts.size()),
		                          const_cast<cpVect*>(reinterpret_cast<const cpVect*>(&verts[0])),
		                          0),
		        body) {
	}

	int PolyShape::getNumVerts() const {
		return cpPolyShapeGetCount(shape);
	}

	cp::Vect PolyShape::getVert(int i) {
		return cpPolyShapeGetVert(shape, i);
	}
}
