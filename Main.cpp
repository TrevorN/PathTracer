#include "Camera.hpp"
#include "Scene.hpp"
#include "Vector3.hpp"
#include <iostream>

using namespace std;

int main()
{
	Scene theScene = Scene(Color(255, 255, 255));
	Sphere GroundSphere = Sphere(Vector3(50, 0, -50), Vector3(0, 0, 0), Vector3(0, 0, 0), 50, Diffuse(
	Camera cam = Camera(theScene, Vector3(0, 0, 0), Vector3(0, 1, 0), Vector3(0, 0, 1), 5.0, 5.0, 5, 5, 5);
	cam.takeSample();
	return 0;
}
