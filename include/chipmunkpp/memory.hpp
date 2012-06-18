#pragma once

#ifdef CHIPMUNKPP_BOOST
#include <boost/shared_ptr.hpp>
#include <boost/make_shared.hpp>
namespace std {
	using boost::shared_ptr;
	using boost::make_shared;
}
#else
#include <memory>
#endif
