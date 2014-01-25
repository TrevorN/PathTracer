#include "Vector3.hpp"
#include <cmath>

Vector3::Vector3(double xin, double yin, double zin)
{
	comps[0] = xin;
	comps[1] = yin;
	comps[2] = zin;
}

double Vector3::getMagnitude() const
{
	return sqrt((comps[0] * comps[0]) + (comps[1] * comps[1]) + (comps[2] * comps[2]));
}

Vector3 Vector3::normalize() const
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

Vector3 Vector3::operator+(const Vector3 &other) const
{
	double newX = comps[0] + other.getX();
	double newY = comps[1] + other.getY();
	double newZ = comps[2] + other.getZ();
	return Vector3(newX, newY, newZ);
}

Vector3 Vector3::operator-(const Vector3 &other) const
{
	double newX = comps[0] - other.getX();
	double newY = comps[1] - other.getY();
	double newZ = comps[2] - other.getZ();
	return Vector3(newX, newY, newZ);
}

Vector3 Vector3::operator*(double scalar) const
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
Vector3 Vector3::crossProduct(const Vector3 &other) const
{
	return Vector3((comps[1] * other.getZ()) - (comps[2] * other.getY()),
		           (comps[2] * other.getX()) - (comps[0] * other.getZ()),
	               (comps[0] * other.getY()) - (comps[1] * other.getX()));
}

double Vector3::dotProduct(const Vector3 &other) const
{
	return (comps[0] * other.getX()) + (comps[1] * other.getY()) + (comps[2] * other.getZ());
}

Vector3 Vector3::projectOnto(const Vector3 &other) const
{
	return other * (dotProduct(other) / other.dotProduct(other));
}

double Vector3::angleBetween(const Vector3 &other) const
{
	return acos(dotProduct(other) / (getMagnitude() * other.getMagnitude()));
}
