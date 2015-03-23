#ifndef _CAMERA_H_
#define _CAMERA_H_

#include "ship.h"

class Camera
{
public:
	Camera(Ship* ship)
	{
		_offsetX = 0;
		_offsetY = 0;
		_player = ship;
	}

	~Camera();
	sf::View update(sf::View view);
private:
	Ship* _player;
	float _offsetX;
	float _offsetY;
};
#endif