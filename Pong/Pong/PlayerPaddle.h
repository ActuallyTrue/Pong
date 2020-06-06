#pragma once

#include "entity.h"

class PlayerPaddle : public Entity {
public:
	PlayerPaddle(int playerNumber) {
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
	void Update() {
		switch (this->playerNumber) {
			case 0:
				this->velocity.y = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S) - sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W);
				break;
			default:
				this->velocity.y = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down) - sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up);
		}
		
		Entity::Update();
	}
private:
	int playerNumber;
};