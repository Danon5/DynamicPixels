#pragma once
#include <SFML/Graphics.hpp>

struct Color
{
    sf::Uint8 r, g, b, a;

    Color();
    Color(sf::Uint8 r, sf::Uint8 g, sf::Uint8 b, sf::Uint8 a);
};

