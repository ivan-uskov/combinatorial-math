#include "stdafx.h"
#include "InitGraph.h"
#include "ColorizeGraph.h"

using namespace std;

void PrintGraphColors(MyGraph const& graph)
{
    cout << "vertice\tcolor" << endl;

    for (unsigned i = 0; i < graph.colors.size(); ++i)
    {
        cout << i << "\t" << graph.colors[i] << endl;
    }
}

int main(int argc, char* argv[])
{
    try
    {
        auto in = InitInputStrmFromCmdArgs(argc, argv);
        auto graph = ReadGraph(in);
        PaintFourColors(graph);
        PrintGraphColors(graph);
    }
    catch (exception const& e)
    {
        cout << "Err: " << e.what() << endl;
        return 1;
    }

    return 0;
}

