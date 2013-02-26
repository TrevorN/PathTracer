#include "Camera.hpp"
#include "Scene.hpp"
#include "Vector3.hpp"
#include <cmath>
#include <iostream>

Camera::Camera(Scene scene, Vector3 location, Vector3 focus, double focalLength, double topWidth, int resX, int resY, int longevity)
{
	this->location = location;
	this->rotation = focus - location;
	this->rotation = this->rotation.normalize();
	this->focalLen = focalLen;
	this->topWidth = topWidth;
	this->resX = resX;
	this->resY = resY;
	this->longevity = longevity;
	AA = false;
	image = new char[resX * 3 * resY];
}

Camera::Camera(Scene scene, Vector3 location, Vector3 focus, double focalLength, double topWidth, int resX, int resY, int longevity, int aaDepth)
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

void Camera::takeSample()
{
	double pixWidth = topWidth / resX;

	for(int i = 0; i < resX; i++)
	{
		double camplaneX = pixWidth * (i - (resX / 2.0));

		for(int j = 0; j < resY; j++)
		{
			double camplaneY = pixWidth * (i - (resY / 2.0));
			double newMagnitude = std::sqrt((focalLen * focalLen) + (camplaneX + camplaneX));
			double theta = std::atan(camplaneX / focalLen);
			double camHeading = std::atan(rotation.getY() / rotation.getX());
			double newX = newMagnitude * std::cos(theta + camHeading);
			double newY = newMagnitude * std::sin(theta + camHeading);
			camHeading = std::atan(rotation.getZ() / rotation.getX());
			newMagnitude = std::sqrt((focalLen * focalLen) + (camplaneY + camplaneY));
			double newZ = newMagnitude * std::sin(theta + camHeading);
			Vector3 targetOnImage = Vector3(newX, newY, newZ);
			//Ray ray = new Ray(location, targetOnImage, scene);
			//ray.fire();
			std::cout << "X: " << newX << "Y: " << newY << "Z: " << newZ;
		}
		std::cout << "\n";
	}
}
