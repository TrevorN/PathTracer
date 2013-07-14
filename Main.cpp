#include "Camera.hpp"
#include "Scene.hpp"
#include "Vector3.hpp"
#include "PngFactory.hpp"
#include "Sphere.hpp"
#include "Cylinder.hpp"
#include "Mirror.hpp"
#include "Diffuse.hpp"
#include "Emissive.hpp"
#include "Refractive.hpp"
#include "Plane.hpp"
#include "Triangle.hpp"
#include <iostream>
#include <string>
#include <cmath>
#include <thread>

using namespace std;

void renderThread(Camera *cam, int numSamples)
{
	for(int i = 0; i < numSamples; i++)
	{
		std::cout << "taking sample";
		cam->takeSample();
	}
}

int main()
{
	int numThreads = 4;

	int resX = 1024;
	int resY = 1024;

	int numSamples = 5;

	double focalLen = 2;
	double topWidth = 33;
	Scene* theScene = new Scene(Colour(150, 150, 150));

	Vector3 pointA = Vector3(0, 0, 6);
	Vector3 pointB = Vector3(-6, 0, -2.5);
	Vector3 pointC = Vector3(0, 6, -2.5);
	Vector3 pointD = Vector3(0, 0, -2.5);

	Sphere* refr[5];
	refr[0] = new Sphere(Vector3(20, 20, 2), Vector3(0, 1, 0), Vector3(0, 0, 1), 1, new Refractive(Colour(5, 10, 15), 1.5));
	refr[1] = new Sphere(Vector3(20, 24, 6), Vector3(0, 1, 0), Vector3(0, 0, 1), 1, new Refractive(Colour(5, 10, 15), 1.25));
	refr[2] = new Sphere(Vector3(20, 28, 10), Vector3(0, 1, 0), Vector3(0, 0, 1), 1, new Refractive(Colour(5, 10, 15), 1.125));
	refr[3] = new Sphere(Vector3(24, 20, 6), Vector3(0, 1, 0), Vector3(0, 0, 1), 1, new Refractive(Colour(5, 10, 15), 2.5));
	refr[4] = new Sphere(Vector3(28, 20, 10), Vector3(0, 1, 0), Vector3(0, 0, 1), 1, new Refractive(Colour(5, 10, 15), 3.5));
	for(int i = 0; i<5; i++){
		theScene->addForm(refr[i]);
	}
//	Sphere* sur = new Sphere(Vector3(0, 0, 0), Vector3(0, 1, 0), Vector3(0, 0, 1), 60, new Diffuse(Colour(50, 5, 7), 0.9));
	Sphere* spheres[36];
	for(int i = 0; i < 6; i++){
		for(int j = 0; j < 6; j++){
			spheres[i+j*4] = new Sphere(Vector3(j*4-8, i*4-8, -3), Vector3(0, 1, 0), Vector3(0, 0, 1), 1, new Diffuse(Colour(30, 25, 20), 0.05));
			theScene->addForm(spheres[i+j*4]);
		}
	}

	Sphere* sphere = new Sphere(Vector3(4, 4, 0), Vector3(0, 1, 0), Vector3(0, 0, 1), 2, new Diffuse(Colour(25, 50, 70), 0.8));
	Sphere* light = new Sphere(Vector3(-8, 16, 0), Vector3(0, 1, 0), Vector3(0, 0, 1), 4, new Emissive(Colour(-50, -250, -140)));
	Sphere* ligh = new Sphere(Vector3(16, -8, 0), Vector3(0, 1, 0), Vector3(0, 0, 1), 4, new Emissive(Colour(-50, -140, -250)));
	Sphere* lig = new Sphere(Vector3(-8, -8, 0), Vector3(0, 1, 0), Vector3(0, 0, 1), 4, new Emissive(Colour(-250, -140, -50)));
	Plane* plan = new Plane(Vector3(0, 0, -4), Vector3(0, 0, 1), new Diffuse(Colour(75, 20, 10)));
	Triangle* refa = new Triangle(pointA, pointB, pointC, new Diffuse(Colour(5, 20, 15), 0.8));
	Triangle* refb = new Triangle(pointA, pointB, pointD, new Diffuse(Colour(5, 30, 15), 0.8));
	Triangle* refc = new Triangle(pointD, pointB, pointC, new Diffuse(Colour(5, 40, 15), 0.8));
	Triangle* refd = new Triangle(pointA, pointD, pointC, new Diffuse(Colour(5, 50, 15), 0.8));
	theScene->addForm(light);
	theScene->addForm(ligh);
	theScene->addForm(lig);
	theScene->addForm(plan);
	theScene->addForm(sphere);
	theScene->addForm(refa);
	theScene->addForm(refb);
	theScene->addForm(refc);
	theScene->addForm(refd);
//	theScene->addForm(sur);
	Camera cam = Camera(theScene, Vector3(40, 40, 20), Vector3(0, 0, 0), Vector3(0, 0, 1), focalLen, topWidth, resX, resY, 16);

	PngFactory establishment = PngFactory();

//Create the arrays for the cameras and the threads;

	thread * threads;
	threads = new thread[numThreads];
	Camera ** cams;
	cams = new Camera*[numThreads];

//Create the cameras and start running the threads;

	for(int i = 0; i < numThreads; i++)
	{
		cams[i] = new Camera(theScene, Vector3(40, 40, 20), Vector3(0, 0, 0), Vector3(0, 0, 1), focalLen, topWidth, resX, resY, 16);
		threads[i] = thread(renderThread, cams[i], numSamples);
	}

//Join all of the threads

	for(int i = 0; i < numThreads; i++)
	{
		threads[i].join();
	}

//Prepare the final image

	Colour * finalImage = new Colour[resX * resY];

//Average in the results from all of the cameras

	for(int i = 0; i < numThreads; i++)
	{
		Colour * tmpImage = cams[i]->getImage();
		for(int j = 0; j < resX * resY; j++)
		{
			finalImage[j] += tmpImage[j] / numThreads;
		}
	}

	establishment.makePng(finalImage, resX, resY, "test.png");

	return 0;
}
