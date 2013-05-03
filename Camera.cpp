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
	this->up = rotation.crossProduct(up).crossProduct(rotation).normalize();
	AA = false;
	image = new Colour[resX * resY];
	samplesTaken = 0;
}

Camera::Camera(Scene* scene, Vector3 location, Vector3 focus, Vector3 up, double focalLen, double topWidth, int resX, int resY, int longevity, int aaDepth)
{
    Camera(scene, location, focus, up, focalLen, topWidth, resX, resY, longevity);
    AA = true;
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

	double halfWidth = (resX*pixWidth/2.0);
	double halfHeight = (resY*pixWidth/2.0);

	for(int i = 0; i < resY; i++)
	{

	Vector3 yVec = yDir * ((i * pixWidth) - halfHeight);

		for(int j = 0; j < resX; j++)
		{
			Vector3 xVec = xDir * ((j * pixWidth) - halfWidth);
			Vector3 rayVec = rootDir + xVec + yVec;
			Ray beam = Ray(location, rayVec - location, longevity);
			//image[j+resX*i] += image[j+resX*i] * (samplesTaken / (samplesTaken + 1.0)) + (beam.fire(environment)/(samplesTaken + 1.0));
			image[j + resX*i] += beam.fire(environment);
		}
	}

	samplesTaken++;
	
}

Colour* Camera::getImage()
{
    Colour* tmpImage = new Colour[resX * resY];
    
    for(int i = 0; i < resX * resY; i++)
    {
        tmpImage[i] = image[i] / samplesTaken;
	tmpImage[i].normalize();
    }

    return tmpImage;
}
