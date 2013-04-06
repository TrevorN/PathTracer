#include "Camera.hpp"
#include "Scene.hpp"
#include "Vector3.hpp"
#include "PngFactory.hpp"
#include <iostream>

using namespace std;

int main()
{
	Scene theScene = Scene(Color(255, 255, 255));
	Sphere GroundSphere = Sphere(Vector3(50, 0, -50), Vector3(0, 0, 0), Vector3(0, 0, 0), 50, Diffuse(
	theScene.addForm(GroundSphere);
	int resX = 500;
	int resY = 500;
	double focalLen = 500;
	double topWidth = 500;
	Camera cam = Camera(theScene, Vector3(0, 0, 0), Vector3(0, 1, 0), Vector3(0, 0, 1), focalLen, topWidth, resX, resY, 5);
	cam.takeSample();

	PngFactory establishment = PngFactory();
	establishment.makePng(cam.getImage(), resX, resY);
	
	return 0;
}
