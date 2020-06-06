#include <iostream>
#include "MainMenu.h"




void MainMenu::Initialize(sf::RenderWindow* window) {
	this->font = new sf::Font();
	this->font->loadFromFile("LoveBug.ttf");

	this->title = new sf::Text("Pong.", *this->font, 126U);
	std::cout << "initialized!\n";
}

void MainMenu::Update(sf::RenderWindow* window) {

}

void MainMenu::Render(sf::RenderWindow* window) {
	window->draw(*this->title);
}

void MainMenu::Destroy(sf::RenderWindow* window) {
	delete this->font;
	delete this->title;
	std::cout << "Destroyed!\n";
}
