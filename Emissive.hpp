#ifndef C_EMISSIVE
#define C_EMISSIVE

#include "Material.hpp"
#include "Ray.hpp"
#include "Colour.hpp"

class Emissive : public Material
{
	public:
		Emissive(Colour);
		Vector3 bounce(Vector3, Vector3);
		Colour getColour(Vector3, Vector3);
};

#endif
