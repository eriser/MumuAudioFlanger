/*
  ==============================================================================

    MapFunc.cpp
    Created: 20 Oct 2015 3:45:01pm
    Author:  Jacob Penn

  ==============================================================================
*/

#include "MapFunc.h"

float mapFunc (float sourceValue, float sourceRangeMin, float sourceRangeMax, float targetRangeMin, float targetRangeMax)
{
    return targetRangeMin + ((targetRangeMax - targetRangeMin) * (sourceValue - sourceRangeMin)) / (sourceRangeMax - sourceRangeMin);
}
