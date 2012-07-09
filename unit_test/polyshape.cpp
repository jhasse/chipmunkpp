#define BOOST_TEST_MODULE ChipmunkppTest
#include <boost/test/unit_test.hpp>
#include <chipmunk.hpp>

using namespace cp;

BOOST_AUTO_TEST_CASE(PolyShapeTest) {
	Space space;

	std::vector<std::shared_ptr<PolyShape>> shapes;

	auto add = [&](std::vector<Vect> vects) {
		auto shape = std::make_shared<PolyShape>(space.staticBody, vects);
		space.add(shape);
		shapes.push_back(shape);
		BOOST_CHECK_EQUAL(shape->getNumVerts(), vects.size());
		for (size_t i = 0; i < vects.size(); ++i) {
			BOOST_CHECK(shape->getVert(i) == vects[i]);
		}
		BOOST_CHECK(!shape->pointQuery(Vect(253, 17)));
	};

	add({Vect(0, 40), Vect(-479, 264), Vect(480, 264)});
	add({Vect(-140, 0), Vect(-479, -320), Vect(-479, 264)});
	add({Vect(-10, -100), Vect(-479, -320), Vect(-140, 0)});
	add({Vect(-61, 37), Vect(55, 50), Vect(5, -58)});
	BOOST_CHECK(shapes.back()->pointQuery(Vect(0, 0)));
}
