#include "stdafx.h"

using namespace std;

Triangle ReadTriangle(istream & input)
{
    Point a, b, c;
    if (!(input >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y))
    {
        throw domain_error("Can't read triangle!");
    }

    return Triangle(a, b, c);
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

list<CTriangle> ReadTriangles(istream & input)
{
    list<CTriangle> triangles;
    unsigned count = ReadTrianglesCount(input);

    while (count-- > 0)
    {
        triangles.push_back(ReadTriangle(input));
    }

    return triangles;
}

WareHouseSize ReadWareHouseSize(istream & input)
{
    WareHouseSize size;
    if (!(input >> size.width >> size.height))
    {
        throw domain_error("Can't read width, height!");
    }

    return size;
}

int main(int argc, char* argv[])
{
    try
    {
        WareHouseSize size = ReadWareHouseSize(cin);
        list<CTriangle> items = ReadTriangles(cin);
    }
    catch (exception const& e)
    {
        cout << e.what() << endl;
    }

    return 0;
}