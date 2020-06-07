#pragma once

#include "entity.h"

class PlayerPaddle : public Entity {
public:
	PlayerPaddle(int playerNumber);
	void Update();
private:
	int playerNumber;
};