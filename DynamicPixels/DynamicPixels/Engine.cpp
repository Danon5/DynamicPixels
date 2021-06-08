#include <iostream>
#include <SFML\Graphics.hpp>
#include "Color.h"
#include "EnumTypes.h"
#include "Pixel.h"
#include "DMath.h"

#define WIDTH 400
#define HEIGHT 300

void PopWindowEvents(sf::Window& window)
{
    sf::Event evnt;

    while (window.pollEvent(evnt))
    {
        switch (evnt.type)
        {
        case sf::Event::Closed:
            window.close();
            break;
        }
    }
}

void UpdateViewTexture(sf::Uint8* texPixels, int& texSize, Pixel* pixels)
{
    int x = 0;
    int y = 0;
	
    for (int i = 0; i < texSize; i += 4)
    {
        Pixel *pixel = &pixels[y * WIDTH + x];

        Color col = GetColorFromType(pixel->type);

        texPixels[i] = col.r;
        texPixels[i + 1] = col.g;
        texPixels[i + 2] = col.b;
        texPixels[i + 3] = col.a;

        x++;
        if (x >= WIDTH)
        {
            x = 0;
            y++;
        }
    }
}

void ResolveCollisionBetween(const sf::Vector2i& p1, const sf::Vector2i& p2, Pixel* pixels, sf::Vector2i& outputPosition)
{
    int dx = p2.x - p1.x;
    int dy = p2.y - p1.y;
    int d = 2 * dy - dx;
    int y = p1.y;

    sf::Vector2i lastAvailablePos = sf::Vector2i(p1.x, p1.y);

    for (int x = p1.x; x < p2.x; x++)
    {
        if (p1.x == x && p1.y == y)
            continue;

        int index = y * WIDTH + x;
        Pixel* pixel = &pixels[index];

        if (pixel->type != Null)
        {
            outputPosition = lastAvailablePos;
            return;
        }

        if (d > 0)
        {
            y++;
            d -= 2 * dx;
        }
        d += 2 * dy;

        lastAvailablePos = sf::Vector2i(x, y);
    }
}

bool IsPosInBounds(const int& x, const int& y)
{
    return x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT;
}

bool IsSolidPixelAt(int x, int y, Pixel* pixels)
{
    if (!IsPosInBounds(x, y))
        return true;
    Pixel* pixelAtPos = &pixels[y * WIDTH + x];
    if (pixelAtPos->type != Null)
        return true;
    return false;
}

Pixel* GetPixelAtPosition(Pixel* pixels, sf::Vector2i& position)
{
    if (position.x < 0 || position.x >= WIDTH || position.y < 0 || position.y >= HEIGHT)
        return nullptr;

    Pixel* pixel = &pixels[position.y * WIDTH + position.x];

    return pixel;
}

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "DynamicPixels");
    sf::Texture viewTex;
    viewTex.create(WIDTH, HEIGHT);
    viewTex.setSmooth(false);
    viewTex.setRepeated(false);
	
    int texSize = WIDTH * HEIGHT * 4; // * 4 for RGBA allocation (1 byte each)
    sf::Uint8* texPixels = new sf::Uint8[texSize];

    sf::Sprite viewSprite;
    viewSprite.setScale(sf::Vector2f(2, 2));

    int size = WIDTH * HEIGHT;
    Pixel* pixels = new Pixel[size];

    float delta = 0;
    sf::Clock time;

    while (window.isOpen())
    {
        PopWindowEvents(window);

        window.clear(sf::Color(0, 0, 0));

        sf::Time deltaTime = time.restart();
        delta = deltaTime.asSeconds();

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            sf::Vector2i mousePos = sf::Mouse::getPosition(window) / 2;

            for (int x = -5; x <= 5; x++)
            {
                for (int y = -5; y <= 5; y++)
                {
                    float sqrDist = pow(x, 2) + pow(y, 2);
                    if (sqrDist > 25)
                        continue;

                    sf::Vector2i pos = mousePos + sf::Vector2i(x, y);

                    Pixel* pixelAtMouse = GetPixelAtPosition(pixels, pos);

                    if (pixelAtMouse != nullptr)
                    {
                        pixelAtMouse->type = Sand;
                    }
                }
            }
        }

        UpdatePixels(pixels, delta);
        UpdateViewTexture(texPixels, texSize, pixels);
        viewTex.update(texPixels);
        viewSprite.setTexture(viewTex);

        window.draw(viewSprite);
    	
        window.display();
    }

    delete[] texPixels;
    delete[] pixels;

    return 0;
}