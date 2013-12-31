#include "Camera.hpp"
#include "Scene.hpp"
#include "Vector3.hpp"
#include "PngFactory.hpp"
#include "Sphere.hpp"
#include "Cylinder.hpp"
#include "Mirror.hpp"
#include "Diffuse.hpp"
#include "Emissive.hpp"
#include "Refractive.hpp"
#include "Plane.hpp"
#include "Triangle.hpp"
#include <iostream>
#include <string>
#include <cmath>
#include <thread>

using namespace std;

int main()
{
    int numThreads = 4;

	int resX = 1024;
	int resY = 1024;

	int numSamples = 10;

	double focalLen = 5;
	double topWidth = 5;
	Scene* theScene = new Scene(Colour(0, 150, 150));
    
    theScene->addForm(new Sphere(Vector3(0,0,0), 20, new Diffuse(Colour(0, 0, 0)))); 
    
    //Create the camera
    Camera cam(theScene, Vector3(10, 0, 0), Vector3(0, 0, 0), Vector3(0, 0, 1), focalLen, topWidth, resX, resY, 16);

    //Render the image
    for(int i = 0; i < numSamples; i++)
    {
        cam.takeSample();
    }
    //cam.capture(numThreads, numSamples);

    //Prepare the final image
    PngFactory establishment = PngFactory();
	establishment.makePng(cam.getImage(), resX, resY, "test.png");

	return 0;
}
