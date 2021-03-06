#pragma once
#include "GameState.h"

class MainMenu : public TinyState {
public:
	void Initialize(sf::RenderWindow* window);
	void Update(sf::RenderWindow* window);
	void Render(sf::RenderWindow* window);
	void Destroy(sf::RenderWindow* window);
	
private:
	sf::Font* font;
	sf::Text* title;
	sf::Text* start;
	sf::Text* quit;

	int selected;
	bool leftKey, rightKey;
};
