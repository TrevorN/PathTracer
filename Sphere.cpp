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
	this->distance = 0;
}

double Sphere::getDistance(Ray* ray)
{
	Vector3 rayDirection = ray->getDirection();
	Vector3 rayPosition = ray->getPosition();

	Vector3 a = location - rayPosition;
	Vector3 b = a.projectOnto(rayDirection);
	double bMag = b.getMagnitude();
	if(b.getY()*rayDirection.getY() < 0){//checkflip
		return -1;
	}
	double aMag = a.getMagnitude();
    //b2 + c2 = a2 so c = sqrt a2 - b2
	double cMag = sqrt((aMag * aMag) - (bMag * bMag));
	if(cMag >= radius){ //borders happen with >, don't know why
		return -1;
	}
	distance = bMag - sqrt((radius*radius)-(cMag * cMag));
	return distance;
}

void Sphere::collideWith(Ray* ray)
{
	//double distance = getDistance(ray);
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

Sphere::~Sphere()
{
    delete material;
}
