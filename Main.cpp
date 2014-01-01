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
#include <ctime>
#include <thread>

using namespace std;

void addCube(Scene* scene, Vector3 location, double edgeLength, Material* material)
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
    scene->addForm(new Triangle(PNP, PPP, NNP, material));
    scene->addForm(new Triangle(PPP, NPP, NNP, material));
    scene->addForm(new Triangle(PNP, PPP, PNN, material));
    scene->addForm(new Triangle(PPP, PPN, PNN, material));
    scene->addForm(new Triangle(PPP, PPN, NPP, material));
    scene->addForm(new Triangle(NPP, PPN, NPN, material));
    scene->addForm(new Triangle(PNN, PPN, NPN, material));
    scene->addForm(new Triangle(PNN, NNN, NPN, material));
    scene->addForm(new Triangle(PNN, NNN, PNP, material));
    scene->addForm(new Triangle(PNP, NNP, NNN, material));
    scene->addForm(new Triangle(NNN, NNP, NPN, material));
    scene->addForm(new Triangle(NPP, NNP, NPN, material));
}

int main()
{
	int numThreads = 4;

	int resX = 1280;
	int resY = 800;

	int numSamples = 100;

	double fustrumLen = 5;
    double blurRadius = 1;
	double topWidth = 5;
	Scene* theScene = new Scene(Colour(150, 150, 150));

	Vector3 pointA(0, 0, 6);
	Vector3 pointB(-6, 0, -2.5);
	Vector3 pointC(0, 6, -2.5);
	Vector3 pointD(0, 0, -2.5);

    addCube(theScene, Vector3(0,0,0), 5, new Refractive(Colour(5, 10, 15)));

	Sphere* refr[5];
	refr[0] = new Sphere(Vector3(20, 20, 2), 1, new Refractive(Colour(5, 10, 15), 1.5));
	refr[1] = new Sphere(Vector3(20, 24, 6), 1, new Refractive(Colour(5, 10, 15), 1.25));
	refr[2] = new Sphere(Vector3(20, 28, 10), 1, new Refractive(Colour(5, 10, 15), 1.125));
	refr[3] = new Sphere(Vector3(24, 20, 6), 1, new Refractive(Colour(5, 10, 15), 2.5));
	refr[4] = new Sphere(Vector3(28, 20, 10), 1, new Refractive(Colour(5, 10, 15), 3.5));
	for(int i = 0; i<5; i++){
		theScene->addForm(refr[i]);
	}
//	Sphere* sur = new Sphere(Vector3(0, 0, 0), Vector3(0, 1, 0), Vector3(0, 0, 1), 60, new Diffuse(Colour(50, 5, 7), 0.9));
	Sphere* spheres[36];
	for(int i = 0; i < 6; i++){
		for(int j = 0; j < 6; j++){
			spheres[i+j*4] = new Sphere(Vector3(j*4-8, i*4-8, -3), 1, new Diffuse(Colour(30, 25, 20), 0.05));
			theScene->addForm(spheres[i+j*4]);
		}
	}

	Sphere* sphere = new Sphere(Vector3(4, 4, 0), 2, new Diffuse(Colour(25, 50, 70), 0.8));
	Sphere* light = new Sphere(Vector3(-8, 16, 0), 4, new Emissive(Colour(-50, -250, -140)));
	Sphere* ligh = new Sphere(Vector3(16, -8, 0), 4, new Emissive(Colour(-50, -140, -250)));
	Sphere* lig = new Sphere(Vector3(-8, -8, 0), 4, new Emissive(Colour(-250, -140, -50)));
	Plane* plan = new Plane(Vector3(0, 0, -4), Vector3(0, 0, 1), new Diffuse(Colour(75, 20, 10)));
	Triangle* refa = new Triangle(pointA, pointB, pointC, new Diffuse(Colour(5, 20, 15), 0.8));
	Triangle* refb = new Triangle(pointA, pointB, pointD, new Diffuse(Colour(5, 30, 15), 0.8));
	Triangle* refc = new Triangle(pointD, pointB, pointC, new Diffuse(Colour(5, 40, 15), 0.8));
	Triangle* refd = new Triangle(pointA, pointD, pointC, new Diffuse(Colour(5, 50, 15), 0.8));
	theScene->addForm(light);
	theScene->addForm(ligh);
	theScene->addForm(lig);
	theScene->addForm(plan);
	theScene->addForm(sphere);
	theScene->addForm(refa);
	theScene->addForm(refb);
	theScene->addForm(refc);
	theScene->addForm(refd);
//	theScene->addForm(sur);

	PngFactory establishment = PngFactory();

    Camera cam(theScene, Vector3(40, 40, 20), Vector3(0, 0, 0), Vector3(0, 0, 1), fustrumLen, Vector3(40, 40, 0).getMagnitude(), blurRadius, topWidth, resX, resY, 16);

    time_t start;
    
    time(&start);
    cam.capture(numThreads, numSamples);
    double seconds = difftime(time(NULL), start);

    cout << "This took " << seconds << " seconds." << std::endl;

	establishment.makePng(cam.getImage(), resX, resY, "test.png");
    
    cout << "\b";

	return 0;
}
