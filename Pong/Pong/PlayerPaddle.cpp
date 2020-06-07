#include "PlayerPaddle.h"
#include "WindowSize.h"

float paddleSpeed = 3.0f;;
PlayerPaddle::PlayerPaddle(int playerNumber) {
	this->playerNumber = playerNumber;
	switch (this->playerNumber) {
	case 0: //for player 1
		this->Load("bluePaddle.png");
		break;
	default: //anything else will be player 2
		this->Load("redPaddle.png");
		break;
	}
}
void PlayerPaddle::Update() {
	switch (this->playerNumber) {
	case 0:
		this->velocity.y = (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S) - sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) * paddleSpeed;
		break;
	default:
		this->velocity.y = (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down) - sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)) * paddleSpeed;
	}

	Entity::Update();
	if (this->getPosition().y < -20) {
		this->move(0, paddleSpeed);
	}
	if (this->getPosition().y + (this->getGlobalBounds().height - 20) > windowHeight) {
		this->move(0, -paddleSpeed);
	}
}