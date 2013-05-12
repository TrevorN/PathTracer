#ifndef C_PLANE
#define C_PLANE

#include "Ray.hpp"
#include "Vector3.hpp"

class Plane : public Form
{
	public:
		Plane(Vector3, Vector3, Material*);
		~Plane();
		Plane(const Plane&);
		Plane& operator=(Plane);
		double getDistance(Ray*);
		void collideWith(Ray*);
		Colour getColour(Ray*);
};

#endif
