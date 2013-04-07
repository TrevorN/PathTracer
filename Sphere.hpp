#ifndef C_SPHERE
#define C_SPHERE

#include "Ray.hpp"
#include "Vector3.hpp"

class Sphere : public Form
{
		double radius;
	public:
		Sphere(Vector3, Vector3, Vector3, double, Material*);
		~Sphere();
		Sphere(const Sphere&);
		Sphere& operator=(Sphere);
		int getDistance(Ray*);
		void collideWith(Ray*);
		Colour getColour(Ray*);
};

#endif
