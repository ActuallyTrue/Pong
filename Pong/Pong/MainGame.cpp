#include "MainGame.h"
#include "MainMenu.h"
void MainGame::Initialize(sf::RenderWindow* window) {
	this->player1 = new PlayerPaddle(0);
	this->player2 = new PlayerPaddle(1);
	this->player2->setPosition(window->getSize().x - this->player2->getGlobalBounds().width, 0);


}

void MainGame::Update(sf::RenderWindow* window) {
	this->player1->Update();
	this->player2->Update();

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)) {
		coreState.SetState(new MainMenu());
	}
	
}

void MainGame::Render(sf::RenderWindow* window) {
	window->draw(*this->player1);
	window->draw(*this->player2);
}

void MainGame::Destroy(sf::RenderWindow* window) {
	delete this->player1;
	delete this->player2;
}