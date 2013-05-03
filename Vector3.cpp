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

double Vector3::getX() const
{
	return x;
}

double Vector3::getY() const
{
	return y;
}

double Vector3::getZ() const
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

bool Vector3::operator==(const Vector3 &other) const
{
	return (x == other.getX()) && (y == other.getY()) && (z == other.getZ());
}

bool Vector3::operator!=(const Vector3 &other) const
{
	return !(*this == other);
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

double Vector3::dotProduct(Vector3 other)
{

	return (x*other.getX())+(y*other.getY())+(z*other.getZ());
}

Vector3 Vector3::projectOnto(Vector3 other)
{

	return other * (dotProduct(other) / other.dotProduct(other));

}

double Vector3::angleBetween(Vector3 other)
{
	return acos(dotProduct(other) / (getMagnitude() * other.getMagnitude()));
}
