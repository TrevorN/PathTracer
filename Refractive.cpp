#include <iostream>
#include "Refractive.hpp"
#include <cmath>

const double pi = 4.0 * atan(1.0);

Refractive::Refractive(Colour colour)
{
	this->colour = colour;
	refractiveIndex = 1;
}

Refractive::Refractive(Colour colour, double refractiveIndex)
{
	this->colour = colour;
	this->refractiveIndex = refractiveIndex;
}

Vector3 Refractive::bounce(Vector3 rayIn, Vector3 surfaceNormal)
{
	//	double theta = 2*pi*((float)rand()/(float)RAND_MAX);
	//	double phi = acos(((float)rand())/(float)RAND_MAX);
	//
	//	double x = sin(theta)*sin(phi);
	//	double y = cos(theta)*sin(phi);
	//	double z = cos(phi);

	double tmpRefr = refractiveIndex;
	if(surfaceNormal.dotProduct(rayIn) > 0){
		tmpRefr = 1.0/tmpRefr;
		surfaceNormal = surfaceNormal*-1;
	}
	if(refractiveIndex == 1){
		return rayIn;
	} else {
		double rayInMag = rayIn.getMagnitude();
		double surfaceNormalMag = surfaceNormal.getMagnitude();
		double cos = -1*rayIn.dotProduct(surfaceNormal)/(rayInMag*surfaceNormalMag);
		double sin = sqrt(1 - cos * cos);
		double newSin = sin/tmpRefr;
		double newCos = sqrt(1 - newSin * newSin);
		//sino/sinn = refractiveIndex/1
		//sinn = sino/refractiveIndex

		Vector3 y = rayIn.projectOnto(surfaceNormal);
		Vector3 x = rayIn - y;

			
		y = y * (newCos / cos);
		x = x * (newSin / sin);

		return x+y;
	}
}

Colour Refractive::getColour(Vector3 rayIn, Vector3 surfaceNormal)
{
	return colour;
}
