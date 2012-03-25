#pragma once

#include "shape.hpp"
#include "body.hpp"
#include "vect.hpp"

#include <chipmunk.h>

namespace cp {
	class Space {
	public:
		Space();
		~Space();
		operator cpSpace*();
		Shape& addShape(Shape&);
		void removeShape(Shape&);
		void setGravity(const Vect&);
		void addBody(const Body&);
		void step(Float);
	private:
		Space(const Space&);
		const Space& operator=(const Space&);
		cpSpace* space;
	public:
		Body staticBody;
	};
}
