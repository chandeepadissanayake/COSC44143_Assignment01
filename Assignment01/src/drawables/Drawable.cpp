#include "Drawable.h"

float Drawable::GetNormalizedCoordinate(float coord, int min, int max)
{
    int oldRange = max - min;
    float coordFromC = coord - (oldRange / 2);
    return (float) coordFromC / (max - min) * (1.0 - (-1.0));
}
