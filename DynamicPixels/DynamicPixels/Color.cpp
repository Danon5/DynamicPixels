#include "Color.h"

Color::Color() : r(0), g(0), b(0), a(0) { }
Color::Color(sf::Uint8 r, sf::Uint8 g, sf::Uint8 b, sf::Uint8 a) : r(r), g(g), b(b), a(a) { };

Color GetColorFromType(PixelType& type)
{
    switch (type)
    {
    case PixelType::Sand:
        return Color(255, 255, 100, 255);
    default:
        return Color(0, 0, 0, 0);
    }
}