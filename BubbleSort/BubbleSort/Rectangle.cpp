#include "Rectangle.hpp"

int Rectangle::width(6);

Rectangle::Rectangle() {
	value = 0;
	setSize(Vector2f{ float(width), float(value) });
}

void Rectangle::setWidth(int width) {
	Rectangle::width = width;
}

int Rectangle::getValue() {
	return value;
}

void Rectangle::setValue(int value) {
	this->value = value;
	setSize(Vector2f{ float(width), float(value) });
	setOrigin(Vector2f{ 0.f,float(value) });
}

void Rectangle::draw(RenderWindow& window, int place) {
	setPosition(Vector2f{ float(20 + place * 7),550 });
	window.draw(*this);
}