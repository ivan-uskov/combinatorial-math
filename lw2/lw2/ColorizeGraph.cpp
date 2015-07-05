#include "stdafx.h"
#include "ColorizeGraph.h"
#include "FourBasedCounter.h"

using namespace std;

bool CheckPaintedCorrectly(MyGraph const& graph, vector<unsigned> const& colors)
{
    auto size = colors.size();
    for (size_t y = 0; y < size; ++y)
    {
        for (size_t x = 0; x < size; ++x)
        {
            if (x != y graph.edges[y * size + x] == 1 && colors[x] == colors[y])
            {
                return false;
            }
        }
    }

    return true;
}

void PaintFourColors(MyGraph & graph)
{
    try
    {
        FourBasedCounter counter(graph.colors.size());
        while (!CheckPaintedCorrectly(graph, counter.View()))
        {
            counter.Inc();
        }

        graph.colors = counter.View();
    }
    catch (out_of_range const&)
    {
        throw invalid_argument("Graph can't paint in four colors!");
    }
}