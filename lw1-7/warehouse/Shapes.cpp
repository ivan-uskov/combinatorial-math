#include "stdafx.h"
#include "Shapes.h"

using namespace std;

namespace Shapes
{
    namespace
    {
        double ToD(unsigned num)
        {
            return static_cast<double>(num);
        }

        double GetLineKCoef(Point const& p1, Point const& p2)
        {
            if (p1.x == p2.x)
            {
                throw invalid_argument("Not a line!");
            }

            return (ToD(p1.y) - p2.y) / (ToD(p1.x) - p2.x);
        }
    };

    Line::Line(Point const& p1, Point const& p2)
        : k(GetLineKCoef(p1, p2))
        , m(ToD(p1.y) - k * p1.x)
    {}

    double Line::ValX(double y)
    {
        return (ToD(y) - m) / k;
    }
}