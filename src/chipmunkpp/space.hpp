#pragma once

#include "shape.hpp"
#include "vect.hpp"
#include "memory.hpp"

#include <vector>
#include <map>

#ifndef _MSC_VER
#pragma GCC visibility push(default)
#endif
namespace cp {
	typedef std::function<void(std::shared_ptr<Shape>, Float, Vect)> SegmentQueryFunc;

	class Body;
	class Arbiter;

	/// Basic unit of simulation
	class Space {
	public:
		Space();
		explicit Space(cpSpace*);
		~Space();
		operator cpSpace*();
		void add(std::shared_ptr<Shape>);
		void add(std::shared_ptr<Body>);
		void remove(std::shared_ptr<Shape>);
		void remove(std::shared_ptr<Body>);

		/// Global gravity applied to the space. Defaults to cp::Vect(0, 0). Can be overridden on a per body basis by
		/// writing custom integration functions.
		Vect getGravity() const;
		void setGravity(const Vect&);

		void step(Float);
		void segmentQuery(Vect a, Vect b, Layers, Group, SegmentQueryFunc) const;
		std::shared_ptr<Shape> segmentQueryFirst(Vect a, Vect b, Layers, Group, SegmentQueryInfo* = nullptr) const;
		std::shared_ptr<Shape> pointQueryFirst(Vect p, Layers, Group) const;

		void addCollisionHandler(CollisionType a, CollisionType b,
		                         std::function<int(Arbiter, Space&)> begin,
		                         std::function<int(Arbiter, Space&)> preSolve,
		                         std::function<void(Arbiter, Space&)> postSolve,
		                         std::function<void(Arbiter, Space&)> separate);
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

		struct CallbackData {
			std::function<int(Arbiter, Space&)> begin;
			std::function<int(Arbiter, Space&)> preSolve;
			std::function<void(Arbiter, Space&)> postSolve;
			std::function<void(Arbiter, Space&)> separate;
			Space& self;

			CallbackData(std::function<int(Arbiter, Space&)> begin, std::function<int(Arbiter, Space&)> preSolve,
			             std::function<void(Arbiter, Space&)> postSolve, std::function<void(Arbiter, Space&)> separate,
			             Space& self)
			: begin(begin), preSolve(preSolve), postSolve(postSolve), separate(separate), self(self) {
			}
		};

		std::map<std::pair<CollisionType, CollisionType>, std::unique_ptr<CallbackData>> callbackDatas;

		static int helperBegin(cpArbiter* arb, cpSpace* s, void* d);
		static int helperPreSolve(cpArbiter* arb, cpSpace* s, void* d);
		static void helperPostSolve(cpArbiter* arb, cpSpace* s, void* d);
		static void helperSeparate(cpArbiter* arb, cpSpace* s, void* d);
	public:
		std::shared_ptr<Body> staticBody;
	};
}
#ifndef _MSC_VER
#pragma GCC visibility pop
#endif
