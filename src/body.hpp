#pragma once

#include "vect.hpp"

#include <chipmunk.h>

namespace cp {
	class Body {
	public:
		Body(Float mass, Float inertia);
		explicit Body(cpBody*);
		~Body();
		operator cpBody*() const;
		Vect getPos() const;
		void setPos(Vect);
		Vect getVel() const;
		void setVel(Vect velocity);
		DataPointer getUserData() const;
		void setUserData(DataPointer);
	private:
		Body(const Body&);
		const Body& operator=(const Body&);
		cpBody* body;
		bool freeBody;
	};
}
