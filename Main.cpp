#include "Camera.hpp"
#include "Scene.hpp"
#include "Vector3.hpp"
#include "PngFactory.hpp"
#include <iostream>

int main()
{
	int resX = 1024;
	int resY = 1024;
	double focalLen = 1024;
	double topWidth = 1024;
	Camera cam = Camera(Scene(Colour(255,0,0)), Vector3(0, 0, 0), Vector3(0, 1, 0), Vector3(0, 0, 1), focalLen, topWidth, resX, resY, 5);
	cam.takeSample();

	PngFactory establishment = PngFactory();
	establishment.makePng(cam.getImage(), resX, resY);
	
	return 0;
}
