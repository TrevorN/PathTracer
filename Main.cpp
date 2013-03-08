#include "Camera.hpp"
#include "Scene.hpp"
#include "Vector3.hpp"
#include <iostream>

using namespace std;

int main()
{
	Camera cam = Camera(Scene(), Vector3(0, 0, 0), Vector3(0, 1, 0), Vector3(0, 0, 1), 5.0, 5.0, 5, 5, 5);
	cam.takeSample();
	return 0;
}
