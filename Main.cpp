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
	double focalLen = 5;
	double topWidth = 5;
	Scene* theScene = new Scene(Colour(-255, -255, -255));
//	Sphere* groundSphere = new Sphere(Vector3(0, 20, -510), Vector3(0, 1, 0), Vector3(0, 0, 1), 500, new Mirror(Colour(-50, -200, -50)));
//	theScene->addForm(groundSphere);

	Sphere* colorSphere = new Sphere(Vector3(0, 200, 0), Vector3(0, 1, 0), Vector3(0, 0, 1), 50, new Mirror(Colour(255, 0, 255)));

	theScene->addForm(colorSphere);

	Camera cam = Camera(theScene, Vector3(0, 0, 0), Vector3(0, 1, 0), Vector3(0, 0, 1), focalLen, topWidth, resX, resY, 3, 0, 1);

	cam.takeSample();

	PngFactory establishment = PngFactory();
	establishment.makePng(cam.getImage(), resX, resY, "test.png");

	return 0;
}
