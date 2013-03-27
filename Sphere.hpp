#ifndef C_SPHERE
#ifndef C_SPHERE
#define C_SPHERE

#include "Ray.hpp"
#include "Vector3.hpp"

class Sphere : public Form
{
		double radius;
	private:
		Sphere(Vector3, Vector3, Vector3, double, Material);
		int getDistance(Ray);
		Ray collideWith(Ray);
		Color getColor(Ray);
}

#endif
