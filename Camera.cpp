#include "Camera.hpp"
#include "Scene.hpp"
#include "Vector3.hpp"
#include <cmath>
#include <iostream>

Camera::Camera(Scene scene, Vector3 location, Vector3 focus, Vector3 up, double focalLen, double topWidth, int resX, int resY, int longevity)
{
	this->location = location;
	this->rotation = focus - location;
	this->rotation = this->rotation.normalize();
	this->up = up;
	this->focalLen = focalLen;
	this->topWidth = topWidth;
	this->resX = resX;
	this->resY = resY;
	this->longevity = longevity;
	AA = false;
	image = new char[resX * 3 * resY];
}

Camera::Camera(Scene scene, Vector3 location, Vector3 focus, Vector3 up, double focalLen, double topWidth, int resX, int resY, int longevity, int aaDepth)
{
	this->location = location;
	this->rotation = focus - location;
	this->rotation = this->rotation.normalize();
	this->up = up;
	this->focalLen = focalLen;
	this->topWidth = topWidth;
	this->resX = resX;
	this->resY = resY;
	this->aaDepth = aaDepth;
	this->longevity = longevity;
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
	Vector3 xDir = up.crossProduct(rootDir).normalize();
	Vector3 yDir = xDir.crossProduct(rootDir).normalize();

	for(int j = 0; j < resY; j++)
	{
		for(int i = 0; i < resX; i++)
		{
			Vector3 vec1 = xDir * ((i * 2) - (resX * pixWidth));
			Vector3 vec2 = yDir * ((j * 2) - (resY * pixWidth));
			Vector3 rayVec = rootDir + vec1 + vec2;
			std::cout << "X: " << rayVec.getX() << " Y: " << rayVec.getY() << " Z: " << rayVec.getZ() << "\t";
		}
		std::cout << "\n";
	}
}
