#include <boost/test/unit_test.hpp>
#include <chipmunk.hpp>

using namespace cp;

BOOST_AUTO_TEST_CASE(SegmentShapeTest) {
	auto shape = std::make_shared<SegmentShape>(nullptr, Vect(0, 0), Vect(100, 0), 5);
	auto body = std::make_shared<Body>(1, 1);
	shape->setBody(body);
	Space space;
	space.add(shape);
	BOOST_CHECK(shape->pointQuery(Vect(43, 0)));
	BOOST_CHECK(shape->pointQuery(Vect(50, 4.9)));
	BOOST_CHECK(!shape->pointQuery(Vect(30, 5.1)));
	BOOST_CHECK(shape->pointQuery(Vect(0, -4.9)));
	space.remove(shape);
	shape->setBody(nullptr);
}