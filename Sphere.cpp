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

double Sphere::getDistance(Ray* ray)
{
	Vector3 rayDirection = ray->getDirection();
	Vector3 rayPosition = ray->getPosition();

	Vector3 a = location - rayPosition;
	Vector3 b = a.projectOnto(rayDirection);
	double aMag = a.getMagnitude();
    double bMag = b.getMagnitude();
    if(bMag <= radius){//checkflip
		return -1;
	}
    //b2 + c2 = a2 so c = sqrt a2 - b2
	double cMag = sqrt((aMag * aMag) - (bMag * bMag));
    if(cMag >= radius){ //borders happen with >, don't know why
		return -1;
	}
	return bMag - sqrt((radius*radius)-(cMag * cMag));
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
	ray->setDirection(surfaceNormal);

}

Colour Sphere::getColour(Ray* ray)
{

	return material->getColour(ray->getDirection(), ray->getPosition());

}

Sphere::~Sphere()
{
    delete material;
}
