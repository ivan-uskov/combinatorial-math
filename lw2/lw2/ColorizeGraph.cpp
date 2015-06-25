#include "stdafx.h"
#include "ColorizeGraph.h"

using namespace std;

void PaintNotAdjacentVertices(MyGraph & graph, unsigned y, unsigned color)
{
    auto size = graph.colors.size();
    auto startPoint = y * size;

    for (unsigned x = 0; x < size; ++x)
    {
        if (graph.edges[startPoint + x] == 0 && graph.colors[x] == 0)
        {
            graph.colors[x] = color;
        }
    }
}

void PaintFourColors(MyGraph & graph)
{
    auto size = graph.colors.size();
    unsigned color = 1;

    for (unsigned y = 0; y < size; ++y)
    {
        if (graph.colors[y] == 0)
        {
            graph.colors[y] = color;
            PaintNotAdjacentVertices(graph, y, color++);
        }
    }

    if (color > 4)
    {
        throw domain_error("This graph can be colored with four colors!");
    }
}