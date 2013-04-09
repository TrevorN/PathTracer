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
	Scene* theScene = new Scene(Colour(-240, -240, -240));
	Sphere* groundSphere = new Sphere(Vector3(0, 20, -510), Vector3(0, 1, 0), Vector3(0, 0, 1), 500, new Diffuse(Colour(50, 50, 50)));
	theScene->addForm(groundSphere);

	/* trip
	theScene->addForm(new Sphere(Vector3(512, 1536, 512), Vector3(0, 1, 0), Vector3(0, 0, 1), 128, new Mirror(Colour(32, 64, 32))));
	theScene->addForm(new Sphere(Vector3(-303, 736, -100), Vector3(0, 1, 0), Vector3(0, 0, 1), 106, new Mirror(Colour(102, 28, 68))));
	theScene->addForm(new Sphere(Vector3(203, 1736, -100), Vector3(0, 1, 0), Vector3(0, 0, 1), 306, new Mirror(Colour(2, 28, 88))));
	theScene->addForm(new Sphere(Vector3(0, 54, 0), Vector3(0, 1, 0), Vector3(0, 0, 1), 2056, new Mirror(Colour(-120, -28, -158))));
	*/

	Sphere* colorSphere = new Sphere(Vector3(0, 20, 0), Vector3(0, 1, 0), Vector3(0, 0, 1), 5, new Diffuse(Colour(0, 255, 255)));

	theScene->addForm(colorSphere);

	Camera cam = Camera(theScene, Vector3(0, 0, 0), Vector3(0, 1, 0), Vector3(0, 0, 1), focalLen, topWidth, resX, resY, 5);

	cam.takeSample();

	PngFactory establishment = PngFactory();
	establishment.makePng(cam.getImage(), resX, resY, "test.png");
	
	return 0;
}
