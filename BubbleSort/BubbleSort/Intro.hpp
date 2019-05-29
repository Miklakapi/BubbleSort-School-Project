#pragma once

#include <SFML\Window.hpp>
#include <SFML\System.hpp>
#include <SFML\Graphics.hpp>

using namespace sf;

class Intro : public RectangleShape {

	Texture* texture;

	Clock clock;

	bool on;

	int nr;

public:

	Intro();

	bool run();

	void draw(RenderWindow& window);

	~Intro();
};