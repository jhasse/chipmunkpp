#include "vect.hpp"

#include <iostream>
#include <iomanip>

namespace cp {
	bool operator==(const Vect& lhs, const Vect& rhs) {
		return lhs.x == rhs.x && lhs.y == rhs.y;
	}

	bool operator!=(const Vect& lhs, const Vect& rhs) {
		return lhs.x != rhs.x || lhs.y != rhs.y;
	}

	double operator*(const Vect& lhs, const Vect& rhs) {
		return lhs.x * rhs.x +lhs.y * rhs.y;
	}

	Vect operator*(const Vect& lhs, const double v) {
		return Vect(lhs.x * v, lhs.y * v);
	}

	Vect operator/(const Vect& lhs, const double v) {
		return Vect(lhs.x / v, lhs.y / v);
	}

	Vect operator*(const double v, const Vect& rhs) {
		return Vect(rhs.x * v, rhs.y * v);
	}

	Vect operator/(const double v, const Vect& rhs) {
		return Vect(rhs.x / v, rhs.y / v);
	}

	Vect operator-(const Vect& lhs, const Vect& rhs) {
		return Vect(lhs.x - rhs.x, lhs.y - rhs.y);
	}

	Vect operator+(const Vect& lhs, const Vect& rhs) {
		return Vect(lhs.x + rhs.x, lhs.y + rhs.y);
	}

	Vect::Vect() : x(0), y(0) {}

	Vect::Vect(Float x, Float y) : x(x), y(y) {}

	Vect::Vect(const cpVect& vect) : x(vect.x), y(vect.y) {}

	Vect::operator cpVect() const {
		return cpv(x, y);
	}

	Vect& Vect::operator/=(const double v) {
		x /= v;
		y /= v;
		return *this;
	}

	Vect& Vect::operator*=(const double v) {
		x *= v;
		y *= v;
		return *this;
	}

	Vect& Vect::operator-=(const Vect& rhs) {
		x -= rhs.x;
		y -= rhs.y;
		return *this;
	}

	Vect& Vect::operator-=(const double v) {
		x -= v;
		y -= v;
		return *this;
	}

	Vect& Vect::operator+=(const double v) {
		x += v;
		y += v;
		return *this;
	}

	Vect& Vect::operator+=(const Vect& rhs) {
		x += rhs.x;
		y += rhs.y;
		return *this;
	}

	Vect& Vect::operator++() {
		++x;
		++y;
		return *this;
	}

	Vect& Vect::operator--() {
		--x;
		--y;
		return *this;
	}

	Float Vect::lengthSq() const {
		return x*x+y*y;
	}

	Float Vect::length() const {
		return sqrt(lengthSq());
	}

	Vect vlerp(Vect a, Vect b, Float t) {
		return a*(1-t)+b*t;
	}

	Float vdist(Vect a, Vect b) {
		return (a-b).length();
	}
}

std::ostream& operator<<(std::ostream& out, const cp::Vect& vec)
{
	int w = static_cast<int>(out.width(0));
	out << "(" << std::setw(w) << vec.x << ", " << std::setw(w) << vec.y << ")";
	return out;
}
