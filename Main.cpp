#include "Camera.hpp"
#include "Scene.hpp"
#include "Vector3.hpp"
#include "PngFactory.hpp"
#include "Sphere.hpp"
#include "Mirror.hpp"
#include <iostream>

int main()
{
	int resX = 1024;
	int resY = 1024;
	double focalLen = 1024;
	double topWidth = 1024;
	Scene* setting = new Scene(Colour(-128, -100, -130));
	setting->addForm(new Sphere(Vector3(0, 1024, 0), Vector3(0, 1, 0), Vector3(0, 0, 1), 256, new Mirror(Colour(0, -128, -128))));
	setting->addForm(new Sphere(Vector3(512, 1536, 512), Vector3(0, 1, 0), Vector3(0, 0, 1), 128, new Mirror(Colour(32, 64, 32))));
	setting->addForm(new Sphere(Vector3(-303, 736, -100), Vector3(0, 1, 0), Vector3(0, 0, 1), 106, new Mirror(Colour(102, 28, 68))));
	setting->addForm(new Sphere(Vector3(203, 1736, -100), Vector3(0, 1, 0), Vector3(0, 0, 1), 306, new Mirror(Colour(2, 28, 88))));
	setting->addForm(new Sphere(Vector3(0, 54, 0), Vector3(0, 1, 0), Vector3(0, 0, 1), 2056, new Mirror(Colour(-120, -28, -158))));
	Camera cam = Camera(setting, Vector3(0, 0, 0), Vector3(0, 1, 0), Vector3(0, 0, 1), focalLen, topWidth, resX, resY, 5);
	cam.takeSample();

	PngFactory establishment = PngFactory();
	establishment.makePng(cam.getImage(), resX, resY, "test.png");
	
	return 0;
}
