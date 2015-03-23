#pragma once

namespace Shapes
{
    struct Point
    {
        unsigned const x, y;

        Point(unsigned x = 0, unsigned y = 0);
    };

    struct Line
    {
        unsigned const k, m;

        Line(Point const& p1, Point const& p2);
        virtual ~Line(){};

        virtual bool operator <= (Point const& point)const;
        virtual bool operator >= (Point const& point)const;
    };

    struct Section : Line
    {
        Point const p1, p2;

        Section(Point const& p1, Point const& p2);
        virtual ~Section(){};

        bool operator <= (Point const& point)const override;
        bool operator >= (Point const& point)const override;
    };

    struct Triangle
    {
        Point p1, p2, p3;

        Triangle(Point const& p1, Point const& p2, Point const& p3);
    };
};
