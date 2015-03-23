#include "camera.h"

Camera::~Camera()
{
}

sf::View
Camera::update(sf::View view)
{
	_offsetX = Mathfx::Lerp(_offsetX, _player->position.x, 0.002f * DELTATIME);
	_offsetY = Mathfx::Lerp(_offsetY, _player->position.y, 0.002f * DELTATIME);

	view.setCenter(_offsetX, _offsetY);
	return view;
}