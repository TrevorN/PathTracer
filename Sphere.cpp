#include "Vector3.hpp"
#include "Sphere.hpp"
#include <iostream>
#include <cstdlib>
#include <cmath>

Sphere::Sphere(Vector3 location, double radius, Material* material)
{
	this->location = location;
	this->radius = radius;
	this->material = material;
}

double Sphere::getDistance(Ray* ray) const
{
	Vector3 rayDirection = ray->getDirection();
	Vector3 rayPosition = ray->getPosition();

	Vector3 a = location - rayPosition;
	Vector3 b = a.projectOnto(rayDirection);
	double bMag = b.getMagnitude();
	double aMag = a.getMagnitude();
	if(b.getY()*rayDirection.getY() < 0){//checkflip
		return -1;
	}
	//b2 + c2 = a2 so c = sqrt a2 - b2
	double squaRad = radius*radius;
	double csqMag = (aMag * aMag) - (bMag * bMag);
	if(csqMag > squaRad){ //borders happen with >, don't know why
		return -1;
	}

	//insidestuff
	int sign = 0;
	if(aMag < radius + .000001){
		sign = 1;
	} else {
		sign = -1;
	}

	return 	(b + rayDirection * (sign * sqrt((squaRad)-(csqMag)))).getMagnitude();
}

void Sphere::collideWith(Ray* ray) const
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

Colour Sphere::getColour(Ray* ray) const
{

	return material->getColour(ray->getDirection(), ray->getPosition());

}

Sphere::~Sphere()
{
    delete material;
}
