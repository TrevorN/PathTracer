#include <cmath>
#include <iostream>
#include "Camera.hpp"
#include "Ray.hpp"

Camera::Camera(Scene scene, Vector3 location, Vector3 focus, Vector3 up, double focalLen, double topWidth, int resX, int resY, int longevity)
{
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
	image = new char[resX * 3 * resY];
}

Camera::Camera(Scene scene, Vector3 location, Vector3 focus, Vector3 up, double focalLen, double topWidth, int resX, int resY, int longevity, int aaDepth)
{
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
	image = new char[resX * 3 * resY];
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

	for(int i = 0; i < resY; i++)
	{
		for(int j = 0; j < resX; j++)
		{
			Vector3 vec1 = xDir * (-(resX * pixWidth * .5) + ((j * pixWidth * resX)/(resX -1)));
			Vector3 vec2 = yDir * (-(resY * pixWidth * .5) + ((i * pixWidth * resY)/(resY -1)));
			Vector3 rayVec = rootDir + vec1 + vec2;
			std::cout << "X: " << rayVec.getX() << " Y: " << rayVec.getY() << " Z: " << rayVec.getZ() << "\t";
		}
		std::cout << "\n";
	}
}
