#pragma once

#include <SFML\System.hpp>
#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>

#include <string>

#include "Rectangle.hpp"

using namespace sf;
using namespace std;

class Play {

public:

	enum Type {
		None,
		Return
	};

	class Data{

	public:

		Data(Rectangle* rectangle, int rectangleNr, bool* stop);

		Rectangle* rectangle;

		int rectangleNr;

		bool* stop;
	};

private:

	Rectangle* rectangle;

	int rectangleNr;

	Font font;

	Text textClock;

	Clock clock;

	Clock delay;

	bool start;

	bool stop;

	bool on;

	Thread* thread;

public:

	Play(int size = 178, string fontFile = "Fonts/IndieFlower.ttf");

	Type run(RenderWindow& window);

	void draw(RenderWindow& window);

	void reset();

	static void sort(Play::Data data);

	~Play();
};