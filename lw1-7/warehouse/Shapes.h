#pragma once

namespace Shapes
{
    struct Point
    {
        unsigned x, y;
    };

    struct Line
    {
        double const k, m;

        Line(Point const& p1, Point const& p2);
        double ValX(double y);
    };

    struct Triangle
    {
        Point p1, p2, p3;
    };

    struct Square
    {
        Point top, bot;
    };
};
