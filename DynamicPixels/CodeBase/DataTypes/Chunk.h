#pragma once
#include "Pixel.h"

struct Chunk
{
public:
	static const int CHUNK_SIZE = 64;
private:
	Pixel* _pixels = new Pixel[CHUNK_SIZE];
public:
	Pixel* GetPixelAtIndex(int x, int y) const;
private:
	int To1DIndex(int x, int y) const;
};