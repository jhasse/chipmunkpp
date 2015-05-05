#pragma once

#include "vect.hpp"
#include "types.hpp"
#include "memory.hpp"
#include "segmentqueryinfo.hpp"

#include <chipmunk.h>
#include <functional>

#ifndef _MSC_VER
#pragma GCC visibility push(default)
#endif
namespace cp {
	class Body;
	class Space;

	/// Opaque collision shape
	class Shape {
		friend class Space;
	public:
		virtual ~Shape();
		operator cpShape*() const;
		bool pointQuery(Vect) const;
		bool segmentQuery(Vect a, Vect b, SegmentQueryInfo* = nullptr);
		void setFriction(Float);
		void setElasticity(Float);
		void setCollisionType(CollisionType);
		CollisionType getCollisionType() const;
		void setLayers(Layers);
		void setOwning(bool);
		void setUserData(DataPointer);
		void setBody(std::shared_ptr<Body> body);
		DataPointer getUserData() const;
	private:
		Shape(const Shape&);
		const Shape& operator=(const Shape&);

		std::shared_ptr<Body> body;
		std::weak_ptr<Space> space;
	protected:
		Shape(cpShape*, std::shared_ptr<Body>);

		cpShape* shape;
	};
}
#ifndef _MSC_VER
#pragma GCC visibility pop
#endif
