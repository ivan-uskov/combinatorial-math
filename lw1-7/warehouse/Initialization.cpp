#include "stdafx.h"
#include "Initialization.h"

using namespace std;
using namespace Shapes;

Size ReadSize(istream & input)
{
    Size size;
    if (!(input >> size.width >> size.height))
    {
        throw domain_error("Can't read width, height!");
    }

    return size;
}

unsigned ReadTrianglesCount(istream & input)
{
    string line;
    unsigned count;
    getline(input, line);
    if (!input || !(istringstream(line) >> count))
    {
        throw domain_error("Can't read triangle count!");
    }

    return count;
}

Triangle ReadTriangle(istream & input)
{
    Point a, b, c;
    if (!(input >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y))
    {
        throw domain_error("Can't read triangle!");
    }

    return{ a, b, c };
}

vector<Triangle> ReadTriangles(istream & input)
{
    vector<Triangle> triangles;
    unsigned count = ReadTrianglesCount(input);

    while (count-- > 0)
    {
        triangles.push_back(ReadTriangle(input));
    }

    return triangles;
}

void MinimizeTriangle(Triangle const& tr, MinimizedShapes & shapes)
{

}

MinimizedShapes MinimizeTriangles(vector<Triangle> const& triangles)
{
    MinimizedShapes shapes;

    for_each(triangles.begin(), triangles.end(), [&shapes](Triangle const& tr){
        MinimizeTriangle(tr, shapes);
    });

    return shapes;
}