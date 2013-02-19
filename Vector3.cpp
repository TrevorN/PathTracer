#include "Vector3.hpp"
#include <cmath>

double x;
double y;
double z;

Vector3::Vector3(double xin, double yin, double zin)
{
	x = xin;
	y = yin;
	z = zin;
}

double Vector3::getMagnitude()
{
	return sqrt((x * x) + (y * y) + (z * z));
}

Vector3 Vector3::normalize()
{
	double mag = getMagnitude();
	return new Vector3(x / mag, y / mag, z / mag);
}

double Vector3::getX()
{
	return x;
}

double Vector3::getY()
{
	return y;
}

double Vector3::getZ()
{
	return z;
}

/*
 * Takes the cross product of this vector as A
 * with the other vector (argument) as B.
 */
Vector3 Vector3::crossProduct(Vector3 other)
{
	return new Vector3((y * other->getZ()) - (z * other->getY()),
		(z * other->getX()) - (x * other->getZ()),
		(x * other->getY()) - (y * other->getX()));
}

Vector3 Vector3::scale(double scalar)
{
	return new Vector3(x * scalar, y * scalar, z * scalar);
}
