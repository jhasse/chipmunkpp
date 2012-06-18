#pragma once

#include "shape.hpp"
#include "vect.hpp"
#include "memory.hpp"

#include <vector>

namespace cp {
	typedef std::function<void(std::shared_ptr<Shape>, Float, Vect)> SegmentQueryFunc;

	class Body;

	class Space {
	public:
		Space();
		~Space();
		operator cpSpace*();
		void addShape(std::shared_ptr<Shape>);
		void removeShape(std::shared_ptr<Shape>);
		void setGravity(const Vect&);
		void addBody(std::shared_ptr<Body>);
		void removeBody(std::shared_ptr<Body>);
		void step(Float);
		void segmentQuery(Vect a, Vect b, Layers, Group, SegmentQueryFunc);
	private:
		Space(const Space&);
		const Space& operator=(const Space&);
		static void segmentQueryFunc(cpShape*, cpFloat, cpVect, void*);

		cpSpace* space;
		std::vector<std::shared_ptr<Shape>> shapes;
		std::vector<std::shared_ptr<Body>> bodies;

		struct SegmentQueryData {
			const decltype(Space::shapes)& shapes;
			SegmentQueryFunc& func;
		};
	public:
		std::shared_ptr<Body> staticBody;
	};
}
