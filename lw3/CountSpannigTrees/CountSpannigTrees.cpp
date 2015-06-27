#include "stdafx.h"
#include "InitGraph.h"

using namespace std;


int main(int argc, char* argv[])
{
    try
    {
        auto in = InitInputStrmFromCmdArgs(argc, argv);
        auto graph = ReadGraph(in);

        cout << "Count spanning trees: " << graph.GetCountSpanningTrees() << endl;
    }
    catch (exception const& e)
    {
        cout << e.what() << endl;
    }

    return 0;
}

