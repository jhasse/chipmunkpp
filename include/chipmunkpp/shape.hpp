#pragma once

#include "vect.hpp"
#include "types.hpp"

#include <chipmunk.h>

namespace cp {
	class Shape {
	public:
		virtual ~Shape();
		operator cpShape*() const;
		bool pointQuery(Vect) const;
		void setFriction(Float);
		void setElasticity(Float);
		void setGroup(Group);
		void setCollisionType(CollisionType);
		void setOwning(bool);
		void setUserData(DataPointer);
		DataPointer getUserData() const;
	private:
		Shape(const Shape&);
		const Shape& operator=(const Shape&);
	protected:
		Shape(cpShape*);

		cpShape* shape;
	};
}
