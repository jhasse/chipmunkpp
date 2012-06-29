#include "chipmunkpp/vect.hpp"

#include <iostream>
#include <iomanip>

namespace cp {
	bool operator==(const Vect& lhs, const Vect& rhs) {
		return lhs.x() == rhs.x() && lhs.y() == rhs.y();
	}

	bool operator!=(const Vect& lhs, const Vect& rhs) {
		return lhs.x() != rhs.x() || lhs.y() != rhs.y();
	}

	double operator*(const Vect& lhs, const Vect& rhs) {
		return lhs.x() * rhs.x() +lhs.y() * rhs.y();
	}

	Vect operator*(const Vect& lhs, const double v) {
		return Vect(lhs.x() * v, lhs.y() * v);
	}

	Vect operator/(const Vect& lhs, const double v) {
		return Vect(lhs.x() / v, lhs.y() / v);
	}

	Vect operator*(const double v, const Vect& rhs) {
		return Vect(rhs.x() * v, rhs.y() * v);
	}

	Vect operator/(const double v, const Vect& rhs) {
		return Vect(rhs.x() / v, rhs.y() / v);
	}

	Vect operator-(const Vect& lhs, const Vect& rhs) {
		return Vect(lhs.x() - rhs.x(), lhs.y() - rhs.y());
	}

	Vect operator+(const Vect& lhs, const Vect& rhs) {
		return Vect(lhs.x() + rhs.x(), lhs.y() + rhs.y());
	}

	Vect::Vect() : vect(cpvzero) {}

	Vect::Vect(Float x, Float y) : vect(cpv(x, y)) {}

	Vect::Vect(const cpVect& vect) : vect(vect) {}

	Vect::operator cpVect() const {
		return vect;
	}

	Float Vect::x() const {
		return vect.x;
	}

	Float Vect::y() const {
		return vect.y;
	}

	Vect& Vect::operator/=(const double v) {
		vect.x /= v;
		vect.y /= v;
		return *this;
	}

	Vect& Vect::operator*=(const double v) {
		vect.x *= v;
		vect.y *= v;
		return *this;
	}

	Vect& Vect::operator-=(const Vect& rhs) {
		vect.x -= rhs.x();
		vect.y -= rhs.y();
		return *this;
	}

	Vect& Vect::operator-=(const double v) {
		vect.x -= v;
		vect.y -= v;
		return *this;
	}

	Vect& Vect::operator+=(const double v) {
		vect.x += v;
		vect.y += v;
		return *this;
	}

	Vect& Vect::operator+=(const Vect& rhs) {
		vect.x += rhs.x();
		vect.y += rhs.y();
		return *this;
	}

	Vect& Vect::operator++() {
		++vect.x;
		++vect.y;
		return *this;
	}

	Vect& Vect::operator--() {
		--vect.x;
		--vect.y;
		return *this;
	}
}

std::ostream& operator<<(std::ostream& out, const cp::Vect& vec)
{
	std::streamsize w = out.width(0);
	out << "(" << std::setw(w) << vec.x() << ", " << std::setw(w) << vec.y() << ")";
	return out;
}
