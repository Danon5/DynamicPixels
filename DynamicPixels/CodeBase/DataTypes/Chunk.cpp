#include "Chunk.h"

Pixel* Chunk::GetPixelAtIndex(int x, int y) const
{
	return &_pixels[To1DIndex(x, y)];
}

int Chunk::To1DIndex(int x, int y) const
{
	return y * CHUNK_SIZE + x;
}