#pragma once

#include <SFML\Window.hpp>
#include <SFML\System.hpp>
#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>

#include <string>
#include <fstream>

using namespace sf;
using namespace std;

class Options : public RectangleShape {

public:

	enum Type {
		None,
		Return
	};

private:

	Texture* texture;

	RectangleShape sound[2];

	RectangleShape fps[2];

	RectangleShape counter[2];

	bool bSound;

	int iFps;

	bool bCounter;

	SoundBuffer soundB;

	Sound clickSound;

	Clock clickDelay;

public:

	Options(RenderWindow& window);

	bool getSound();

	int getFps();

	bool getCounter();

	Type run(RenderWindow& window);

	void draw(RenderWindow& window);

	~Options();
};