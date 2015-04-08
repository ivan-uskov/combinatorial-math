#pragma once
#include "Shapes.h"

struct Size
{
    unsigned width;
    unsigned height;
};

struct MinimizedShapes
{
    std::vector<Shapes::Triangle> triangles;
    std::vector<Shapes::Square> squares;
};

Size ReadSize(std::istream & input);
std::vector<Shapes::Triangle> ReadTriangles(std::istream & input);

MinimizedShapes MinimizeTriangles(std::vector<Shapes::Triangle> const& triangles);