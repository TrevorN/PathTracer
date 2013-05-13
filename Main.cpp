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
	Scene* theScene = new Scene(Colour(200, 200, 200));

    Vector3 pointA = Vector3(0, -2, 5);
    Vector3 pointB = Vector3(0, 5, 0);
    Vector3 pointC = Vector3(-5, -5, 0);
    Vector3 pointD = Vector3(5, -5, 0);
    
	Camera cam = Camera(theScene, Vector3(-40, -40, 2), Vector3(0, 0, 0), Vector3(0, 0, 1), focalLen, topWidth, resX, resY, 5);

	PngFactory establishment = PngFactory();

	for(int i = 0; i < 5; i++)
	{
		std::cout << "Taking sample " << i + 1 << " \n";
		cam.takeSample();
	}

	establishment.makePng(cam.getImage(), resX, resY, "test.png");

	return 0;
}
