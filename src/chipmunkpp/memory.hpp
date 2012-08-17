#pragma once

#ifdef CHIPMUNKPP_BOOST

#include <boost/shared_ptr.hpp>
#include <boost/weak_ptr.hpp>
#include <boost/make_shared.hpp>
#include <boost/function.hpp>

namespace std {
	using boost::shared_ptr;
	using boost::weak_ptr;
	using boost::make_shared;

	using boost::function;
}

#else

#include <memory>
#include <functional>

#endif
