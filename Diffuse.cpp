#include "Diffuse.hpp"
#include "Colour.hpp"
#include <cmath>
#include <cstdlib>

const double PI = 4.0 * atan(1.0);

Diffuse::Diffuse(Colour colour)
{
	this->colour = colour;
}

Vector3 Diffuse::bounce(Vector3 rayIn, Vector3 surfaceNormal)
{
	/*    
	      surfaceNormal = surfaceNormal.normalize();
	      double x = surfaceNormal.getX();
	      double y = surfaceNormal.getY();
	      double z = surfaceNormal.getZ();

	      double theta = asin(z) + asin(((rand() / RAND_MAX) * 2) - 1) - pi;
	      double holder = sqrt(x * x + y * y);
	      double phi = acos(x / holder) + asin(((rand() / RAND_MAX) * 2) - 1) - pi;

	      if(y < 0)
	      {
	      phi *= -1;
	      }

	      x = cos(theta) * cos(phi);
	      y = cos(theta) * sin(phi);
	      z = sin(theta);

	      return Vector3(x, y, z).normalize();
	      */
	double theta = 2*PI*((float)rand()/(float)RAND_MAX);
	double phi = acos((float)rand()/(float)RAND_MAX);

	double x = sin(theta)*sin(phi);
	double y = cos(theta)*sin(phi);
	double z = cos(phi);

	Vector3 useless = surfaceNormal + Vector3(1,0,0);
	Vector3 yDir = useless.crossProduct(surfaceNormal).normalize();
	Vector3 xDir = yDir.crossProduct(surfaceNormal).normalize();
	yDir = yDir*y;
	xDir = xDir*x;

	Vector3 zDir = surfaceNormal*z;
	return zDir + yDir + xDir;

}

Colour Diffuse::getColour(Vector3 rayIn, Vector3 surfaceNormal)
{
	return colour;
}
