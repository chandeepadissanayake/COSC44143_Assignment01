/*
 * Definitions for Drawable.h
 */
#include "Drawable.h"

float Drawable::GetNormalizedCoordinate(float coord, int min, int max)
{
    return (float) (- 1.0f + ((1.0f - (-1.0f)) / (max - min) * (coord - min)));
}
