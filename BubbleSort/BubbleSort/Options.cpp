#include "Options.hpp"

Options::Options(RenderWindow& window) {
	setSize({ 1280,720 });

	for (int i = 0; i < 2; i++) {
		sound[i].setSize({ 75,75 });
		fps[i].setSize({ 75,75 });
		counter[i].setSize({ 75,75 });
	}

	fstream stream;
	stream.open("settings.txt", ios::in);
	if (!stream.is_open()) {
		stream.open("settings.txt", ios::out);
		stream << "100";
		bSound = true;
		iFps = 60;
		bCounter = false;
		window.setFramerateLimit(60);
		stream.close();
	}
	else {
		string line;
		getline(stream, line);
		stream.close();
		for (int i = 0; i < 3; i++) {
			if (line.at(i) != '0' && line.at(i) != '1') {
				stream.open("settings.txt", ios::out);
				stream << "100";
				bSound = true;
				iFps = 60;
				bCounter = false;
				window.setFramerateLimit(60);
				stream.close();
			}
		}
		if (line.at(0) == '0') bSound = false;
		else bSound = true;
		if (line.at(1) == '0') {
			iFps = 60;
			window.setFramerateLimit(60);
		}
		else {
			iFps = 144;
			window.setFramerateLimit(144);
		}
		if (line.at(2) == '0') bCounter = false;
		else bCounter = true;
	}

	//

	texture = new Texture[5];
	(texture + 0)->loadFromFile("Img/Options.png");
	(texture + 1)->loadFromFile("Img/ON.png");
	(texture + 2)->loadFromFile("Img/OFF.png");
	(texture + 3)->loadFromFile("Img/60.png");
	(texture + 4)->loadFromFile("Img/144.png");

	//

	setTexture((texture + 0));

	sound[0].setTexture((texture + 2));
	sound[1].setTexture((texture + 1));

	fps[0].setTexture((texture + 3));
	fps[1].setTexture((texture + 4));

	counter[0].setTexture((texture + 2));
	counter[1].setTexture((texture + 1));

	//

	sound[0].setPosition({ 415,165 });
	sound[1].setPosition({ 790,165 });

	fps[0].setPosition({ 415,276 });
	fps[1].setPosition({ 790,276 });

	counter[0].setPosition({ 415,387 });
	counter[1].setPosition({ 790,387 });

	//

	IntRect rect[2]{ {0,0,75,75}, {75,0,75,75} };

	if (bSound) {
		sound[0].setTextureRect(rect[0]);
		sound[1].setTextureRect(rect[1]);
	}
	else {
		sound[1].setTextureRect(rect[0]);
		sound[0].setTextureRect(rect[1]);
	}

	if (bCounter) {
		counter[0].setTextureRect(rect[0]);
		counter[1].setTextureRect(rect[1]);
	}
	else {
		counter[1].setTextureRect(rect[0]);
		counter[0].setTextureRect(rect[1]);
	}

	if (iFps == 60) {
		fps[1].setTextureRect(rect[0]);
		fps[0].setTextureRect(rect[1]);
	}
	else {
		fps[0].setTextureRect(rect[0]);
		fps[1].setTextureRect(rect[1]);
	}

	soundB.loadFromFile("Sound/click.ogg");
	clickSound.setBuffer(soundB);
}

bool Options::getSound() {
	return bSound;
}

int Options::getFps() {
	return iFps;
}

bool Options::getCounter() {
	return bCounter;
}

Options::Type Options::run(RenderWindow& window) {

	if (Mouse::isButtonPressed(Mouse::Left) && clickDelay.getElapsedTime().asSeconds() >= 0.2) {
		clickDelay.restart();
		Vector2f pos = { float(Mouse::getPosition(window).x), float(Mouse::getPosition(window).y) };
		IntRect rect[2]{ {0,0,75,75}, {75,0,75,75} };

		if (pos.x >= 490 && pos.x <= 790) {

			if (pos.y >= 610 && pos.y <= 685) {
				fstream stream;
				stream.open("settings.txt", ios::out);

				if (bSound) stream << 1;
				else stream << 0;

				if (iFps == 60) {
					window.setFramerateLimit(60);
					stream << 0;
				}
				else {
					window.setFramerateLimit(144);
					stream << 1;
				}

				if (bCounter) stream << 1;
				else stream << 0;

				if (bSound) clickSound.play();

				return Type::Return;
			}
		}
		else if (pos.x >= 415 && pos.x <= 490) {
			if (pos.y >= 165 && pos.y <= 238) {
				bSound = false;
				sound[1].setTextureRect(rect[0]);
				sound[0].setTextureRect(rect[1]);
				if (bSound) clickSound.play();
			}
			else if (pos.y >= 276 && pos.y <= 352) {
				iFps = 60;
				fps[1].setTextureRect(rect[0]);
				fps[0].setTextureRect(rect[1]);
				if (bSound) clickSound.play();
			}
			else if (pos.y >= 387 && pos.y <= 463) {
				bCounter = false;
				counter[1].setTextureRect(rect[0]);
				counter[0].setTextureRect(rect[1]);
				if (bSound) clickSound.play();
			}
		}
		else if (pos.x >= 790 && pos.x <= 865) {
			if (pos.y >= 165 && pos.y <= 238) {
				bSound = true;
				sound[0].setTextureRect(rect[0]);
				sound[1].setTextureRect(rect[1]);
				if (bSound) clickSound.play();
			}
			else if (pos.y >= 276 && pos.y <= 352) {
				iFps = 144;
				fps[0].setTextureRect(rect[0]);
				fps[1].setTextureRect(rect[1]);
				if (bSound) clickSound.play();
			}
			else if (pos.y >= 387 && pos.y <= 463) {
				bCounter = true;
				counter[0].setTextureRect(rect[0]);
				counter[1].setTextureRect(rect[1]);
				if (bSound) clickSound.play();
			}
		}
	}

	return None;
}

void Options::draw(RenderWindow& window) {
	window.draw(*this);
	for (int i = 0; i < 2; i++) {
		window.draw(sound[i]);
		window.draw(fps[i]);
		window.draw(counter[i]);
	}
}

Options::~Options() {
	delete[] texture;
}