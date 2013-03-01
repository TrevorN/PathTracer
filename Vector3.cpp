#include "Vector3.hpp"
#include <cmath>

Vector3::Vector3(double xin, double yin, double zin)
{
	x = xin;
	y = yin;
	z = zin;
}

Vector3::Vector3()
{

}

double Vector3::getMagnitude()
{
	return sqrt((x * x) + (y * y) + (z * z));
}

Vector3 Vector3::normalize()
{
	double mag = getMagnitude();
	return Vector3(x / mag, y / mag, z / mag);
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

Vector3 Vector3::operator+(Vector3 other)
{
	double newX = x + other.getX();
	double newY = y + other.getY();
	double newZ = z + other.getZ();
	return Vector3(newX, newY, newZ);
}

Vector3 Vector3::operator-(Vector3 other)
{
	double newX = x - other.getX();
	double newY = y - other.getY();
	double newZ = z - other.getZ();
	return Vector3(newX, newY, newZ);
}

Vector3 Vector3::operator*(double scalar)
{
	return Vector3(x * scalar, y * scalar, z * scalar);
}

/*
 * Takes the cross product of this vector as A
 * with the other vector (argument) as B.
 */
Vector3 Vector3::crossProduct(Vector3 other)
{
	return Vector3((y * other.getZ()) - (z * other.getY()),
		(z * other.getX()) - (x * other.getZ()),
		(x * other.getY()) - (y * other.getX()));
}
