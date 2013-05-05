#include "Vector3.hpp"
#include "Cylinder.hpp"
#include <iostream>
#include <cstdlib>
#include <cmath>

Cylinder::Cylinder(Vector3 location, Vector3 rotation, Vector3 up, double radius, double height, Material* material)
{
	this->location = location;
	this->rotation = rotation.normalize();
	this->up = up - up.projectOnto(rotation);//rotation.crossProduct(up).crossProduct(rotation).normalize();
	this->radius = radius;
	this->height = height;
	this->material = material;
	this->distance = 0;
	this->face = 0;
}

double Cylinder::getDistance(Ray* ray)
{
	face = 0;
	Vector3 rayDirection = ray->getDirection();
	Vector3 rayPosition = ray->getPosition();

	Vector3 a = location - rayPosition;
	Vector3 b = rayDirection * a.getMagnitude() * (a.getMagnitude() / (a.dotProduct(rayDirection)));
	double bMag = b.getMagnitude();
	Vector3 c = b - a;
	if(b.getY()*rayDirection.getY() < 0){//checkflip
		return -1;
	}

	Vector3 artRad = c - c.projectOnto(up);
	double artRadMag = artRad.getMagnitude();

	if(artRadMag >= radius){ //borders happen with >, don't know why
		return -1;
	}
	Vector3 artB = b - b.projectOnto(up);
	double artBMag = artB.getMagnitude();

	distance = (1.0 - (sqrt((radius*radius)-(artRadMag*artRadMag)))/artBMag)*bMag;

	double relHeight = (rayDirection*distance).projectOnto(up).getMagnitude();

	if(relHeight >= height * 0.5){
		distance = -1;
	}



	//caps
	Vector3 top = location + up * height * 0.5 - rayPosition;
	Vector3 bottom = location - up * height * 0.5 - rayPosition;
	double topMag = top.getMagnitude();
	double bottomMag = bottom.getMagnitude();
	Vector3 side;

	if(bottomMag > topMag){
		face = 1;
		side = top;
	} else {
		face = -1;
		side = bottom;
	}

	Vector3 sideB = side.projectOnto(rayDirection);
	Vector3 sideC = side - sideB;
	double sideCMag = sideC.getMagnitude();
	Vector3 depth = sideC.projectOnto(up);
	double depthMag = depth.getMagnitude();


	double offset = sideCMag * depthMag / (sideC - depth).getMagnitude(); // proportions 
	sideB = sideB - sideB * offset;


	if((side - sideB).getMagnitude() < radius){
		double sideBMag = sideB.getMagnitude();
		if(sideBMag < distance || distance == -1){
			distance = sideBMag;
		} else {
			face = 0;
		}
	}

	return distance;
}

void Cylinder::collideWith(Ray* ray)
{
	//double distance = getDistance(ray);
	if(distance == -1)
	{
		std::cout << "Something went horribly, horribly wrong. Goodbye world. \n";
		exit(EXIT_FAILURE);
	}


	Vector3 rayDirection = ray->getDirection();
	Vector3 rayPosition = ray->getPosition();
	Vector3 newPosition = rayPosition + (rayDirection * distance);

	Vector3 surfaceNormal;
	if(face != 0){
		surfaceNormal = up*face;
	} else {
		Vector3 innerVec = newPosition - location;
		surfaceNormal = innerVec - innerVec.projectOnto(up);
	}
	Vector3 newDirection = material->bounce(rayDirection, surfaceNormal);

	ray->setPosition(newPosition);
	ray->setDirection(newDirection);

}

Colour Cylinder::getColour(Ray* ray)
{

	return material->getColour(ray->getDirection(), ray->getPosition());

}

Cylinder::~Cylinder()
{
	delete material;
}
