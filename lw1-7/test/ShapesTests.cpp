#include "stdafx.h"
#include "../warehouse/Shapes.h"

using namespace Shapes;
using namespace std;

BOOST_AUTO_TEST_SUITE(ShapesTests)

BOOST_AUTO_TEST_CASE(PointTests)
{
    {
        Point point;
        BOOST_CHECK_EQUAL(point.x, 0);
        BOOST_CHECK_EQUAL(point.y, 0);
    }

    {
        Point point(1);
        BOOST_CHECK_EQUAL(point.x, 1);
        BOOST_CHECK_EQUAL(point.y, 0);
    }

    {
        Point point(3, 4);
        BOOST_CHECK_EQUAL(point.x, 3);
        BOOST_CHECK_EQUAL(point.y, 4);
    }
}

BOOST_AUTO_TEST_CASE(LineTests)
{

}

BOOST_AUTO_TEST_SUITE_END()