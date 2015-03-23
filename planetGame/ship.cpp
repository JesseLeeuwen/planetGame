#include "ship.h"

Ship::~Ship()
{
	_current_engine_power = 0;
	_max_engine_power = 0;
	_velocity = sf::Vector2f(0, 0);
	position = sf::Vector2f(0, 0);
	life_time = 0;
}

void
Ship::update()
{
	//input / change _current_engine_power
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
	{
		if (_current_engine_power < _max_engine_power)
			_current_engine_power += _max_engine_power / 60.0f;
		else
			_current_engine_power = _max_engine_power;
	}
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
	{
		if (_current_engine_power > _max_engine_power / 60.0f)
			_current_engine_power -= _max_engine_power / 60.0f;
		else
			_current_engine_power = 0.0f;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
		_shape.rotate(2.0f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
		_shape.rotate(-2.0f);

	//set velocity vector
	float angle = _shape.getRotation() / 180 * PI;
	float xspeed = cos(angle) * _current_engine_power;
	float yspeed = sin(angle) * _current_engine_power;

	//_velocity += sf::Vector2f(xspeed, yspeed) * 0.2f;
	_velocity += sf::Vector2f(
		Mathfx::Hermite(0, xspeed, 0.02f * DELTATIME),
		Mathfx::Hermite(0, yspeed, 0.02f * DELTATIME)
	);

	//changePosition
	if (Mathfx::length(_velocity) > 3.0f)
		_velocity = Mathfx::normalize(_velocity) * 3.0f;

	apply_orbit_force();
	position += _velocity;
	//set art position
	_shape.setPosition(position);
}

void 
Ship::render(sf::RenderWindow* window)
{
	window->draw(_shape);
}

void
Ship::onGUI(sf::RenderWindow* window)
{

}

//orbit system ship side
void
Ship::set_orbit_planet(Planet* planet)
{
	_orbit_planet = planet;
}

Planet*
Ship::get_orbit_planet()
{
	return _orbit_planet;
}

void 
Ship::apply_orbit_force()
{
	if (_orbit_planet == nullptr) return;

	sf::Vector2f releativePos = (_orbit_planet->position - position);
	float dist = Mathfx::length(releativePos);

	//launch system
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space) && _launch_feul > 0)
	{
		_velocity -= Mathfx::normalize(releativePos) * (1.0f / (dist - _orbit_planet->radius)) * 7.5f;

		if (_current_engine_power < _max_engine_power)
			_current_engine_power += _max_engine_power / 60.0f;
		else
			_current_engine_power = _max_engine_power;

		_launch_feul -= 0.01f * DELTATIME;
	}

	//planet Collision
	if (dist < _orbit_planet->radius + 10.0f)
	{
		_current_engine_power = 0;
		position = _orbit_planet->position - (Mathfx::normalize(releativePos) * ((float)_orbit_planet->radius + 10));
	}

	if (dist < _orbit_planet->force_radius && dist > _orbit_planet->radius + 10.0f)
	{
		_velocity += Mathfx::normalize(releativePos) * (1.0f / (dist - _orbit_planet->radius)) * 4.905f;
		_landed = false;
	}
	else if (dist < _orbit_planet->radius + 10.0f && !_landed)
	{
		_velocity = sf::Vector2f(0, 0);
		_current_engine_power = 0;
		_launch_feul = 2.0f;
		_landed = true;
	}
}
