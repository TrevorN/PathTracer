#include "Diffuse.hpp"
#include "Colour.hpp"
#include <cmath>
#include <cstdlib>
#include <ctime>

const double pi = 4.0 * atan(1.0);

Diffuse::Diffuse(Colour colour)
{
	this->colour = colour;
	srand(time(NULL));
}

Vector3 Diffuse::bounce(Vector3 rayIn, Vector3 surfaceNormal)
{
	double theta = 2*pi*((float)rand()/(float)RAND_MAX);
	double phi = acos((float)rand()/(float)RAND_MAX);

	double x = sin(theta)*sin(phi);
	double y = cos(theta)*sin(phi);
	double z = cos(phi);

	Vector3 rayOut = Vector3(0,0,0);
	Vector3 yDir = Vector3(0,0,1).crossProduct(surfaceNormal).normalize();
	Vector3 xDir = yDir.crossProduct(surfaceNormal).normalize();
	yDir = yDir*y;
	xDir = xDir*x;
	Vector3 zDir = surfaceNormal*z;
	rayOut = zDir + yDir + xDir;


	return rayOut;
}

Colour Diffuse::getColour(Vector3 rayIn, Vector3 surfaceNormal)
{

	return colour;
}
