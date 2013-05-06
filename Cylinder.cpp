#include "Vector3.hpp"
#include "Cylinder.hpp"
#include <iostream>
#include <cstdlib>
#include <cmath>

Cylinder::Cylinder(Vector3 location, Vector3 rotation, Vector3 up, double radius, double height, Material* material)
{
	this->location = location;
	this->rotation = rotation.normalize();
	this->up = (up - up.projectOnto(rotation)).normalize();//rotation.crossProduct(up).crossProduct(rotation).normalize();
	this->radius = radius;
	this->height = height;
	this->material = material;
	this->distance = 0;
	this->face = 0;
}

double Cylinder::getDistance(Ray* ray)
{
	distance = -1;
	face = 0;
	Vector3 rayDirection = ray->getDirection();
	Vector3 rayPosition = ray->getPosition();
	Vector3 a = location - rayPosition;

	Vector3 b = rayDirection * a.getMagnitude() * (a.getMagnitude() * rayDirection.getMagnitude() / (a.dotProduct(rayDirection)));
	double bMag = b.getMagnitude();
	Vector3 c = b - a;
	if(b.getX()*rayDirection.getX() < 0 || b.getY()*rayDirection.getY() < 0 || b.getZ()*rayDirection.getZ() < 0){//checkflip
		return -1;
	}

	Vector3 artRad = c - c.projectOnto(up);
	double artRadMag = artRad.getMagnitude();

	Vector3 artB = b - b.projectOnto(up);
	double artBMag = artB.getMagnitude();

	// r^2 = |artRad|^2+|artB'|^2-2*|artB'|*artRad*artB/|artB| : law of cosines
	// 0 = |artB'|^2 - 2 * artRad * artB/|artB| * |artB'| - r^2 + artRad^2
	double quadB = -2 * artRad.dotProduct(artB)/artBMag;
	double quadC = artRadMag*artRadMag - radius*radius;
	double off = ((-quadB + sqrt(quadB * quadB - 4 * quadC))/2.0);
	distance = (1.0 - off/artBMag) * bMag;

//	distance = (1.0 - (sqrt((radius*radius)-(artRadMag*artRadMag)))/artBMag)*bMag;

	double relHeight = ((rayDirection*distance)-a).projectOnto(up).getMagnitude();

	if(artRadMag >= radius){ //borders happen with >, don't know why
		distance = -1;
	}

	if(relHeight >= height * 0.5){
		distance = -1;
	}


	//caps
	
	Vector3 top = a + up * height * 0.5;
	Vector3 bottom = a - up * height * 0.5;
	double topMag = top.getMagnitude();
	double bottomMag = bottom.getMagnitude();
	Vector3 side;

	int tmpFace;
	if(bottomMag > topMag){
		tmpFace = 1;
		side = top;
	} else {
		tmpFace = -1;
		side = bottom;
	}

	/*
	Vector3 sideB = side.projectOnto(rayDirection);
	Vector3 sideC = side - sideB;
	double sideCMag = sideC.getMagnitude();
	Vector3 depth = sideC.projectOnto(up);
	double depthMag = depth.getMagnitude();


	double offset = sideCMag * depthMag / (sideC - depth).getMagnitude(); // proportions 
	int sign = -1; //flips through solid
	if(up.getX()*depth.getX() < 0 || up.getY() * depth.getY() < 0){
		sign = 1;
	}
	double sideBMag = sideB.getMagnitude() + sign * offset;
	sideB = sideB.normalize() * sideBMag;
	*/
	//(p - side - rayPosition) * up = 0
	//(d*rayDirection + rayPosition - side - rayPosition) * up = 0
	//d * (rayDirection * up) + (-side) * up = 0
	//d = (side) * up /(rayDirection * up)
	double dPl = side.dotProduct(up)/rayDirection.dotProduct(up);


	if(((rayDirection * dPl) - side).getMagnitude() < radius){
		if(dPl < distance || distance == -1){
			distance = dPl;
			face = tmpFace;
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
	Vector3 newPosition = rayPosition + (rayDirection.normalize() * distance);

	Vector3 surfaceNormal;
	if(face != 0){
		surfaceNormal = up*face;
	} else {
		Vector3 innerVec = newPosition - location;
		surfaceNormal = innerVec - innerVec.projectOnto(up);
	}
	Vector3 newDirection = material->bounce(rayDirection, surfaceNormal.normalize());

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
