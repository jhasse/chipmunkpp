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

	Float operator*(const Vect& lhs, const Vect& rhs) {
		return lhs.x * rhs.x +lhs.y * rhs.y;
	}

	Vect operator*(const Vect& lhs, const Float v) {
		return Vect(lhs.x * v, lhs.y * v);
	}

	Vect operator/(const Vect& lhs, const Float v) {
		return Vect(lhs.x / v, lhs.y / v);
	}

	Vect operator*(const Float v, const Vect& rhs) {
		return Vect(rhs.x * v, rhs.y * v);
	}

	Vect operator/(const Float v, const Vect& rhs) {
		return Vect(rhs.x / v, rhs.y / v);
	}

	Vect operator-(const Vect& lhs, const Vect& rhs) {
		return Vect(lhs.x - rhs.x, lhs.y - rhs.y);
	}

	Vect operator+(const Vect& lhs, const Vect& rhs) {
		return Vect(lhs.x + rhs.x, lhs.y + rhs.y);
	}

	bool operator<(const Vect& lhs, const Vect& rhs) {
		return lhs.x < rhs.x && lhs.y < rhs.y;
	}

	bool operator>(const Vect& lhs, const Vect& rhs) {
		return lhs.x > rhs.x && lhs.y > rhs.y;
	}

	Vect::Vect() : x(0), y(0) {}

	Vect::Vect(Float x, Float y) : x(x), y(y) {}

	Vect::Vect(const cpVect& vect) : x(vect.x), y(vect.y) {}

	Vect::operator cpVect() const {
		return cpv(x, y);
	}

	Vect& Vect::operator/=(const Float v) {
		x /= v;
		y /= v;
		return *this;
	}

	Vect& Vect::operator*=(const Float v) {
		x *= v;
		y *= v;
		return *this;
	}

	Vect& Vect::operator-=(const Vect& rhs) {
		x -= rhs.x;
		y -= rhs.y;
		return *this;
	}

	Vect& Vect::operator-=(const Float v) {
		x -= v;
		y -= v;
		return *this;
	}

	Vect& Vect::operator+=(const Float v) {
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

	Vect Vect::perp() const {
		return Vect(-y, x);
	}

	Vect Vect::rperp() const {
		return Vect(y, -x);
	}

	Vect Vect::normalize() const {
		return *this/length();
	}

	Vect Vect::normalizeSafe() const {
		if (x == 0 && y == 0) {
			return Vect();
		} else {
			return normalize();
		}
	}

	Vect Vect::clamp(Float len) const {
		return (lengthSq() > len*len) ? normalize() * len : *this;
	}

	Float Vect::toAngle() const {
		return cpfatan2(y, x);
	}

	Float Vect::dot(Vect v1, Vect v2) {
		return v1.x * v2.x + v1.y * v2.y;
	}

	Float Vect::cross(Vect v1, Vect v2) {
		return v1.x*v2.y - v1.y*v2.x;
	}

	Vect Vect::project(Vect v1, Vect v2) {
		return Vect::dot(v1, v2) / v2.lengthSq() * v2;
	}

	Vect Vect::rotate(Vect v) const {
		return Vect(x * v.x - y * v.y, x * v.y + y * v.x);
	}

	Vect Vect::unrotate(Vect v) const {
		return Vect(x * v.x + y * v.y, y * v.x - x * v.y);
	}

	Vect Vect::lerp(Vect v1, Vect v2, Float t) {
		return v1 * (1 - t) + v2 * t;
	}

	Vect Vect::lerpconst(Vect v1, Vect v2, Float d) {
		return v1 + (v2 - v1).clamp( d);
	}

	Vect Vect::slerp(Vect v1, Vect v2, Float t) {
		auto tmp = cpvslerp(v1, v2, t);
		return Vect(tmp.x, tmp.y);
	}

	Vect Vect::slerpconst(Vect v1, Vect v2, Float a) {
		auto tmp = cpvslerpconst(v1, v2, a);
		return Vect(tmp.x, tmp.y);
	}

	Float Vect::dist(Vect v1, Vect v2) {
		return (v1-v2).length();
	}

	Float Vect::distSq(Vect v1, Vect v2) {
		return (v1-v2).lengthSq();
	}

	Vect Vect::forAngle(Float a) {
		return Vect(cpfcos(a), cpfsin(a));
	}

	bool Vect::near(Vect v1, Vect v2, Float dist) {
		return (v1-v2).lengthSq() < dist * dist;
	}
}

std::ostream& operator<<(std::ostream& out, const cp::Vect& vec)
{
	int w = static_cast<int>(out.width(0));
	out << "(" << std::setw(w) << vec.x << ", " << std::setw(w) << vec.y << ")";
	return out;
}
