#pragma once

#include "vect.hpp"
#include "types.hpp"
#include "memory.hpp"

#include <chipmunk.h>
#include <functional>

namespace cp {
	class Body;

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
		void setBody(std::shared_ptr<Body> body);
		DataPointer getUserData() const;
	private:
		Shape(const Shape&);
		const Shape& operator=(const Shape&);

		std::shared_ptr<Body> body;
	protected:
		Shape(cpShape*, std::shared_ptr<Body>);

		cpShape* shape;
	};
}
