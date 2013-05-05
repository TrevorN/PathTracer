#include "Camera.hpp"
#include "Scene.hpp"
#include "Vector3.hpp"
#include "PngFactory.hpp"
#include "Sphere.hpp"
#include "Cylinder.hpp"
#include "Mirror.hpp"
#include "Diffuse.hpp"
#include <iostream>

int main()
{
	int resX = 1280;
	int resY = 720;

	double focalLen = 2;
	double topWidth = 17;
	Scene* theScene = new Scene(Colour(0, 0, 0));

	Cylinder* centerCylinder = new Cylinder(Vector3(0, 2, 0), Vector3(1, 0, 0), Vector3(0, 0, 1), 1, 4, new Diffuse(Colour(50, 50, 50)));
	theScene->addForm(centerCylinder);
	
	/*
	Sphere* centerSphere = new Sphere(Vector3(0, 2, 0), Vector3(0, 1, 0), Vector3(0, 0, 1), 1, new Diffuse(Colour(50, 50, 50)));
	theScene->addForm(centerSphere);

	*/
//	/*
	Sphere* redSphere = new Sphere(Vector3(0, 0, 3), Vector3(0, 1, 0), Vector3(0, 0, 1), 1, new Diffuse(Colour(-4000, 0, 0)));
	theScene->addForm(redSphere);

	Sphere* greenSphere = new Sphere(Vector3(-2.59808, 0, -1.5), Vector3(0, 1, 0), Vector3(0, 0, 1), 1, new Diffuse(Colour(0, -4000, 0)));
	theScene->addForm(greenSphere);


	Sphere* blueSphere = new Sphere(Vector3(2.59808, 0, -1.5), Vector3(0, 1, 0), Vector3(0, 0, 1), 1, new Diffuse(Colour(0, 0, -4000)));
	theScene->addForm(blueSphere);

	

	Camera cam = Camera(theScene, Vector3(0, -10, 0), Vector3(0, 0, 1), Vector3(0, 0, 1), focalLen, topWidth, resX, resY, 5);

	PngFactory establishment = PngFactory();

	for(int i = 0; i < 5; i++)
	{
		std::cout << "Taking sample " << i << " \n";
		cam.takeSample();
	}

	establishment.makePng(cam.getImage(), resX, resY, "test.png");


	return 0;
}
