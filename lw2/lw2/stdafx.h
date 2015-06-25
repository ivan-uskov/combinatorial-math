#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <functional>
#include <algorithm>
#include <iterator>
#include <math.h>
#define _USE_MATH_DEFINES

bool DblsEqualy(double num1, double num2);

struct MyGraph
{
    std::vector<bool> edges;
    std::vector<unsigned> colors;
};