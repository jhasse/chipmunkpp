#include "chipmunkpp/vect.hpp"

#include <iostream>
#include <iomanip>

namespace cp {
	Vect::Vect(Float x, Float y) : v(cpv(x, y)) {
	}

	Vect::Vect(const cpVect& vect) : v(vect) {
	}

	Vect::operator cpVect() const {
		return v;
	}

	Float Vect::x() const {
		return v.x;
	}

	Float Vect::y() const {
		return v.y;
	}
}

std::ostream& operator<<(std::ostream& out, const cp::Vect& vec)
{
	std::streamsize w = out.width(0);
	out << "(" << std::setw(w) << vec.x() << ", " << std::setw(w) << vec.y() << ")";
	return out;
}
