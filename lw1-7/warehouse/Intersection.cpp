#include "stdafx.h"
#include "Intersection.h"

using namespace Shapes;


// Its a position relatively domain quantity
enum Align
{
    Top,
    Bottom,
    Left,
    Right
};

struct OrientedSection
{
    Point p1, p2;
    Align align;
};

struct OrientedTriangle
{
    OrientedSection cathetus;
    Point orientationPoint;

    OrientedTriangle(Point const& cat1, Point const& cat2, Point const& orPoint)
    {
        cathetus.p1 = cat1;
        cathetus.p2 = cat2;
        orientationPoint = orPoint;

        if (cathetus.p2.x < cathetus.p1.x)
        {
            std::swap(cathetus.p2, cathetus.p1);
        }

        if (cat1.y < orPoint.y)
        {
            cathetus.align = Align::Bottom;
        }
        else
        {
            cathetus.align = Align::Top;
        }
    }
};

OrientedTriangle Orientate(Triangle const& triangle)
{
    if (triangle.p1.y == triangle.p2.y)
    {
        return OrientedTriangle(triangle.p1, triangle.p2, triangle.p3);
    }
    else if (triangle.p1.y == triangle.p3.y)
    {
        return OrientedTriangle(triangle.p1, triangle.p3, triangle.p2);
    }
    else if (triangle.p2.y == triangle.p3.y)
    {
        return OrientedTriangle(triangle.p2, triangle.p3, triangle.p1);
    }
    else
    {
        throw std::invalid_argument("Triangle is not rectangular isosceles!");
    }
}

double GetVerticalSectionX(OrientedSection const& sec, double y)
{
    if (sec.p1.x != sec.p2.x)
    {
        return Line(sec.p1, sec.p2).ValX(y);
    }

    return sec.p1.x;
}

bool InSideOfVerticalSection(OrientedSection const& sec, Point const& point)
{
    bool isPointYBetweenSectionY = InRange({ sec.p1.y, sec.p2.y }, point.y);
    double secX = GetVerticalSectionX(sec, point.y);
    bool isPointOnAnotherSideFromSection;

    if (sec.align == Align::Left)
    {
        isPointOnAnotherSideFromSection = secX <= point.x;
    }
    else
    {
        isPointOnAnotherSideFromSection = secX >= point.x;
    }

    return isPointYBetweenSectionY && isPointOnAnotherSideFromSection;
}

bool InSideOfSection(OrientedSection const& sec, Point const& point)
{
    switch (sec.align) //horizontal section are simplier
    {
    case Align::Bottom:
        return InRange({ sec.p1.x, sec.p2.x }, point.x) && (sec.p1.y <= point.y);
    case Align::Top:
        return InRange({ sec.p1.x, sec.p2.x }, point.x) && (sec.p1.y >= point.y);
    }

    return InSideOfVerticalSection(sec, point);
}

bool Intersects(Triangle const& triangle, Point const& point)
{
    auto tr = Orientate(triangle);

    return InSideOfSection(tr.cathetus, point) && 
        InSideOfSection({ tr.cathetus.p1, tr.orientationPoint, Align::Left }, point) &&
        InSideOfSection({ tr.cathetus.p2, tr.orientationPoint, Align::Right }, point);
}