#include "game.h"

Game::Game(sf::RenderWindow* window)
{
	_window = window;
	std::cout << "game create" << std::endl;
	_planets.clear();
	_planets.push_back(new Planet(sf::Vector2f(-254, 562), 75));
	_planets.push_back(new Planet(sf::Vector2f(400, -256), 90));
	_planets.push_back(new Planet(sf::Vector2f(-358, 135), 199));
	_planets.push_back(new Planet(sf::Vector2f(126, 365), 68));

	//player creation / camera creation
	_player = new Ship(sf::Vector2f(-50, -10));
	_camera = new Camera(_player);
}

Game::~Game()
{
}

void
Game::update()
{
	for each (Entity* obj in _planets)
	{
		obj->update();
		obj->render(_window);
	}

	_player->set_orbit_planet(get_nearest_planet(_player->position));
	_player->update();
	_player->render(_window);
	_window->setView(_camera->update(_window->getView()));
}

void
Game::onGUI()
{
	for each (Entity* obj in _planets)
	{
		obj->onGUI(_window);
	}
	_player->onGUI(_window);
}

// TODO: return planet based on radius and distance
Planet*
Game::get_nearest_planet(sf::Vector2f position)
{
	Planet* entity = _player->get_orbit_planet();

	for each (Planet* planet in _planets)
	{
		if (entity != nullptr)
		{
			if (planet->position == entity->position) continue;

			float distOld = Mathfx::length(entity->position - position) - entity->radius;
			float distNew = Mathfx::length(planet->position - position) - planet->radius;

			if(distOld > distNew)
				entity = planet;
		}
		else
			entity = planet;
	}
	return entity;
}