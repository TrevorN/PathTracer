#include "Vector3.hpp"
#include "Sphere.hpp"
#include <cmath>

Sphere::Sphere(Vector3 location, Vector3 rotation, Vector3 up, double radius, Material material)
{
	this->location = location;
	this->rotation = rotation.normalize();
	this->up = rotation.crossProduct(up).crossProduct(rotation).normalize();
	this->radius = radius;
	this->material = material;
}

int Sphere::getDistance(Ray ray)
{
	Vector3 rayDirection = ray.getDirection();
	Vector3 rayPosition = ray.getPosition();

	double theta = rotation.angleBetween(rayDirection);
	double x = location - rayPosition;
	double y = x * sin(theta);
	if(y  > radius)
		return -1;
	return (x * cos(theta)) - sqrt(y * y * radius * radius);
}

Ray Sphere::collideWith(Ray ray)
{
	double distance = getDistance(ray);
	if(distance == -1)
	{
		cout << "Something went horribly, horribly wrong. Goodbye world. \n"
		exit(EXIT_FAILURE);
	}

	Vector3 rayDirection = ray.getDirection();
	Vector3 rayPosition = ray.getPosition();
	Vector3 newPosition = rayPosition + (distance * rayDirection);

	Vector3 surfaceNormal = newPosition - location;
	Vector3 newDirection = material.bounce(rayDirection, surfaceNormal);

	return Ray(newPosition, newPosition + newDirection, ray.getLongevity() - 1);
}

Color Sphere::getColor(Ray ray)

	return material.getColor(ray);
}
