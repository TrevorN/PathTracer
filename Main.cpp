#include "Camera.hpp"
#include "Scene.hpp"
#include "Vector3.hpp"
#include "PngFactory.hpp"
#include "Sphere.hpp"
#include "Mirror.hpp"
#include "Diffuse.hpp"
#include "Emissive.hpp"
#include "Refractive.hpp"
#include "Plane.hpp"
#include "Triangle.hpp"
#include <iostream>
#include <string>
#include <cmath>
#include <ctime>
#include <thread>

using namespace std;

void addCube(Scene &scene, Vector3 location, double edgeLength, Material* material)
{
    edgeLength /= 2;
    Vector3 PPP(location.getX() + edgeLength, location.getY() + edgeLength, location.getZ() + edgeLength);
    Vector3 PPN(location.getX() + edgeLength, location.getY() + edgeLength, location.getZ() - edgeLength);
    Vector3 PNP(location.getX() + edgeLength, location.getY() - edgeLength, location.getZ() + edgeLength);
    Vector3 PNN(location.getX() + edgeLength, location.getY() - edgeLength, location.getZ() - edgeLength);
    Vector3 NPP(location.getX() - edgeLength, location.getY() + edgeLength, location.getZ() + edgeLength);
    Vector3 NPN(location.getX() - edgeLength, location.getY() + edgeLength, location.getZ() - edgeLength);
    Vector3 NNP(location.getX() - edgeLength, location.getY() - edgeLength, location.getZ() + edgeLength);
    Vector3 NNN(location.getX() - edgeLength, location.getY() - edgeLength, location.getZ() - edgeLength);
    scene.addForm(new Triangle(PNP, PPP, NNP, material));
    scene.addForm(new Triangle(PPP, NPP, NNP, material));
    scene.addForm(new Triangle(PNP, PPP, PNN, material));
    scene.addForm(new Triangle(PPP, PPN, PNN, material));
    scene.addForm(new Triangle(PPP, PPN, NPP, material));
    scene.addForm(new Triangle(NPP, PPN, NPN, material));
    scene.addForm(new Triangle(PNN, PPN, NPN, material));
    scene.addForm(new Triangle(PNN, NNN, NPN, material));
    scene.addForm(new Triangle(PNN, NNN, PNP, material));
    scene.addForm(new Triangle(PNP, NNP, NNN, material));
    scene.addForm(new Triangle(NNN, NNP, NPN, material));
    scene.addForm(new Triangle(NPP, NNP, NPN, material));
}

int main()
{
	int numThreads = 4;

    int resX, resY, numSamples;

    if(false)
    {
        resX = 200;
        resY = 150;
        numSamples = 100;
    } else {
        resX = 1280;
        resY = 800;
        numSamples = 200;
    }

	double fustrumLen = 5;
    double blurRadius = 1;
	double topWidth = 5;

	Scene theScene(Colour(230, 220, 250));

    //Define the Scene
    //Ground Plane
    theScene.addForm(new Plane(Vector3(0, 0, 0), Vector3(0, 0, 1), new Diffuse(Colour(100,100,100), .3)));
    //Interesting refractive foreground
    addCube(theScene, Vector3(0,0,2.5), 5, new Diffuse(Colour(120, 130, 140)));
    //Sphere for lighting interest
    theScene.addForm(new Sphere(Vector3(9, 9, 9), 1, new Emissive(Colour(-5000, -4000, -0)))); 
    //Render the Scene
    Vector3 cameraPos(8.1, 12.2, 4.3);
    Vector3 cameraTarget(-0.1, 0.1, 2.6);
    Vector3 cameraUp(0.0421, -0.123, 1.4);
    Camera cam(theScene, cameraPos, cameraTarget, cameraUp, fustrumLen, cameraPos.getMagnitude(), blurRadius, topWidth, resX, resY, 16);

    time_t start;
    
    time(&start);
    cam.capture(numThreads, numSamples);
    double seconds = difftime(time(NULL), start);

    cout << "This took " << seconds << " seconds." << std::endl;
    PngFactory establishment;
	establishment.makePng(cam.getImage(), resX, resY, "test.png");
    
    cout << "\b";

	return 0;
}
