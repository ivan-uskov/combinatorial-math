#pragma once;
#include "Matrix.h"

Matrix ReadGraph(std::istream & in);
std::ifstream InitInputStrmFromCmdArgs(int argc, char* argv[]);