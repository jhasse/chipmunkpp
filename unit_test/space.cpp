#include <boost/test/unit_test.hpp>
#include <chipmunk.hpp>

using namespace cp;

BOOST_AUTO_TEST_CASE(SpaceTest) {
	Space space;
	BOOST_CHECK(space.getGravity() == Vect());
	Vect g(5, 13);
	space.setGravity(g);
	BOOST_CHECK(space.getGravity() == g);
}