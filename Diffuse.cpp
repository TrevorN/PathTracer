#include "Diffuse.hpp"
#include "Color.hpp"i
#include <cmath>

const double pi = 4.0 * atan(1.0);

Diffuse::Diffuse(Colour colour, double hardness)
{
	this->colour = colour;
	//lol nobody cares about hardness.
}

Vector3 Diffuse::bounce(Vector3 rayIn, Vector3 surfaceNormal)
	double x = surfaceNormal.getX();
	double y = surfaceNormal.getY();
	double z = surfaceNormal.getZ();

	double theta = asin(z);
	double phi = acos(x / cos(theta));

	theta += pi * rand() - pi / 2;
	phi += pi * rand() - pi / 2;

	x = cos(theta) * cos(phi);
	y = cos(theta) * sin(phi):
	z = sin(theta);

	return Vector3(x, y, z).normalize();
}
