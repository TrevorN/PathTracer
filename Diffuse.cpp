#include "Diffuse.hpp"
#include "Colour.hpp"
#include <cmath>
#include <cstdlib>
#include <ctime>

const double pi = 4.0 * atan(1.0);

Diffuse::Diffuse(Colour colour)
{
	this->colour = colour;
}

Vector3 Diffuse::bounce(Vector3 rayIn, Vector3 surfaceNormal)
{
	double theta = 2*pi*rand();
	double phi = acos(rand());

	double x = sin(theta)*cos(phi);
	double y = cos(theta)*cos(phi);
	double z = sin(phi);

	Vector3 rayOut;
	Vector3 yDir = Vector3(0,0,1).crossProduct(surfaceNormal)*y;
	Vector3 xDir = yDir.crossProduct(surfaceNormal)*x;
	Vector3 zDir = surfaceNormal*z;
	rayOut = xDir+yDir+zDir;

	return rayOut;
}

Colour Diffuse::getColour(Vector3 rayIn, Vector3 surfaceNormal)
{

	return colour;
}
