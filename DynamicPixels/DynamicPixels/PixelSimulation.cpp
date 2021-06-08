#include "PixelSimulation.h"

void UpdatePixels(Pixel* pixels, const float& delta)
{
    bool flipX = false;

    for (int y = HEIGHT - 1; y >= 0; y--)
    {
        for (int x = 0; x < WIDTH; x++)
        {
            int trueX = flipX ? WIDTH - 1 - x : x;

            Pixel* pixel = &pixels[y * WIDTH + trueX];

            // logic here
        }
        flipX = !flipX;
    }
}