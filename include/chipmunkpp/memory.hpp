#pragma once

#ifdef CHIPMUNKPP_BOOST
#include <boost/shared_ptr.hpp>
namespace std {
	using boost::shared_ptr;
}
#else
#include <memory>
#endif