#include <boost/test/unit_test.hpp>
#include <chipmunk.hpp>

using namespace cp;

BOOST_AUTO_TEST_CASE(BBTest) {
	BB bb = BB::forCircle(Vect(30, 100), 5);
	BOOST_CHECK(bb.contains(Vect(30, 100)));
	BOOST_CHECK(bb.contains(Vect(34, 100)));
	BOOST_CHECK(bb.contains(Vect(26, 102)));
	BOOST_CHECK(!bb.contains(Vect(36, 100)));
	BOOST_CHECK(!bb.contains(Vect(30, 94)));
	BOOST_CHECK(!bb.contains(Vect(20, 106)));
}