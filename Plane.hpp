#ifndef C_PLANE
#define C_PLANE

#include "Ray.hpp"
#include "Vector3.hpp"

class Plane : public Form
{
		Vector3 location, up;
	public:
		Plane(Vector3, Vector3, Material*);
		~Plane();
		double getDistance(Ray*) const;
		void collideWith(Ray*) const;
		Colour getColour(Ray*) const;
};

#endif
