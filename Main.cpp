#include "Camera.hpp"
#include "Scene.hpp"
#include "Vector3.hpp"
#include "PngFactory.hpp"
#include "Sphere.hpp"
#include "Mirror.hpp"
#include "Diffuse.hpp"
#include <iostream>

int main()
{
	int resX = 640;
	int resY = 480;
	double focalLen = 100;
	double topWidth = 640;
	Scene* theScene = new Scene(Colour(-255, -255, -255));
	Sphere* groundSphere = new Sphere(Vector3(0, -500, 0), Vector3(0, 1, 0), Vector3(0, 0, 1), 450, new Diffuse(Colour(-255, -255, -255)));
	theScene->addForm(groundSphere);

	Sphere* colorSphere = new Sphere(Vector3(0, 100, 0), Vector3(0, 1, 0), Vector3(0, 0, 1), 50, new Diffuse(Colour(55, 55, 55)));

	theScene->addForm(colorSphere);

	Camera cam = Camera(theScene, Vector3(0, 0, 0), Vector3(0, 1, 0), Vector3(0, 0, 1), focalLen, topWidth, resX, resY, 5, 0, 10);

	cam.takeSample();

	PngFactory establishment = PngFactory();
	establishment.makePng(cam.getImage(), resX, resY, "test.png");

	return 0;
}
