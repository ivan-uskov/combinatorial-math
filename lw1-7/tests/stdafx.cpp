#include "stdafx.h"

//=================================================
#include <./boost/test/included/unit_test.hpp>
//=================================================

bool InRange(std::pair<unsigned, unsigned> const& range, unsigned num)
{
    if (range.first < range.second)
    {
        return range.first <= num && num <= range.second;
    }
    else
    {
        return range.first >= num && num >= range.second;
    }
}