#ifndef C_CYLINDER
#define C_CYLINDER

#include "Ray.hpp"
#include "Vector3.hpp"

class Cylinder : public Form
{
		double radius;
		double height;
		int face;
	public:
		Cylinder(Vector3, Vector3, Vector3, double, double, Material*);
		~Cylinder();
		Cylinder(const Cylinder&);
		Cylinder& operator=(Cylinder);
		double getDistance(Ray*);
		void collideWith(Ray*);
		Colour getColour(Ray*);
};

#endif
