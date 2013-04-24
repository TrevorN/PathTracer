#include "Diffuse.hpp"
#include "Colour.hpp"
#include <cmath>
#include <cstdlib>

const double pi = 4.0 * atan(1.0);

Diffuse::Diffuse(Colour colour)
{
	this->colour = colour;
	srand(time(NULL));
}

Vector3 Diffuse::bounce(Vector3 rayIn, Vector3 surfaceNormal)
{
	double x = surfaceNormal.getX();
	double y = surfaceNormal.getY();
	double z = surfaceNormal.getZ();

	double theta = asin(z) + cos(rand * 2) * pi - pi;
	double phi = acos(x / cos(theta)) + cos(rand * 2) * pi - pi;

	x = cos(theta) * cos(phi);
	y = cos(theta) * sin(phi);
	z = sin(theta);

	return Vector3(x, y, z).normalize();
}

Colour Diffuse::getColour(Vector3 rayIn, Vector3 surfaceNormal)
{

	return colour;
}
