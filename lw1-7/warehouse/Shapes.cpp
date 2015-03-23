#include "stdafx.h"
#include "Shapes.h"

using namespace std;

namespace
{
    unsigned GetLineKCoef(Shapes::Point const& p1, Shapes::Point const& p2)
    {
        if (p1.x == p2.x)
        {
            throw invalid_argument("Not a line!");
        }

        return (p1.y - p2.y) / (p1.x - p2.x);
    }

    bool InRange(pair<unsigned, unsigned> const& range, unsigned num)
    {
        return range.first <= num && num <= range.second;
    }
};

namespace Shapes
{
    Point::Point(unsigned x, unsigned y)
        : x(x)
        , y(y)
    {}

    Line::Line(Point const& p1, Point const& p2)
        : k(GetLineKCoef(p1, p2))
        , m(p1.y - k * p1.x)
    {}

    bool Line::operator <= (Point const& point)const
    {
        return (k * point.x + m) <= point.y;
    }

    bool Line::operator >= (Point const& point)const
    {
        return (k * point.x + m) >= point.y;
    }

    Section::Section(Point const& p1, Point const& p2)
        : p1(p1)
        , p2(p2)
        , Line(p1, p2)
    {}

    bool Section::operator <= (Point const& point)const
    {
        return Line::operator <= (point) && InRange({p1.x, p2.x}, point.x);
    }

    bool Section::operator >= (Point const& point)const
    {
        return Line::operator >= (point) && InRange({ p1.x, p2.x }, point.x);
    }
}