#pragma once

#include <SFML\Graphics.hpp>
#include <SFML\Window.hpp>
#include <vector>
#include <iostream>

#include "entity.h"
#include "planet.h"
#include "ship.h"
#include "camera.h"
#include "mathfx.h"

class Game
{
public:
	Game(sf::RenderWindow* window);
	~Game();

	void update();
	void onGUI();
	Planet* get_nearest_planet(sf::Vector2f position);
private:

	Ship* _player;
	Camera* _camera;
	sf::RenderWindow* _window;
	std::vector<Planet* > _planets;
};