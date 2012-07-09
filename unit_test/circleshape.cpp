#include <boost/test/unit_test.hpp>
#include <chipmunk.hpp>

using namespace cp;

BOOST_AUTO_TEST_CASE(CircleShapeTest) {
	// creating a Shape without a Body shouldn't crash
	auto shape = std::make_shared<CircleShape>(nullptr, 10, Vect());
}
