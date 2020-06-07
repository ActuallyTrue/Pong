#include <SFML/Window.hpp>
#include <Windows.h>
#include "GameState.h"
#include "MainMenu.h"
#include "WindowSize.h"
#include <iostream>

GameState coreState;
bool quitGame = false;

int windowHeight;
int windowWidth;

int main()
{
	windowWidth = 800;
	windowHeight = 600;
	sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Pong");

	coreState.SetWindow(&window);
	coreState.SetState(new MainMenu());

	// run the program as long as the window is open
	while (window.isOpen())
	{
		// check all the window's events that were triggered since the last iteration of the loop
		sf::Event event;
		while (window.pollEvent(event))
		{
			// "close requested" event: we close the window
			if (event.type == sf::Event::Closed)
				window.close();
		}
	
		window.clear(sf::Color::Black);

		coreState.Update();
		coreState.Render();

		window.display();

		if (quitGame) {
			window.close();
		}

		Sleep(5);
	}

	return 0;
}