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
	up = Vector3(0, 0, 1);
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
	up = Vector3(0, 0, 1);
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
	Vector3 lineoffocus = rotation * focalLen;
	Vector3 top = up - up.projectOnto(lineoffocus);
	Vector3 right = lineoffocus.crossProduct(top);
	right = right.normalize();
	int halfwidth = resX/2;
	int halfheight = resY/2;

	for(int i = 0; i < resX; i++)
	{
		for(int j = 0; j < resY; j++)
		{

			Vector3 resultant;

			resultant = top*(i-halfwidth) + right*(j-halfheight) + lineoffocus;
			std::cout << " X: " << resultant.getX() << " Y: " << resultant.getY() << " Z: " << resultant.getZ();

			//Ray ray = new Ray(location, targetOnImage, scene);
			//ray.fire();

		}
		std::cout << "\n";
	}
}
