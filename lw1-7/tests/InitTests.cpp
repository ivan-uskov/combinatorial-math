#include "stdafx.h"
#include "../warehouse/Initialization.h"

using namespace std;

bool operator == (Size const& lhs, Size const& rhs)
{
    return lhs.width == rhs.width && lhs.height == rhs.height;
}

BOOST_AUTO_TEST_CASE(ReadSizeTests)
{
    {
        istringstream in("134 232");
        BOOST_CHECK_NO_THROW(ReadSize(in));
    }
    {
        istringstream in("134 qdqwqwf");
        BOOST_CHECK_THROW(ReadSize(in), domain_error);
    }
}

BOOST_AUTO_TEST_CASE(CheckReadTriangles)
{
    istringstream in("2\n1 1 2 2 1 2\n4 4 5 4 6 5\n");
    BOOST_CHECK_NO_THROW(ReadTriangles(in));
}