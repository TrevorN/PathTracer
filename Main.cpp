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
	
	double focalLen = 1;
	double topWidth = 5;
	Scene* theScene = new Scene(Colour(255, 255, 255));
	Sphere* otherSphere = new Sphere(Vector3(1, 0, 0), Vector3(0, 1, 0), Vector3(0, 0, 1), 1, new Diffuse(Colour(100, 100, 100)));
	theScene->addForm(otherSphere);

	Sphere* colorSphere = new Sphere(Vector3(-1, 0, 0), Vector3(0, 1, 0), Vector3(0, 0, 1), 1, new Diffuse(Colour(100, 100, 100)));

	theScene->addForm(colorSphere);

	Camera cam = Camera(theScene, Vector3(0, -4, 0), Vector3(0, 0, 0), Vector3(0, 0, 1), focalLen, topWidth, resX, resY, 5);

    PngFactory establishment = PngFactory();

	for(int i = 0; i < 50; i++)
	{
		std::cout << "Taking sample " << i << " \n";
		cam.takeSample();
        establishment.makePng(cam.getImage(), resX, resY, "test.png");
	}

	return 0;
}
