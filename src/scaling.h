#include "raylib.h"

static inline float right(float margin, float width)
{
    return GetScreenWidth() -  margin - width;
}

static inline float left(float margin)
{
    return margin;
}

static inline float center(float width)
{
    return (GetScreenWidth() - width) / 2.0f;
}

static inline float center_circ()
{
    return GetScreenWidth() / 2.0f;
}
