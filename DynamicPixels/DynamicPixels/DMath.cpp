#include "DMath.h"

int Clamp(const int& value, const int& min, const int& max)
{
    if (value < min)
        return min;
    if (value > max - 1)
        return max - 1;
    return value;
}