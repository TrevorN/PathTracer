#ifndef C_DIFFUSE
#define C_DIFFUSE

#include "Material.hpp"
#include "Ray.hpp"
#include "Colour.hpp"

class Diffuse : public Material
{
		double hardness; //Keep this between 0 and 90, or else things will get radical.
	public:
		Diffuse(Colour, double);
		Vector3 bounce(Vector3, Vector3);
		Colour getColour(Vector3, Vector3);
};

#endif
