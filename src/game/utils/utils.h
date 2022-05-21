#pragma once



#include <cmath>
#include <limits>



static bool CompareDouble(double a, double b) {
    return std::fabs(a - b) < std::numeric_limits<double>::epsilon();
}
