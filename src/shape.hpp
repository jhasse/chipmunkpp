#pragma once

#include "vect.hpp"

#include <chipmunk.h>

namespace cp {
	class Shape {
	public:
		Shape(cpShape*);
		virtual ~Shape();
		operator cpShape*() const;
		bool pointQuery(Vect) const;
		void setFriction(Float);
	private:
		Shape(const Shape&);
		const Shape& operator=(const Shape&);
		cpShape* shape;
	};
}
