#pragma once

#include "PlayerPaddle.h"
#include "score.h"

class Ball : public Entity {
public:
	Ball(PlayerPaddle* player1, PlayerPaddle* player2, Score* score1, Score* score2);
	void Update();
private:
	Score* score1;
	Score* score2;
	PlayerPaddle* player1;
	PlayerPaddle* player2;
};