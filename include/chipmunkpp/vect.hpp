#pragma once

#include "types.hpp"

#include <iosfwd>

namespace cp {
	class Vect {
	public:
		Vect();
		Vect(Float, Float);
		Vect(const cpVect&);
		operator cpVect() const;
		Float x() const;
		Float y() const;
	private:
		cpVect v;
	};
}

std::ostream& operator<<(std::ostream& out, const cp::Vect& vec);
