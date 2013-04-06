#ifndef C_MATERIAL
#define C_MATERIAL

#include "Colour.hpp"
#include "Ray.hpp"

class Material
{
		Colour colour;
	public:
		virtual Vector3 bounce(Vector3, Vector3);
		virtual Colour getColour(Vector3, Vector3);
};

#endif
