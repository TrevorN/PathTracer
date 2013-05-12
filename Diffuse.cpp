#include "Diffuse.hpp"
#include "Colour.hpp"
#include <cmath>
#include <cstdlib>

const double pi = 4.0 * atan(1.0);

Diffuse::Diffuse(Colour colour)
{
	this->colour = colour;
	hardness = 1;
}

Diffuse::Diffuse(Colour colour, double hardness)
{
	this->colour = colour;
	this->hardness = hardness;
}

Vector3 Diffuse::bounce(Vector3 rayIn, Vector3 surfaceNormal)
{
	double theta = 2*pi*((float)rand()/(float)RAND_MAX);
	double phi = acos(((float)rand())/(float)RAND_MAX);

	double x = sin(theta)*sin(phi);
	double y = cos(theta)*sin(phi);
	double z = cos(phi);

	Vector3 useless = surfaceNormal + Vector3(1,1,1);
	Vector3 yDir = useless.crossProduct(surfaceNormal).normalize();
	Vector3 xDir = yDir.crossProduct(surfaceNormal).normalize();
	yDir = yDir*y;
	xDir = xDir*x;

	Vector3 zDir = surfaceNormal*z;

	Vector3 final = zDir + yDir + xDir;

	if(hardness == 1){
		return final;
	} else {
		Vector3 projection = rayIn.projectOnto(surfaceNormal);
		Vector3 resultant = (rayIn) - (projection * 2);
		return (final*hardness)+(resultant*(1-hardness));
	}
}

Colour Diffuse::getColour(Vector3 rayIn, Vector3 surfaceNormal)
{
	return colour;
}
