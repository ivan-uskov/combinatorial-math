#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>

#define _USE_MATH_DEFINES
#include <math.h>

///=======================================
#define BOOST_TEST_MODULE CComplexTests
#define BOOST_TEST_INCLUDED
#pragma warning (disable:4702)
#include <./boost/test/unit_test.hpp>
///=======================================