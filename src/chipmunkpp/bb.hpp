#pragma once

#include "vect.hpp"

#pragma GCC visibility push(default)
namespace cp {
	class BB {
	public:
		/// left
		Float l;
		/// bottom
		Float b;
		/// right
		Float r;
		/// top
		Float t;

		/// Convenience constructor for making a cp::BB fitting a circle at position p with radius r.
		static BB forCircle(Vect p, Float r);

		/// Returns true if bb contains v.
		bool contains(Vect v);
	};
}
#pragma GCC visibility pop