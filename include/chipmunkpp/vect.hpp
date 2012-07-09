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
		Vect& operator/=(const double v);
		Vect& operator*=(const double v);
		Vect& operator-=(const Vect& rhs);
		Vect& operator-=(const double v);
		Vect& operator+=(const double v);
		Vect& operator+=(const Vect& rhs);
		Vect& operator++();
		Vect& operator--();
		Float length() const;
		Float lengthSq() const;

		Float x;
		Float y;
	};

	bool operator==(const Vect& lhs, const Vect& rhs);
	bool operator!=(const Vect& lhs, const Vect& rhs);
	Vect operator*(const Vect& lhs, const double v);
	Vect operator/(const Vect& lhs, const double v);
	Vect operator*(const double v, const Vect& rhs);
	Vect operator/(const double v, const Vect& rhs);
	double operator*(const Vect& lhs, const Vect& rhs);
	Vect operator-(const Vect& lhs, const Vect& rhs);
	Vect operator+(const Vect& lhs, const Vect& rhs);

	Vect vlerp(Vect a, Vect b, Float t);
	Float vdist(Vect a, Vect b);
}

std::ostream& operator<<(std::ostream&, const cp::Vect&);
