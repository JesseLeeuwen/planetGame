#include "planet.h"

Planet::~Planet()
{
	radius = 0;
	force_radius = 0;
	life_time = 0;
}

void
Planet::update()
{
	life_time += DELTATIME;
	_shape.setRadius(Mathfx::Berp(0, radius, life_time / 1000));
	_shape.rotate(0.4f);		
	_shape.setOrigin(sf::Vector2f(_shape.getRadius(), _shape.getRadius()));
}

void 
Planet::render(sf::RenderWindow* window)
{
	window->draw(_shape);
}

void
Planet::onGUI(sf::RenderWindow* window)
{
	
}
