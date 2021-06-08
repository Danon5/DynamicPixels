#pragma once
#include <SFML\Graphics.hpp>
#include "EnumTypes.h"

struct Pixel
{
    sf::Vector2f position;
    sf::Vector2f velocity;
    PixelType type;

    Pixel();
    Pixel(sf::Vector2i position, sf::Vector2f velocity, PixelType type);
};
