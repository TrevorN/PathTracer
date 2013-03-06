#include "Camera.hpp"
#include "Scene.hpp"
#include "Vector3.hpp"
#include <cmath>
#include <iostream>

Camera::Camera(Scene scene, Vector3 location, Vector3 focus, double focalLen, double topWidth, int resX, int resY, int longevity)
{
	this->location = location;
	this->rotation = focus - location;
	this->rotation = this->rotation.normalize();
	this->focalLen = focalLen;
	std::cout << focalLen << "\n";
	this->topWidth = topWidth;
	this->resX = resX;
	this->resY = resY;
	this->longevity = longevity;
	AA = false;
	image = new char[resX * 3 * resY];
}

Camera::Camera(Scene scene, Vector3 location, Vector3 focus, double focalLen, double topWidth, int resX, int resY, int longevity, int aaDepth)
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
	AA = true;
	image = new char[resX * 3 * resY];
}

Camera::~Camera()
{
	delete image;
}

/*
void Camera::takeSample()
{
	double pixWidth = topWidth / resX;

	for(int i = 0; i < resX; i++)
	{
	
		for(int j = 0; j < resY; j++)i
		{
			double camplaneX = pixWidth * ((i * 2) - resX);
			double camplaneZ = pixWidth * ((j * 2) - resY);
			double camplaneY = focalLen;
			//First we tilt it up/down, you know, because bits ain't shift. This is around X axis.
			double theta = std::asin(rotation.getZ() / focalLen);
			double tmpX = camplaneX;
			double tmpY = (camplaneY * std::cos(theta)) - (camplaneY * std::sin(theta));
			double tmpZ = (camplaneZ * std::sin(theta)) + (camplaneZ * std::cos(theta));
			//Now we spin around Z so that we are looking in the right direction.
			theta = std::atan(rotation.getY() / rotation.getX());
			double newX = (tmpX * std::cos(theta)) - (tmpX * std::sin(theta));
			double newY = (tmpX * std::sin(theta)) + (tmpX * std::cos(theta));
			double newZ = tmpZ;
			//Ray ray = new Ray(location, targetOnImage, scene);
			//ray.fire();
	}
}
*/

void Camera::takeSample()
{
	

	double pixWidth = topWidth / resX;
	
	Vector3 rootDir = rotation * focalLen;
	Vector3 xDir = Vector3(0,0,1).crossProduct(rootDir).normalize();
	Vector3 yDir = xDir.crossProduct(rootDir).normalize();

	for(int j = 0; j < resY; j++)
	{
		for(int i = 0; i < resX; i++)
		{
			/*
			Vector3 vec1 = rotation * focalLen;
			Vector3 vec2 = Vector3(vec1.getX() / 2.0, vec1.getY() / 2.0, (((vec1.getX() * vec1.getX()) / 2) - ((vec1.getY() * vec1.getY()) / 2)) / vec1.getZ()).normalize() * (pixWidth * ((i * 2) - resX));
			Vector3 vec3 = vec1.crossProduct(vec2).normalize() * (pixWidth * ((i * 2) - resY));
			*/
			Vector3 vec1 = xDir * ((i * 2) - (resX * pixWidth));
			Vector3 vec2 = yDir * ((j * 2) - (resY * pixWidth));
			Vector3 rayVec = rootDir + vec1 + vec2;
			std::cout << "X: " << rayVec.getX() << " Y: " << rayVec.getY() << " Z: " << rayVec.getZ() << "\t";
		}
		std::cout << "\n";
	}
}
