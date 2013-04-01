#ifndef C_MATERIAL
#define C_MATERIAL

#include "Colour.hpp"
#include "Vector3.hpp"

class Material
{
		Colour color;
	public:
		virtual Vector3 bounce(Vector3, Vector3);
		virtual Colour getColour(Vector3, Vector3);
};

#endif
