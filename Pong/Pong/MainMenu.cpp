#include <iostream>
#include "MainMenu.h"
#include "MainGame.h"




void MainMenu::Initialize(sf::RenderWindow* window) {
	this->selected = 0;
	this->font = new sf::Font();
	this->font->loadFromFile("LoveBug.ttf");

	this->title = new sf::Text("Pong.", *this->font, 126U);
	this->title->setOrigin(this->title->getGlobalBounds().width / 2, this->title->getGlobalBounds().height / 2);
	this->title->setPosition(window->getSize().x / 2, window->getSize().y / 8);

	this->start = new sf::Text("Start", *this->font, 90U);
	this->start->setOrigin(this->start->getGlobalBounds().width / 2, this->start->getGlobalBounds().height / 2);
	this->start->setPosition(window->getSize().x / 4, window->getSize().y / 2);

	this->quit = new sf::Text("Quit", *this->font, 90U);
	this->quit->setOrigin(this->quit->getGlobalBounds().width / 2, this->quit->getGlobalBounds().height / 2);
	this->quit->setPosition(window->getSize().x / 2 + this->quit->getGlobalBounds().width, window->getSize().y / 2);
}

void MainMenu::Update(sf::RenderWindow* window) {
	this->rightKey = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right);
	this->leftKey = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left);
	if (leftKey) {
		this->selected--;
	}
	if (rightKey) {
		this->selected++;
	}
	if (selected < 0) {
		this->selected = 0;
	}
	if (selected > 1) {
		this->selected = 1;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Return)) {
		switch (this->selected) {
		case 0: //play the game
			coreState.SetState(new MainGame());
			break;
		case 1: //stop the game
			quitGame = true;
		}
	}
}

void MainMenu::Render(sf::RenderWindow* window) {
	this->start->setFillColor(sf::Color::White);
	this->quit->setFillColor(sf::Color::White);
	switch (this->selected) {
	case 0:
		this->start->setFillColor(sf::Color::Cyan);
		break;
	case 1:
		this->quit->setFillColor(sf::Color::Cyan);
		break;
	}
	window->draw(*this->title);
	window->draw(*this->start);
	window->draw(*this->quit);
}

void MainMenu::Destroy(sf::RenderWindow* window) {
	delete this->font;
	delete this->title;
	delete this->start;
	delete this->quit;
}
