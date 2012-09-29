#pragma once

#include "shape.hpp"
#include "vect.hpp"
#include "memory.hpp"

#include <vector>

#pragma GCC visibility push(default)
namespace cp {
	typedef std::function<void(std::shared_ptr<Shape>, Float, Vect)> SegmentQueryFunc;

	class Body;

	class Space {
	public:
		Space();
		~Space();
		operator cpSpace*();
		void add(std::shared_ptr<Shape>);
		void add(std::shared_ptr<Body>);
		void remove(std::shared_ptr<Shape>);
		void remove(std::shared_ptr<Body>);
		void setGravity(const Vect&);
		void step(Float);
		void segmentQuery(Vect a, Vect b, Layers, Group, SegmentQueryFunc) const;
		std::shared_ptr<Shape> segmentQueryFirst(Vect a, Vect b, Layers, Group, SegmentQueryInfo* = nullptr) const;
		std::shared_ptr<Shape> pointQueryFirst(Vect p, Layers, Group) const;
	private:
		Space(const Space&);
		const Space& operator=(const Space&);
		static void segmentQueryFunc(cpShape*, cpFloat, cpVect, void*);
		std::shared_ptr<Shape> findPtr(cpShape*) const;

		cpSpace* space;
		std::vector<std::shared_ptr<Shape>> shapes;
		std::vector<std::shared_ptr<Body>> bodies;

		struct SegmentQueryData {
			const Space* const self;
			SegmentQueryFunc& func;
		};
	public:
		std::shared_ptr<Body> staticBody;
	};
}
#pragma GCC visibility pop