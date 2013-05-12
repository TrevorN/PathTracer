#include "Camera.hpp"
#include "Scene.hpp"
#include "Vector3.hpp"
#include "PngFactory.hpp"
#include "Sphere.hpp"
#include "Cylinder.hpp"
#include "Mirror.hpp"
#include "Diffuse.hpp"
#include "Emissive.hpp"
#include <iostream>
#include <cmath>

int main()
{
	int resX = 500;
	int resY = 500;

	double focalLen = 2;
	double topWidth = 17;
	Scene* theScene = new Scene(Colour(20, 20, 20));


	Sphere* centerSphere = new Sphere(Vector3(4, 4, 4), Vector3(1, 0, 0), Vector3(0, 0, 1), 2, new Diffuse(Colour(-10, -10, -10)));
	theScene->addForm(centerSphere);

	Sphere* lightSphere = new Sphere(Vector3(12, 12, 10), Vector3(0, 1, 0), Vector3(0, 0, 1), 2, new Emissive(Colour(-8000, -8000, -8000)));
	theScene->addForm(lightSphere);

	Cylinder* rCylinder = new Cylinder(Vector3(-1, 0, 0), Vector3(0, 1, 0), Vector3(1, 0, 0), 100, 0.5, new Diffuse(Colour(255, 0, 55), 0.9));
	theScene->addForm(rCylinder);

	Cylinder* lCylinder = new Cylinder(Vector3(0, -1, 0), Vector3(0, 0, 1), Vector3(0, 1, 0), 100, 0.5, new Diffuse(Colour(0, 255, 55), 0.9));
	theScene->addForm(lCylinder);

	Cylinder* bCylinder = new Cylinder(Vector3(0, 0, -1), Vector3(0, 1, 0), Vector3(0, 0, -1), 100, 0.5, new Diffuse(Colour(0, 55, 255), 0.9));
	theScene->addForm(bCylinder);



	Camera cam = Camera(theScene, Vector3(10, 10, 6), Vector3(0, 0, 0), Vector3(0, 0, 1), focalLen, topWidth, resX, resY, 7);

	PngFactory establishment = PngFactory();

	for(int i = 0; i < 32; i++)
	{
		std::cout << "Taking sample " << i << " \n";
		cam.takeSample();
	}

	establishment.makePng(cam.getImage(), resX, resY, "test.png");


	return 0;
}
