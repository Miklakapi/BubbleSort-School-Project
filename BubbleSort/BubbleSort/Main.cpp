#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

#include <conio.h>

#include "Rectangle.hpp"
#include "Game.hpp"

using namespace sf;

int main() {

	srand(time(NULL));

	RenderWindow app{ VideoMode{1280, 720, 32}, "Bubble Sort",Style::Close };
	app.setFramerateLimit(144);

	Game game(app);

	while (app.isOpen()) {

		Event ev;

		while (app.pollEvent(ev)) {

			switch (ev.type) {
			case Event::Closed:
				app.close();
				break;
			}

		}

		game.run(app);

		app.clear(Color::Black);
		game.draw(app);
		app.display();
	}
}