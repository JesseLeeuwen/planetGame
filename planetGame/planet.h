#pragma once

#include "entity.h"

class Planet : public Entity
{
public:
	Planet(sf::Vector2f pos, int planet_radius) : Entity(pos, 1)
	{
		radius = planet_radius;
		force_radius = planet_radius * 3.2f;
		_shape = sf::CircleShape(planet_radius/100);
		_shape.setPointCount(planet_radius/3);
		_shape.setOrigin(sf::Vector2f(planet_radius/100, planet_radius/100));
		_shape.setPosition(pos);
		position = pos;
		life_time = std::rand() % 150;
	}
	~Planet();

	void update() override;
	void onGUI(sf::RenderWindow* window) override;
	void render(sf::RenderWindow* window) override;

	int radius;
	float force_radius;
private:
	sf::CircleShape _shape;
};

