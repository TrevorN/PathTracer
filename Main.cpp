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
#include <thread>

void workunit(Colour* image, Camera c)
{
    for(int i = 0; i < 150; i++)
    {
        std::cout << "Taking Sample: " << i << " \n";
        c.takeSample();
    }

    image = c.getImage();
}

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

    theScene->addForm(new Triangle(pointA, pointB, pointC, new Diffuse(Colour(40, 40, 20))));
    theScene->addForm(new Triangle(pointA, pointC, pointD, new Diffuse(Colour(40, 40, 20))));
    theScene->addForm(new Triangle(pointA, pointB, pointD, new Diffuse(Colour(40, 40, 20))));
    theScene->addForm(new Sphere(Vector3(0, -9, 6), Vector3(0, 0, 1), Vector3(0, 1, 0), 2, new Emissive(Colour(-750, -500, -75))));
    theScene->addForm(new Sphere(Vector3(5, 5, 0), Vector3(0, 0, 1), Vector3(0, 1, 0), 2, new Emissive(Colour(-50, -50, -500))));
    theScene->addForm(new Plane(Vector3(0, 0, 0), Vector3(0, 0, 1), new Diffuse(Colour(50, 20, 50))));
    theScene->addForm(new Plane(Vector3(0, 5, 0), Vector3(0, -1, 0), new Diffuse(Colour(20, 50, 50))));
    theScene->addForm(new Plane(Vector3(5, 0, 0), Vector3(-1, 0, 0), new Diffuse(Colour(50, 50, 20))));

    Colour* imageA;

    std::thread t(workunit, imageA, Camera(theScene, Vector3(-10, -10, 4), Vector3(0, 0, 0), Vector3(0, 0, 1), focalLen, topWidth, resX, resY, 5));
    t.join();

	PngFactory establishment = PngFactory();

	establishment.makePng(imageA, resX, resY, "test.png");
    
    return 0;
}
