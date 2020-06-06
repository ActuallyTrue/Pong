#include "MainGame.h"
#include "MainMenu.h"
void MainGame::Initialize(sf::RenderWindow* window) {

}

void MainGame::Update(sf::RenderWindow* window) {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)) {
		coreState.SetState(new MainMenu());
	}
}

void MainGame::Render(sf::RenderWindow* window) {

}

void MainGame::Destroy(sf::RenderWindow* window) {
	
}