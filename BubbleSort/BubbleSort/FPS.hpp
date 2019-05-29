#pragma once

#include <SFML\Window.hpp>
#include <SFML\System.hpp>
#include <SFML\Graphics.hpp>

#include <string>

using namespace sf;
using namespace std;

class FPS : public Text {

	Font font;

	Clock delay;

	Clock clock;

public:

	FPS(Vector2f position = Vector2f{ 3,680 }, string fontFile = "Fonts/IndieFlower.ttf");

	void setFPSFont(string fontFile);

	void run();
};