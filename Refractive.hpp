#ifndef C_REFRACTIVE
#define C_REFRACTIVE

#include "Material.hpp"
#include "Ray.hpp"
#include "Colour.hpp"

class Refractive : public Material
{
		double refractiveIndex;
	public:
		Refractive(Colour);
		Refractive(Colour, double);
		Vector3 bounce(Vector3, Vector3);
		Colour getColour(Vector3, Vector3);
};

#endif
