#include "Game.hpp"

Game::Game(RenderWindow& window) {
	type = Type::InIntro;
	intro = new Intro;

	fstream stream;
	stream.open("settings.txt", ios::in);
	if (!stream.is_open()) {
		stream.open("settings.txt", ios::out);
		stream << "100";
		sound = true;
		fpsCounter = false;
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
				sound = true;
				fpsCounter = false;
				window.setFramerateLimit(60);
				stream.close();
			}
		}
		if (line.at(0) == '0') sound = false;
		else sound = true;
		if (line.at(1) == '0') {
			window.setFramerateLimit(60);
		}
		else {
			window.setFramerateLimit(144);
		}
		if (line.at(2) == '0') fpsCounter = false;
		else fpsCounter = true;
	}
	if (fpsCounter) FpsCounter = new FPS;
	clickDelay.restart();
}

void Game::run(RenderWindow& window) {
	/////////
	/////////
	if (type == Type::InIntro) {
		if (intro->run()) {
			type = Type::InMenu;
			delete intro;
			menu = new Menu;
		}
	}
	/////////
	/////////
	else if (type == Type::InMenu) {
		Menu::Type type1 = menu->run(window, true, sound);
		if (type1 == Menu::None);
		else if (type1 == Menu::Play && clickDelay.getElapsedTime().asSeconds() > 0.2) {
			delete menu;
			play = new Play;
			type = Type::InGame;
		}
		else if (type1 == Menu::Options  && clickDelay.getElapsedTime().asSeconds() > 0.2) {
			options = new Options(window);
			type = Type::InOptions;
		}
		else if (type1 == Menu::Exit && clickDelay.getElapsedTime().asSeconds() > 0.2) exit(0);
	}
	/////////
	/////////
	else if (type == Type::InGame) {
		if (play->run(window) == Play::Return) {
			type = Type::InMenu;
			delete play;
			menu = new Menu;
		}
	}
	/////////
	/////////
	else if (type == Type::InOptions) {
		menu->run(window, false, sound);
		if (options->run(window) == Options::Return) {
			type = Type::InMenu;
			this->sound = options->getSound();
			if (options->getCounter() && fpsCounter == false) {
				FpsCounter = new FPS;
				fpsCounter = true;
			}
			else if (!options->getCounter() && fpsCounter) {
				delete FpsCounter;
				fpsCounter = false;
			}
			delete options;
			clickDelay.restart();
		}
	}

	if (fpsCounter) FpsCounter->run();
}

void Game::draw(RenderWindow& window) {
	switch (type) {
	case Type::InIntro:
		intro->draw(window);
		break;
	case Type::InMenu:
		menu->draw(window, true);
		break;
	case Type::InGame:
		play->draw(window);
		break;
	case Type::InOptions:
		options->draw(window);
		menu->draw(window, false);
		break;
	}
	if (fpsCounter) window.draw(*FpsCounter);
}

Game::~Game() {
	switch (type) {
	case Type::InIntro:
		delete intro;
		break;
	case Type::InMenu:
		delete menu;
		break;
	case Type::InGame:
		delete play;
		break;
	case Type::InOptions:
		delete menu;
		delete options;
		break;
	}
	if (fpsCounter) delete FpsCounter;
}