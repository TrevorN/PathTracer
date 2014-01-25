#ifndef C_SPHERE
#define C_SPHERE

#include "Ray.hpp"
#include "Vector3.hpp"
#include "Form.hpp"

class Sphere : public Form
{
		Vector3 location;
		double radius;
			public:
		Sphere(Vector3, double, Material*);
		~Sphere();
		double getDistance(Ray*) const;
		void collideWith(Ray*) const;
		Colour getColour(Ray*) const;
};

#endif
