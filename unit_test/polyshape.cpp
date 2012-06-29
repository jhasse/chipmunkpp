#define BOOST_TEST_MODULE PolyShapeTest
#include <boost/test/unit_test.hpp>
#include <chipmunk.hpp>

using namespace cp;

BOOST_AUTO_TEST_CASE(PolyShapeTest) {
	Space space;

	std::vector<std::shared_ptr<PolyShape>> shapes;

	auto add = [&](std::vector<Vect> vects) {
		auto shape = std::make_shared<PolyShape>(space.staticBody, vects);
		space.add(shape);
		BOOST_CHECK_EQUAL(shape->getNumVerts(), vects.size());
		for (size_t i = 0; i < vects.size(); ++i) {
			BOOST_CHECK(shape->getVert(i) == vects[i]);
		}
	};

	add({Vect(0, 40), Vect(-479, 264), Vect(480, 264)});
	add({Vect(-140, 0), Vect(-479, -320), Vect(-479, 264)});
	add({Vect(-10, -100), Vect(-479, -320), Vect(-140, 0)});
}
