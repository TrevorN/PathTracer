#include "Vector3.hpp"
#include "Triangle.hpp"

Triangle::Triangle(Vector3 pointA, Vector3 pointB, Vector3 pointC, Material* material)
{
	this->points[0] = pointA;
	this->points[1] = pointB;
	this->points[2] = pointC;
	this->location = (pointA + pointB + pointC) * (1.0 / 3.0);
	this->up = (pointA - location).crossProduct(pointB - location);
	this->material = material;
}

double Triangle::getDistance(Ray* ray) const
{
	Vector3 rayDirection = ray->getDirection();
	Vector3 rayPosition = ray->getPosition();

	double distance = up.dotProduct(location - rayPosition) / up.dotProduct(rayDirection);

	if(distance < .001)
	{
		return -1;
	}

	Vector3 stoPos = rayPosition + (rayDirection.normalize() * distance);

	double a = (points[1] - points[0]).crossProduct(stoPos - points[0]).dotProduct(up);
	double b = (points[2] - points[1]).crossProduct(stoPos - points[1]).dotProduct(up);
	double c = (points[0] - points[2]).crossProduct(stoPos - points[2]).dotProduct(up);

	if(a >=0 && b >= 0 && c >= 0)
	{
		return distance;
	}

	return -1;
}

void Triangle::collideWith(Ray* ray) const
{
	double distance = getDistance(ray);
	Vector3 rayPosition = ray->getPosition();
	Vector3 rayDirection = ray->getDirection();
	Vector3 newPosition = rayPosition + (rayDirection.normalize() * distance);
	Vector3 surfaceNormal;
	if(rayDirection.dotProduct(up) > 0){
		surfaceNormal = up * -1;
	} else {
		surfaceNormal = up;
	}
	Vector3 newDirection = material->bounce(rayDirection, surfaceNormal);

	ray->setPosition(newPosition);
	ray->setDirection(newDirection);
}

Colour Triangle::getColour(Ray* ray) const
{
	return material->getColour(ray->getDirection(), ray->getPosition());
}

Triangle::~Triangle()
{
	delete material;
}
