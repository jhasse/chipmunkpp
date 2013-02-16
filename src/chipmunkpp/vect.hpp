#pragma once

#include "types.hpp"

#include <iosfwd>

#ifndef _MSC_VER
#pragma GCC visibility push(default)
#endif
namespace cp {
	/// 2D Vector class
	class Vect {
	public:
		/// Constructor
		Vect(Float x, Float y);

		/// Creates the zero vector.
		Vect();

		/// Copy constructor
		Vect(const cpVect&);

		/// Conversion operator to Chipmunk's cpVect.
		operator cpVect() const;

		Vect& operator/=(const Float v);
		Vect& operator*=(const Float v);
		Vect& operator-=(const Vect& rhs);
		Vect& operator-=(const Float v);
		Vect& operator+=(const Float v);
		Vect& operator+=(const Vect& rhs);
		Vect& operator++();
		Vect& operator--();

		/// Returns the length.
		Float length() const;

		/// Returns the squared length. Faster than Vect::length() when you only need to compare lengths.
		Float lengthSq() const;

		/// Returns a perpendicular vector. (90 degree rotation)
		Vect perp() const;

		/// Returns a perpendicular vector. (-90 degree rotation)
		Vect rperp() const;

		/// Returns a normalized copy.
		Vect normalize() const;

		/// Returns a normalized copy or the zero vector if the vector was already the zero vector. Protects against
		/// divide by zero errors.
		Vect normalizeSafe() const;

		/// Clamp v to length len.
		Vect clamp(Float len) const;

		/// Returns the angular direction the vector is pointing in (in radians).
		Float toAngle() const;

		/// Uses complex multiplication to return a copy rotated by v. Scaling will occur if the vector isn't a unit vector.
		Vect rotate(Vect v) const;

		/// Inverse of Vect::rotate.
		Vect unrotate(Vect v) const;

		/// x component
		Float x;

		/// y component
		Float y;

		/// Returns the unit length vector for the given angle (in radians).
		static Vect forAngle(Float a);

		/// Vector dot product.
		static Float dot(Vect v1, Vect v2);

		/// 2D vector cross product analog. The cross product of 2D vectors results in a 3D vector with only a z
		/// component. This function returns the value along the z-axis.
		static Float cross(Vect v1, Vect v2);

		/// Returns the vector projection of v1 onto v2.
		static Vect project(Vect v1, Vect v2);

		/// Linearly interpolate between a and b.
		static Vect lerp(Vect v1, Vect v2, Float t);

		/// Linearly interpolate between v1 towards v2 by distance d.
		static Vect lerpconst(Vect v1, Vect v2, Float d);

		/// Spherical linearly interpolate between v1 and v2.
		static Vect slerp(Vect v1, Vect v2, Float t);

		/// Spherical linearly interpolate between v1 towards v2 by no more than angle a in radians.
		static Vect slerpconst(Vect v1, Vect v2, Float a);

		/// Returns the distance between v1 and v2.
		static Float dist(Vect v1, Vect v2);

		/// Returns the squared distance between v1 and v2. Faster than Vect::dist when you only need to compare
		/// distances.
		static Float distSq(Vect v1, Vect v2);

		/// Returns true if the distance between v1 and v2 is less than dist.
		static bool near(Vect v1, Vect v2, Float dist);
	};

	bool operator==(const Vect& lhs, const Vect& rhs);
	bool operator!=(const Vect& lhs, const Vect& rhs);
	Vect operator*(const Vect& lhs, const Float v);
	Vect operator/(const Vect& lhs, const Float v);
	Vect operator*(const Float v, const Vect& rhs);
	Vect operator/(const Float v, const Vect& rhs);
	Float operator*(const Vect& lhs, const Vect& rhs);
	Vect operator-(const Vect& lhs, const Vect& rhs);
	Vect operator+(const Vect& lhs, const Vect& rhs);
	bool operator<(const Vect& lhs, const Vect& rhs);
	bool operator>(const Vect& lhs, const Vect& rhs);
}

std::ostream& operator<<(std::ostream&, const cp::Vect&);

#ifndef _MSC_VER
#pragma GCC visibility pop
#endif