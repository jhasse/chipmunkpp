#pragma once

#include "vect.hpp"

#include <chipmunk.h>

namespace cp {
	class Body {
	public:
		Body(cpFloat mass, cpFloat inertia);
		explicit Body(cpBody*);
		~Body();
		operator cpBody*() const;
		Vect getPos() const;
		void setPos(Vect);
		Vect getVel() const;
	private:
		Body(const Body&);
		const Body& operator=(const Body&);
		cpBody* body;
		bool freeBody;
	};
}
