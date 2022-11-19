#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
class Painter
{
public:
	virtual ~Painter() {};
	virtual void draw(RenderTarget& window) = 0;
};