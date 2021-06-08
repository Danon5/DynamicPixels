#include "Pixel.h"

Pixel::Pixel() 
	: velocity(0, 0), type(PixelType::Null) { }

Pixel::Pixel(sf::Vector2i position, sf::Vector2f velocity, PixelType type) 
	: position(position), velocity(velocity), type(type) { }