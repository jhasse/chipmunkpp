#include "segmentshape.hpp"

namespace cp {
	SegmentShape::SegmentShape(Body& body, Vect a, Vect b, Float radius)
		: Shape(cpSegmentShapeNew(body, a, b, radius)) {
	}
}
