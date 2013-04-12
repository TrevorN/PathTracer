#include <cmath>
#include <iostream>
#include "Camera.hpp"
#include "Ray.hpp"

Camera::Camera(Scene* scene, Vector3 location, Vector3 focus, Vector3 up, double focalLen, double topWidth, int resX, int resY, int longevity)
{
	environment = scene;
	this->location = location;
	this->rotation = focus - location;
	this->rotation = this->rotation.normalize();
	this->focalLen = focalLen;
	this->topWidth = topWidth;
	this->resX = resX;
	this->resY = resY;
	this->longevity = longevity;
	this->up = up;
	AA = false;
	image = new Colour[resX * resY];
	samplesTaken = 0;
}

Camera::Camera(Scene* scene, Vector3 location, Vector3 focus, Vector3 up, double focalLen, double topWidth, int resX, int resY, int longevity, int aaDepth)
{
	environment = scene;
	this->location = location;
	this->rotation = focus - location;
	this->rotation = this->rotation.normalize();
	this->focalLen = focalLen;
	this->topWidth = topWidth;
	this->resX = resX;
	this->resY = resY;
	this->aaDepth = aaDepth;
	this->longevity = longevity;
	this->up = up;
	AA = true;
	image = new Colour[resX * resY];
	samplesTaken = 0;
}

Camera::~Camera()
{
	delete [] image;
}

void Camera::takeSample()
{
	double pixWidth = topWidth / resX;
	
	Vector3 rootDir = rotation * focalLen;
	Vector3 xDir = rootDir.crossProduct(up).normalize();
	Vector3 yDir = rootDir.crossProduct(xDir).normalize();

	int halfWidth = (resX*pixWidth/2.0);
	int halfHeight = (resY*pixWidth/2.0);

	for(int i = 0; i < resY; i++)
	{
		for(int j = 0; j < resX; j++)
		{
			Vector3 yVec = yDir * ((i * pixWidth) - halfHeight);
			Vector3 xVec = xDir * ((j * pixWidth) - halfWidth);
			Vector3 rayVec = rootDir + xVec + yVec;
	//		std::cout << "X: " << rayVec.getX() << " Y: " << rayVec.getY() << " Z: " << rayVec.getZ() << "\t";
			Ray beam = Ray(location, rayVec, longevity);
			image[j+resX*i] += image[j+resX*i] * (samplesTaken / (samplesTaken + 1.0)) + (beam.fire(environment)/(samplesTaken + 1));
		}
	//	std::cout << "\n";
	}

	samplesTaken++;
	
}

Colour* Camera::getImage()
{
	return image;
}
