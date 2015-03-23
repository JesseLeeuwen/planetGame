//#include <SFML\System.hpp>
#include "game.h"

int main(int argc, char** argv)
{
	bool running = true;
	bool focus = true;
	int VIEW_WIDTH = 1024;
	int VIEW_HEIGHT = 1024 / 16 * 9;
	float ASPECT_RATIO = (float)VIEW_WIDTH / VIEW_HEIGHT;

	sf::RenderWindow window(sf::VideoMode(VIEW_WIDTH, VIEW_HEIGHT), "planet game");
	window.setVerticalSyncEnabled(true);
	window.setPosition(sf::Vector2i(100, 100));

	Game game(&window);
	sf::View view;
	sf::Event event;

	sf::Vector2u old_window_size = window.getSize();

	// main loop
	while (running)
	{
		window.pollEvent(event);
		if (event.type == sf::Event::Resized)
		{
			// TODO: code to protect aspect				
			float aspect_ratio = (float)window.getSize().x / (float)window.getSize().y;
			std::cout << window.getSize().y << std::endl;
			if (aspect_ratio != ASPECT_RATIO)
			{
				if (old_window_size.x != window.getSize().x)
				{
					window.setSize(sf::Vector2u(
						window.getSize().x,
						window.getSize().x / 16 * 9
						));
				}
				else if (old_window_size.y != window.getSize().y)
				{
					window.setSize(sf::Vector2u(
						window.getSize().y / 9 * 16,
						window.getSize().y
					));
				}
					
			}
			old_window_size = window.getSize();
			window.pollEvent(event);
		}

		if (event.type == sf::Event::LostFocus)
			focus = false;
		if (event.type == sf::Event::GainedFocus)
			focus = true;

		if (event.type == sf::Event::Closed)
		{
			window.close();
			running = false; 
		}

		if (focus)
		{
			window.clear();
			    
			game.update();
			game.onGUI();
		}
		window.display();
	}

	return 1;
}