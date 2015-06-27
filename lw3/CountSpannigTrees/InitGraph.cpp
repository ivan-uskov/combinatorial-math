#include "stdafx.h"
#include "InitGraph.h"

using namespace std;

vector<int> ReadGraphValues(istream & in, unsigned length)
{
    unsigned num;
    vector<int> values;

    for (unsigned i = 0; (in >> num) && (i < length); ++i)
    {
        values.push_back(num);
    }

    return values;
}

unsigned ReadLength(istream & in)
{
    unsigned length;
    if (!(in >> length))
    {
        throw domain_error("Can't read graph length!");
    }

    return length;
}

Matrix ReadGraph(istream & in)
{
    unsigned length = ReadLength(in);        
    unsigned count = length * length;

    auto values = ReadGraphValues(in, count);

    return Matrix(length, values);
}

ifstream InitInputStrmFromCmdArgs(int argc, char* argv[])
{
    const int argumentsCount = 2;
    if (argc < 2)
    {
        throw invalid_argument("Argument not passed: [input file name]!");
    }

    return ifstream(argv[1]);
}