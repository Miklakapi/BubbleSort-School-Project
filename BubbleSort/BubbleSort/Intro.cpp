#include "Intro.hpp"

Intro::Intro() {
	on = false;
	nr = 1;
	setSize({ 1280,720 });
	texture = new Texture[2];
	(texture + 0)->loadFromFile("Img/Logo1.png");
	(texture + 1)->loadFromFile("Img/Logo2.png");
	setTexture(texture);
}

bool Intro::run() {
	if (clock.getElapsedTime().asSeconds() >= 0.5 && on == false) {
		on = true;
		clock.restart();
	}
	else if (nr == 1 && on && clock.getElapsedTime().asSeconds() >= 3) {
		clock.restart();
		setTexture((texture + 1));
		nr++;
	}
	else if (nr == 2 && on && clock.getElapsedTime().asSeconds() >= 3) {
		return true;
	}
	if (Keyboard::isKeyPressed(Keyboard::Space) && on && clock.getElapsedTime().asSeconds() >= 0.2) {
		clock.restart();
		if (nr == 1) {
			setTexture((texture + 1));
			nr++;
		}
		else {
			return true;
		}
	}
	return false;
}

void Intro::draw(RenderWindow& window) {
	if (on) {
		window.draw(*this);
	}
}

Intro::~Intro() {
	delete[] texture;
}