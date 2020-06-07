#pragma once

#include "GameState.h"
#include "Entity.h"
#include "PlayerPaddle.h"
#include "Ball.h"
#include "Score.h"

class MainGame : public TinyState {
public:
	void Initialize(sf::RenderWindow* window);
	void Update(sf::RenderWindow* window);
	void Render(sf::RenderWindow* window);
	void Destroy(sf::RenderWindow* window);

private:
	PlayerPaddle* player1;
	PlayerPaddle* player2;
	Ball* ball;
	Score* player1Score;
	Score* player2Score;
	sf::Font* font;
};
