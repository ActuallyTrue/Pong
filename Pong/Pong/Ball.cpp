#include "Ball.h"
#include "WindowSize.h"
#include "Score.h"

Ball::Ball(PlayerPaddle* player1, PlayerPaddle* player2, Score* score1, Score* score2) {
	this->player1 = player1;
	this->player2 = player2;
	this->score1 = score1;
	this->score2 = score2;
	this->Load("ball.png");
	this->setOrigin(this->getGlobalBounds().width / 2, this->getGlobalBounds().height / 2);
	this->velocity.x = 1.0f;
	this->velocity.y = -1.0f;
}
void Ball::Update() {
	
	if (this->CheckCollision(this->player1) || this->CheckCollision(this->player2)) {
		this->velocity.x *= -1;
	}
	if (this->getPosition().y < 0 || this->getPosition().y + this->getGlobalBounds().height > windowHeight) {
		this->velocity.y *= -1;
	}

	if (this->getPosition().x < 0) {
		this->score2->IncrementScore();
		this->setPosition(windowWidth / 2, windowHeight / 2);
	}

	if (this->getPosition().x > windowWidth) {
		this->score1->IncrementScore();
		this->setPosition(windowWidth / 2, windowHeight / 2);
	}
	Entity::Update();
}