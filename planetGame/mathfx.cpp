#include "mathfx.h"

Mathfx::Mathfx()
{
}

Mathfx::~Mathfx()
{
}

float
Mathfx::Lerp(float start, float end, float value)
{
	return ((1.0f - value) * start) + (value * end);
}

float
Mathfx::Hermite(float start, float end, float value)
{
	return Lerp(start, end, value * value * (3.0f - 2.0f * value));
}

float
Mathfx::Sinerp(float start, float end, float value)
{
	return Lerp(start, end, sin(value * PI * 0.5f));
}

float
Mathfx::Coserp(float start, float end, float value)
{
	return Lerp(start, end, 1.0f - cos(value * PI * 0.5f));
}

float
Mathfx::Berp(float start, float end, float value)
{
	value = fmaxf(fminf(value, 1), -1);
	value = (sin(value * PI * (0.2f + 2.5f * value * value * value)) * powf(1.0f - value, 2.2f) + value) * (1.0f + (1.2f * (1.0f - value)));
	return start + (end - start) * value;
}

float
Mathfx::SmoothStep(float x, float min, float max)
{
	x = fmaxf(fminf(x, max), min);
	float v1 = (x - min) / (max - min);
	float v2 = (x - min) / (max - min);
	return -2 * v1 * v1 *v1 + 3 * v2 * v2;
}

float
Mathfx::Bounce(float x) {
	return abs(sin(6.28f*(x + 1.0f)*(x + 1.0f)) * (1.0f - x));
}

/*
* CLerp - Circular Lerp - is like lerp but handles the wraparound from 0 to 360.
* This is useful when interpolating eulerAngles and the object
* crosses the 0/360 boundary.  The standard Lerp function causes the object
* to rotate in the wrong direction and looks stupid. Clerp fixes that.
*/

float
Mathfx::Clerp(float start, float end, float value){
	float min = 0.0f;
	float max = 360.0f;
	float half = abs((max - min) / 2.0f);//half the distance between min and max
	float retval = 0.0f;
	float diff = 0.0f;

	if ((end - start) < -half){
		diff = ((max - start) + end)*value;
		retval = start + diff;
	}
	else if ((end - start) > half){
		diff = -((max - end) + start)*value;
		retval = start + diff;
	}
	else retval = start + (end - start)*value;

	return retval;
}

//divide
sf::Vector2f 
Mathfx::divide(float f, sf::Vector2f v)
{
	return sf::Vector2f(f / v.x, f / v.y);
}

sf::Vector2f 
Mathfx::divide(sf::Vector2f v, float f)
{
	return sf::Vector2f(v.x / f, v.y / f);
}

sf::Vector2f 
Mathfx::divide(int i, sf::Vector2f v)
{
	return sf::Vector2f(i / v.x, i / v.y);
}

sf::Vector2f 
Mathfx::divide(sf::Vector2f v, int i)
{
	return sf::Vector2f(v.x / i, v.y / i);
}

sf::Vector2f 
Mathfx::divide(sf::Vector2f v, sf::Vector2f v2)
{
	return sf::Vector2f(v.x / v2.x, v.y / v2.y);
}

sf::Vector2f
Mathfx::normalize(sf::Vector2f v)
{
	return v / length(v);
}

float
Mathfx::length(sf::Vector2f v)
{
	float mag = std::sqrt((v.x * v.x) + (v.y * v.y));
	return mag;
}
