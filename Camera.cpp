#include "Camera.hpp"
#include "Ray.hpp"
#include <iostream>
#include <cmath>
#include <thread>

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
	image = new Colour[resX * resY];
	samplesTaken.store(0);
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
            imageMutex.lock();
            image[j + resX*i] += beam.fire(environment);
            imageMutex.unlock();
        }
	}
	samplesTaken++;
    std::cout << samplesTaken.load() << std::endl;
}

void Camera::takeSamples(std::atomic<int> &sampleCounter)
{
    while(true)
    {
        if(sampleCounter <= 0)
            break;
        sampleCounter--;
        takeSample(); 
    }
}

void Camera::capture(int numThreads, int numSamples)
{
   std::atomic<int> count;
   count.store(numSamples);
   std::thread* threads = new std::thread[numThreads];
   for(int i = 0; i < numThreads; i++)
   {
       threads[i] = std::thread(&Camera::takeSamples, this, std::ref(count));
   }
   for(int i = 0; i < numThreads; i++)
   {
       threads[i].join();
   }
   delete [] threads;
}

Colour* Camera::getImage()
{
    Colour* tmpImage = new Colour[resX * resY];
    
    for(int i = 0; i < resX * resY; i++)
    {
        tmpImage[i] = image[i] / samplesTaken.load();
	    tmpImage[i].normalize();
    }

    return tmpImage;
}
