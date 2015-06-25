#include "stdafx.h"
#include "InitGraph.h"

using namespace std;

vector<bool> ReadGraphValues(istream & in, unsigned length)
{
    unsigned num;
    vector<bool> values;

    for (unsigned i = 0; (in >> num) && i < length; ++i)
    {
        values.push_back(num);
    }

    return values;
}

MyGraph ReadGraph(istream & in)
{
    unsigned length;
    if (in >> length)
    {
        unsigned fullLength = length * length;
        auto values = ReadGraphValues(in, fullLength);

        if (values.size() == fullLength)
        {
            return {values, vector<unsigned>(length, 0)};
        }
    }

    throw invalid_argument("Can't read graph!");
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