#pragma once

#include <SFML\Graphics.hpp>
#include "mathfx.h"

class Entity
{
public:
	Entity(sf::Vector2f pos, int isPlanet);
	~Entity();

	virtual void update() = 0;
	virtual void render(sf::RenderWindow* window) = 0;
	virtual void onGUI(sf::RenderWindow* window) = 0;

	int typeObject;
	sf::Vector2f position;
	float life_time;
private:	
};