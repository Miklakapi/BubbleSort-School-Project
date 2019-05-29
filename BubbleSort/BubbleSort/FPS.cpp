#include "FPS.hpp"

FPS::FPS(Vector2f position, string fontFile) {
	setCharacterSize(20);
	setFPSFont(fontFile);
	setFillColor(Color::Green);
	setLetterSpacing(1);
	setStyle(Text::Bold);
	setPosition(position);
}

void FPS::setFPSFont(string fontFile) {
	font.loadFromFile(fontFile);
	setFont(font);
}

void FPS::run() {
	if (delay.getElapsedTime().asSeconds() >= 0.5) {
		delay.restart();
		setString("FPS: " + to_string(int(1 / clock.restart().asSeconds())));
	}
	else {
		clock.restart();
	}
}