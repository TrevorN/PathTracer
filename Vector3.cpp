#include "Vector3.hpp"
#include <cmath>

Vector3::Vector3(double xin, double yin, double zin)
{
	comps[0] = xin;
	comps[1] = yin;
	comps[2] = zin;
}

Vector3::Vector3()
{

}

double Vector3::getMagnitude()
{
	return sqrt((comps[0] * comps[0]) + (comps[1] * comps[1]) + (comps[2] * comps[2]));
}

Vector3 Vector3::normalize()
{
	double mag = getMagnitude();
	return Vector3(comps[0] / mag, comps[1] / mag, comps[2] / mag);
}

double Vector3::getX() const
{
	return comps[0];
}

double Vector3::getY() const
{
	return comps[1];
}

double Vector3::getZ() const
{
	return comps[2];
}

Vector3 Vector3::operator+(Vector3 other)
{
	double newX = comps[0] + other.getX();
	double newY = comps[1] + other.getY();
	double newZ = comps[2] + other.getZ();
	return Vector3(newX, newY, newZ);
}

Vector3 Vector3::operator-(Vector3 other)
{
	double newX = comps[0] - other.getX();
	double newY = comps[1] - other.getY();
	double newZ = comps[2] - other.getZ();
	return Vector3(newX, newY, newZ);
}

Vector3 Vector3::operator*(double scalar)
{
	return Vector3(comps[0] * scalar, comps[1] * scalar, comps[2] * scalar);
}

bool Vector3::operator==(const Vector3 &other) const
{
	return (comps[0] == other.getX()) && (comps[1] == other.getY()) && (comps[2] == other.getZ());
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
	return Vector3((comps[1] * other.getZ()) - (comps[2] * other.getY()),
		           (comps[2] * other.getX()) - (comps[0] * other.getZ()),
	               (comps[0] * other.getY()) - (comps[1] * other.getX()));
}

double Vector3::dotProduct(Vector3 other)
{
	return (comps[0] * other.getX()) + (comps[1] * other.getY()) + (comps[2] * other.getZ());
}

Vector3 Vector3::projectOnto(Vector3 other)
{
	return other * (dotProduct(other) / other.dotProduct(other));
}

double Vector3::angleBetween(Vector3 other)
{
	return acos(dotProduct(other) / (getMagnitude() * other.getMagnitude()));
}
