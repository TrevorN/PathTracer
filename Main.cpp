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
	int resX = 1024;
	int resY = 1024;
	double focalLen = 1024;
	double topWidth = 1024;
	Scene* theScene = new Scene(Colour(-128, -100, -130));
	theScene->addForm(new Sphere(Vector3(0, 1024, 0), Vector3(0, 1, 0), Vector3(0, 0, 1), 256, new Mirror(Colour(0, -128, -128))));


	/* trip
	theScene->addForm(new Sphere(Vector3(512, 1536, 512), Vector3(0, 1, 0), Vector3(0, 0, 1), 128, new Mirror(Colour(32, 64, 32))));
	theScene->addForm(new Sphere(Vector3(-303, 736, -100), Vector3(0, 1, 0), Vector3(0, 0, 1), 106, new Mirror(Colour(102, 28, 68))));
	theScene->addForm(new Sphere(Vector3(203, 1736, -100), Vector3(0, 1, 0), Vector3(0, 0, 1), 306, new Mirror(Colour(2, 28, 88))));
	theScene->addForm(new Sphere(Vector3(0, 54, 0), Vector3(0, 1, 0), Vector3(0, 0, 1), 2056, new Mirror(Colour(-120, -28, -158))));
	*/

	Sphere* GroundSphere = new Sphere(Vector3(50, 200, -50), Vector3(0, 0, 0), Vector3(0, 0, 0), 50, new Diffuse(Colour(110, 28, 68), 0));
	theScene->addForm(GroundSphere);

	Camera cam = Camera(theScene, Vector3(0, 0, 0), Vector3(0, 1, 0), Vector3(0, 0, 1), focalLen, topWidth, resX, resY, 5);

	cam.takeSample();

	PngFactory establishment = PngFactory();
	establishment.makePng(cam.getImage(), resX, resY, "test.png");
	
	return 0;
}
