#include "entity.h"

Entity::Entity(sf::Vector2f pos, int type)
{
	position = pos;
	life_time = 0;
	typeObject = type;
}

Entity::~Entity()
{
	position = sf::Vector2f(0, 0);
	life_time = 0;
	typeObject = 0;
}