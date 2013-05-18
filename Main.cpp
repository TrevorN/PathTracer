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

int main()
{
	int resX = 500;
	int resY = 500;

	double focalLen = 2;
	double topWidth = 17;
	Scene* theScene = new Scene(Colour(150, 150, 150));

	Vector3 pointA = Vector3(0, 0, 6);
	Vector3 pointB = Vector3(-9.237/2, 0, -2.5);
	Vector3 pointC = Vector3(4.6188/2, 4, -2.5);
	Vector3 pointD = Vector3(4.6188/2, -4, -2.5);

	Sphere* wat = new Sphere(Vector3(20, 20, 4), Vector3(0, 1, 0), Vector3(0, 0, 1), 1, new Refractive(Colour(5, 10, 15), 1.5));
//	Sphere* sur = new Sphere(Vector3(0, 0, 0), Vector3(0, 1, 0), Vector3(0, 0, 1), 60, new Diffuse(Colour(50, 5, 7), 0.9));
	Sphere* sphere = new Sphere(Vector3(4, 4, 0), Vector3(0, 1, 0), Vector3(0, 0, 1), 2, new Diffuse(Colour(25, 50, 70), 0.8));
	Sphere* light = new Sphere(Vector3(-8, 16, 0), Vector3(0, 1, 0), Vector3(0, 0, 1), 4, new Emissive(Colour(-50, -250, -140)));
	Sphere* ligh = new Sphere(Vector3(16, -8, 0), Vector3(0, 1, 0), Vector3(0, 0, 1), 4, new Emissive(Colour(-50, -140, -250)));
	Plane* plan = new Plane(Vector3(0, 0, -4), Vector3(0, 0, 1), new Diffuse(Colour(75, 20, 10)));
	Triangle* refa = new Triangle(pointA, pointB, pointC, new Diffuse(Colour(5, 20, 15), 0.8));
	Triangle* refb = new Triangle(pointA, pointB, pointD, new Diffuse(Colour(5, 30, 15), 0.8));
	Triangle* refc = new Triangle(pointD, pointB, pointC, new Diffuse(Colour(5, 40, 15), 0.8));
	Triangle* refd = new Triangle(pointA, pointD, pointC, new Diffuse(Colour(5, 50, 15), 0.8));
	theScene->addForm(light);
	theScene->addForm(ligh);
	theScene->addForm(sphere);
	theScene->addForm(plan);
	theScene->addForm(refa);
	theScene->addForm(refb);
	theScene->addForm(refc);
	theScene->addForm(refd);
//	theScene->addForm(sur);
	theScene->addForm(wat);
	Camera cam = Camera(theScene, Vector3(40, 40, 2), Vector3(0, 0, 0), Vector3(0, 0, 1), focalLen, topWidth, resX, resY, 7);

	PngFactory establishment = PngFactory();

	for(int i = 0; i < 10; i++)
	{
		std::cout << "Taking sample " << i + 1 << " \n";
		cam.takeSample();
	}

	establishment.makePng(cam.getImage(), resX, resY, "test.png");

	return 0;
}
