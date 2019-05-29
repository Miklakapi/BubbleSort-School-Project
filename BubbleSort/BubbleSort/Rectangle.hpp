#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

using namespace sf;

class Rectangle : public RectangleShape {

	int value;

	static int width;

public:

	Rectangle();

	static void setWidth(int width);

	int getValue();

	void setValue(int value);

	void draw(RenderWindow& window, int place);

};