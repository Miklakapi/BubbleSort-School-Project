#include "Menu.hpp"

Menu::Menu() {
	setSize({ 1280,720 });
	rec1.setSize({ 350,350 });
	rec2.setSize({ 350,350 });
	rec3.setSize({ 350,350 });
	rec4.setSize({ 350,350 });

	rec1.setOrigin({ 175,175 });
	rec2.setOrigin({ 175,175 });
	rec3.setOrigin({ 175,175 });
	rec4.setOrigin({ 175,175 });

	rec2.setPosition({ 1280,0 });
	rec3.setPosition({ 0,720 });
	rec4.setPosition({ 1280,720 });

	texture = new Texture[2];
	(texture + 0)->loadFromFile("Img/Menu.png");
	(texture + 1)->loadFromFile("Img/Gear.png");

	setTexture(texture);
	rec1.setTexture((texture + 1));
	rec2.setTexture((texture + 1));
	rec3.setTexture((texture + 1));
	rec4.setTexture((texture + 1));

	sound.loadFromFile("Sound/click.ogg");
	click.setBuffer(sound);
}

Menu::Type Menu::run(RenderWindow& window, bool on, bool sound) {
	if (clock.getElapsedTime().asSeconds() >= 0.05) {
		clock.restart();
		rec1.rotate(3);
		rec2.rotate(-3);
		rec3.rotate(-3);
		rec4.rotate(3);
	}
	if (Mouse::isButtonPressed(Mouse::Left) && on) {
		Vector2f pos = { float(Mouse::getPosition(window).x), float(Mouse::getPosition(window).y) };

		if (pos.x >= 490 && pos.x <= 790 &&
			pos.y >= 165 && pos.y <= 685) {

			if (pos.y >= 276 && pos.y <= 352) {
				if (sound) click.play();
				return Type::Play;
			}
			else if (pos.y >= 387 && pos.y <= 463) {
				if (sound) click.play();
				return Type::Options;
			}
			else if (pos.y >= 498 && pos.y <= 573) {
				if (sound) click.play();
				return Type::Exit;
			}
		}
	}
	return Type::None;
}

void Menu::draw(RenderWindow& window, bool on) {
	if (on) window.draw(*this);
	window.draw(rec1);
	window.draw(rec2);
	window.draw(rec3);
	window.draw(rec4);
}

Menu::~Menu() {
	delete[] texture;
}