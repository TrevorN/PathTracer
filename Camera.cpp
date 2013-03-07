#include <cmath>
#include <iostream>
#include "Camera.hpp"
#include "Ray.hpp"

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
	Vector3 direction = rotation * focalLen;
	Vector3 top = up - up.projectOnto(direction);
	Vector3 right = direction.crossProduct(top).normalize();
	int halfwidth = resX/2;
	int halfheight = resY/2;

	for(int i = 0; i < resX; i++)
	{
		for(int j = 0; j < resY; j++)
		{

			Vector3 resultant = top*(i-halfwidth) + right*(j-halfheight) + direction;
			std::cout << " X: " << resultant.getX() << " Y: " << resultant.getY() << " Z: " << resultant.getZ();

			Ray ray = Ray(location, resultant, &environment, longevity);
			ray.fire();

		}
		std::cout << "\n";
	}
}
