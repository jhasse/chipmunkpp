#pragma once

#include "shape.hpp"
#include "body.hpp"
#include "vect.hpp"

#include <memory>
#include <vector>

namespace cp {
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
	private:
		Space(const Space&);
		const Space& operator=(const Space&);
		cpSpace* space;
		std::vector<std::shared_ptr<Shape>> shapes;
		std::vector<std::shared_ptr<Body>> bodies;
	public:
		Body staticBody;
	};
}
