#include "Plane.hpp"

Plane::Plane(Vector3 location, Vector3 up, Material* material)
{
	this->location = location;
	this->up = up.normalize();
	this->distance = 0;
}

void Plane::getDistance(Ray* ray)
{
	Vector3 rayPosition = ray->getPosition();
	Vector3 rayDirection = ray->getDirection();
