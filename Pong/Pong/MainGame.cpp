#include "MainGame.h"
#include "MainMenu.h"
void MainGame::Initialize(sf::RenderWindow* window) {
	this->font = new sf::Font();
	this->font->loadFromFile("Graphics/Fonts/LoveBug.ttf");
	this->player1Score = new Score(*font, 45U);
	this->player2Score = new Score(*font, 45U);

	this->player2Score->setPosition(window->getSize().x - this->player2Score->getGlobalBounds().width, 0);

	this->player1 = new PlayerPaddle(0);
	this->player2 = new PlayerPaddle(1);
	this->player2->setPosition(window->getSize().x - this->player2->getGlobalBounds().width, window->getSize().y / 2);
	this->player1->setPosition(0, window->getSize().y / 2);

	this->ball = new Ball(this->player1, this->player2, this->player1Score, this->player2Score);

	this->ball->setPosition(window->getSize().x / 2, window->getSize().y / 2);

	


}

void MainGame::Update(sf::RenderWindow* window) {
	this->player1->Update();
	this->player2->Update();
	this->ball->Update();
	this->player1Score->Update();
	this->player2Score->Update();

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)) {
		coreState.SetState(new MainMenu());
	}
	
}

void MainGame::Render(sf::RenderWindow* window) {
	window->draw(*this->player1);
	window->draw(*this->player2);
	window->draw(*this->ball);
	window->draw(*this->player1Score);
	window->draw(*this->player2Score);
}

void MainGame::Destroy(sf::RenderWindow* window) {
	delete this->player1;
	delete this->player2;
	delete this->player1Score;
	delete this->player2Score;
	delete this->ball;
}