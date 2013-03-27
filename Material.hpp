#ifndef C_MATERIAL
#define C_MATERIAL

#include "Color.hpp"
#include "Ray.hpp"

class Material
{
		Color color;
	public:
		virtual Vector3 bounce(Vector3, Vector3);
		virtual Colour getColour(Vector3, Vector3);
};

#endif
