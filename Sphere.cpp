#include "Vector3.hpp"
#include "Sphere.hpp"
#include <iostream>
#include <cstdlib>
#include <cmath>

Sphere::Sphere(Vector3 location, Vector3 rotation, Vector3 up, double radius, Material* material)
{
	this->location = location;
	this->rotation = rotation.normalize();
	this->up = rotation.crossProduct(up).crossProduct(rotation).normalize();
	this->radius = radius;
	this->material = material;
}

int Sphere::getDistance(Ray* ray)
{
	Vector3 rayDirection = ray->getDirection();
	Vector3 rayPosition = ray->getPosition();

	Vector3 a = location - rayPosition;
	Vector3 b = a.projectOnto(rayDirection);
	Vector3 c = a-b;
	int cMag = c.getMagnitude();
	if(cMag > radius){
		return -1;
	}

	int fMag = b.getMagnitude() - sqrt((radius*radius)-(cMag * cMag));;
	return b.getMagnitude() - fMag;
}

void Sphere::collideWith(Ray* ray)
{
	double distance = getDistance(ray);
	if(distance == -1)
	{
		std::cout << "Something went horribly, horribly wrong. Goodbye world. \n";
		exit(EXIT_FAILURE);
	}

	Vector3 rayDirection = ray->getDirection();
	Vector3 rayPosition = ray->getPosition();
	Vector3 newPosition = rayPosition + (rayDirection.normalize() * distance);

	Vector3 surfaceNormal = (newPosition - location).normalize();
	Vector3 newDirection = material->bounce(rayDirection, surfaceNormal);

	ray->setPosition(newPosition);
	ray->setDirection(newDirection);

}

Colour Sphere::getColour(Ray* ray)
{

	return material->getColour(ray->getDirection(), ray->getPosition());

}
