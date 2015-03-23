#ifndef _SHIP_H_
#define _SHIP_H_

#include "planet.h"
#include "entity.h"

class Ship : public Entity
{
public:
	Ship(sf::Vector2f pos) : Entity(pos, false)
	{
		_shape = sf::RectangleShape(sf::Vector2f(30, 15));
		sf::Vector2f size = _shape.getSize();
		_shape.setOrigin(sf::Vector2f(size.x / 3.0f, size.y / 2.0f));
		_velocity = sf::Vector2f(0, 0);
		_shape.setFillColor(sf::Color::Blue);
		position = pos;
	}
	~Ship();
	
	void update() override;
	void render(sf::RenderWindow* window) override;
	void onGUI(sf::RenderWindow* window) override;
	Planet* Ship::get_orbit_planet();
	void Ship::set_orbit_planet(Planet* planet);
private:
	void Ship::apply_orbit_force();

	float _current_engine_power;
	float _max_engine_power = 0.2f;
	float _launch_feul = 0;
	bool _landed;
	Planet* _orbit_planet;
	sf::Vector2f _velocity;
	sf::RectangleShape _shape;
};



#endif