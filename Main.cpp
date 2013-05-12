#include "Camera.hpp"
#include "Scene.hpp"
#include "Vector3.hpp"
#include "PngFactory.hpp"
#include "Sphere.hpp"
#include "Cylinder.hpp"
#include "Mirror.hpp"
#include "Diffuse.hpp"
#include "Emissive.hpp"
#include "Plane.hpp"
#include <iostream>
#include <cmath>

int main()
{
	int resX = 500;
	int resY = 500;

	double focalLen = 2;
	double topWidth = 33;
	Scene* theScene = new Scene(Colour(255, 255, 255));

	Sphere* lightSphere = new Sphere(Vector3(0, 0, 20), Vector3(0, 1, 0), Vector3(0, 0, 1), 2, new Emissive(Colour(-500, -400, -500)));
	theScene->addForm(lightSphere);
	
	Sphere* lightSpherea = new Sphere(Vector3(0, 20, 0), Vector3(0, 1, 0), Vector3(0, 0, 1), 2, new Emissive(Colour(-500, -400, -500)));
	theScene->addForm(lightSpherea);
    
	Sphere* lightSphereb = new Sphere(Vector3(20, 0, 0), Vector3(0, 1, 0), Vector3(0, 0, 1), 2, new Emissive(Colour(-500, -400, -500)));
	theScene->addForm(lightSphereb);
   
	Sphere* mirrorSphere = new Sphere(Vector3(0, 0, 0), Vector3(0, 1, 0), Vector3(0, 0, 1), 5, new Diffuse(Colour(25, 25, 25), 0.7));
	theScene->addForm(mirrorSphere);

	Sphere* focusSphere = new Sphere(Vector3(28, 28, -2), Vector3(0, 1, 0), Vector3(0, 0, 1), 1, new Diffuse(Colour(15, 15, 15)));
	theScene->addForm(focusSphere);

	Cylinder* focusLCylinder = new Cylinder(Vector3(16, 4, 0), Vector3(0, 1, 0), Vector3(0, 0, 1), 2, 18, new Diffuse(Colour(16, 32, 32), 0.8));
	theScene->addForm(focusLCylinder);

	Cylinder* focusRCylinder = new Cylinder(Vector3(4, 16, 0), Vector3(0, 1, 0), Vector3(0, 0, 1), 2, 18, new Diffuse(Colour(32, 16, 32), 0.8));
	theScene->addForm(focusRCylinder);

	Plane* floorPlane = new Plane(Vector3(0, 0, -5), Vector3(0, 0, 1), new Diffuse(Colour(20, 20, 40)));
	theScene->addForm(floorPlane);

	Plane* leftPlane = new Plane(Vector3(-7, 0, 0), Vector3(1, 0, 0), new Diffuse(Colour(40, 20, 20)));
	theScene->addForm(leftPlane);

	Plane* rightPlane = new Plane(Vector3(0, -7, 0), Vector3(0, 1, 0), new Diffuse(Colour(20, 40, 20)));
	theScene->addForm(rightPlane);

	Camera cam = Camera(theScene, Vector3(40, 40, 2), Vector3(0, 0, 0), Vector3(0, 0, 1), focalLen, topWidth, resX, resY, 5);

	PngFactory establishment = PngFactory();

	for(int i = 0; i < 4096; i++)
	{
		std::cout << "Taking sample " << i << " \n";
		cam.takeSample();
	}

	establishment.makePng(cam.getImage(), resX, resY, "test.png");

	return 0;
}
