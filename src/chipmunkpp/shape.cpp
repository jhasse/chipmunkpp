#include "shape.hpp"
#include "body.hpp"

namespace cp {
	Shape::Shape(cpShape* s, std::shared_ptr<Body> b) : body(b), shape(s) {
	}

	Shape::~Shape() {
		cpShapeFree(shape);
	}

	Shape::operator cpShape*() const {
		return shape;
	}

	bool Shape::pointQuery(Vect p) const {
		return cpShapePointQuery(shape, p) == cpTrue;
	}

	bool Shape::segmentQuery(Vect a, Vect b, SegmentQueryInfo* const info) {
		cpSegmentQueryInfo i;
		bool rtn = cpShapeSegmentQuery(shape, a, b, &i) == cpTrue;
		if (info) {
			info->t = i.t;
			info->n = i.n;
		}
		return rtn;
	}

	void Shape::setFriction(Float f) {
		cpShapeSetFriction(shape, f);
	}

	void Shape::setElasticity(Float f) {
		cpShapeSetElasticity(shape, f);
	}

	void Shape::setGroup(Group g) {
		cpShapeSetGroup(shape, static_cast<cpGroup>(g));
	}

	void Shape::setCollisionType(CollisionType t) {
		cpShapeSetCollisionType(shape, t);
	}

	CollisionType Shape::getCollisionType() const {
		return cpShapeGetCollisionType(shape);
	}

	void Shape::setLayers(Layers l) {
		cpShapeSetLayers(shape, static_cast<cpLayers>(l));
	}

	void Shape::setUserData(DataPointer p) {
		cpShapeSetUserData(shape, p);
	}

	DataPointer Shape::getUserData() const {
		return cpShapeGetUserData(shape);
	}

	void Shape::setBody(std::shared_ptr<Body> b) {
		cpShapeSetBody(shape, b ? (*b) : (cpBody*)0);
		body = b;
	}
}
