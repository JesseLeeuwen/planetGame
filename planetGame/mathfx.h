#ifndef _MATHFX_H_
#define _MATHFX_H_

#pragma once

#include <math.h>
#include <SFML\Graphics.hpp>
#define PI 3.14159265359
#define DELTATIME 1000/60

class Mathfx
{
public:
	Mathfx();
	~Mathfx();

	static float Hermite(float start, float end, float value);
	static float Sinerp(float start, float end, float value);
	static float Coserp(float start, float end, float value);
	static float Berp(float start, float end, float value);
	static float SmoothStep(float x, float min, float max);
	static float Lerp(float start, float end, float value);
	static float Bounce(float x);
	static float Clerp(float start, float end, float value);

	static sf::Vector2f divide(float f, sf::Vector2f v);
	static sf::Vector2f divide(sf::Vector2f v, float f);
	static sf::Vector2f divide(int i, sf::Vector2f v);
	static sf::Vector2f divide(sf::Vector2f v, int i);
	static sf::Vector2f divide(sf::Vector2f v, sf::Vector2f v2);

	static sf::Vector2f normalize(sf::Vector2f v);
	static float length(sf::Vector2f v);

private:

};
#endif