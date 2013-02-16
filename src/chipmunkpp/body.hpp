#pragma once

#include "vect.hpp"

#include <chipmunk.h>

#ifndef _MSC_VER
#pragma GCC visibility push(default)
#endif
namespace cp {
	/**
	 * \brief Rigid body
	 *
	 * A rigid body holds the physical properties of an object. (mass, position, rotation, velocity, etc.) It does not
	 * have a shape until you attach one or more collision shapes to it. If you’ve done physics with particles before,
	 * rigid bodies differ in that they are able to rotate. Rigid bodies generally tend to have a 1:1 correlation to
	 * sprites in a game. You should structure your game so that you use the position and rotation of the rigid body
	 * for drawing your sprite.
	 **/
	class Body {
	public:
		Body(Float mass, Float inertia);
		explicit Body(cpBody*);
		~Body();
		operator cpBody*() const;
		Vect getPos() const;
		void setPos(Vect);

		/// Linear velocity of the center of gravity of the body.
		Vect getVel() const;
		void setVel(Vect velocity);

		/// Velocity limit of the body. Defaults to INFINITY unless you set it specifically. Can be used to limit
		/// falling speeds, etc.
		Float getVelLimit() const;
		void setVelLimit(Float limit);

		DataPointer getUserData() const;
		void setUserData(DataPointer);
	private:
		Body(const Body&);
		const Body& operator=(const Body&);
		cpBody* body;
		bool freeBody;
	};
}
#ifndef _MSC_VER
#pragma GCC visibility pop
#endif