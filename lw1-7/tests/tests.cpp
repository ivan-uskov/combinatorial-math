#include "stdafx.h"
#include "../warehouse/Intersection.h"

using namespace Shapes;

BOOST_AUTO_TEST_SUITE(IntersectionTests)

BOOST_AUTO_TEST_CASE(CheckVertices)
{
    BOOST_CHECK(Intersects({ { 1, 1 }, { 1, 5 }, { 5, 1 } }, { 1, 1 }));
    BOOST_CHECK(Intersects({ { 1, 1 }, { 1, 5 }, { 5, 1 } }, { 5, 1 }));
    BOOST_CHECK(Intersects({ { 1, 1 }, { 1, 5 }, { 5, 1 } }, { 1, 5 }));
}

BOOST_AUTO_TEST_CASE(CheckInside)
{
    BOOST_CHECK(Intersects({ { 1, 1 }, { 1, 5 }, { 5, 1 } }, { 2, 2 }));
    BOOST_CHECK(Intersects({ { 1, 1 }, { 1, 5 }, { 5, 1 } }, { 3, 2 }));
    BOOST_CHECK(Intersects({ { 1, 1 }, { 1, 5 }, { 5, 1 } }, { 2, 3 }));
}

BOOST_AUTO_TEST_CASE(CheckBorders)
{
    BOOST_CHECK(Intersects({ { 1, 1 }, { 1, 5 }, { 5, 1 } }, { 1, 2 }));
    BOOST_CHECK(Intersects({ { 1, 1 }, { 1, 5 }, { 5, 1 } }, { 1, 3 }));
    BOOST_CHECK(Intersects({ { 1, 1 }, { 1, 5 }, { 5, 1 } }, { 1, 4 }));

    BOOST_CHECK(Intersects({ { 1, 1 }, { 1, 5 }, { 5, 1 } }, { 2, 1 }));
    BOOST_CHECK(Intersects({ { 1, 1 }, { 1, 5 }, { 5, 1 } }, { 3, 1 }));
    BOOST_CHECK(Intersects({ { 1, 1 }, { 1, 5 }, { 5, 1 } }, { 4, 1 }));

    BOOST_CHECK(Intersects({ { 1, 1 }, { 1, 5 }, { 5, 1 } }, { 2, 4 }));
    BOOST_CHECK(Intersects({ { 1, 1 }, { 1, 5 }, { 5, 1 } }, { 3, 3 }));
    BOOST_CHECK(Intersects({ { 1, 1 }, { 1, 5 }, { 5, 1 } }, { 4, 2 }));
}

BOOST_AUTO_TEST_SUITE_END()