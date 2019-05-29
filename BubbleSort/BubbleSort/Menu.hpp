#pragma once

#include <SFML\Window.hpp>
#include <SFML\System.hpp>
#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>

using namespace sf;

class Menu : public RectangleShape {

public:

	enum Type {
		None,
		Play,
		Options,
		Exit
	};

private:

	Texture* texture;

	RectangleShape rec1;

	RectangleShape rec2;

	RectangleShape rec3;

	RectangleShape rec4;

	SoundBuffer sound;

	Sound click;

	Clock clock;

public:

	Menu();

	Type run(RenderWindow& window, bool on, bool sound);

	void draw(RenderWindow& window, bool on);

	~Menu();
};