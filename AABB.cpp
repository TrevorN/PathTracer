#include <stdlib>
#include "AABB.hpp"

AABB::AABB(Vector3 lowBound, Vector3 highBound, Material* material)
{
	double xLow, xHigh, yLow, yHigh, zLow, zHigh;
	if(lowBound.getX() < highBound.getX())
	{
		xLow = lowBound.getX();
		xHigh = highBound.getX();
	} else {
		xLow = highBound.getX();
		xHigh = lowBound.getX();
	}

	if(lowBound.getY() < highBound.getY())
	{
		yLow = lowBound.getY();
		yHigh = highBound.getY();
	} else {
		yLow = highBound.getY();
		yHigh = lowBound.getY();
	}

	if(lowBound.getZ() < highBound.getZ())
	{
		zLow = lowBound.getZ();
		zHigh = highBound.getZ();
	} else {
		zLow = highBound.getZ();
		zHigh = lowBound.getZ();
	}
}
~AABB();
double getDistance(Ray*) const;
void collideWith(Ray*) const;
Colour getColour(Ray*) const;