#ifndef C_MATERIAL
#define C_MATERIAL

#include "Colour.hpp"
#include "Vector3.hpp"

class Material
{
	protected:
		Colour colour;
	public:
		virtual Vector3 bounce(Vector3, Vector3) = 0;
		virtual Colour getColour(Vector3, Vector3) = 0;
};

#endif
