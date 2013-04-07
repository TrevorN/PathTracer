#ifndef C_MIRROR
#define C_MIRROR

#include "Material.hpp"

class Mirror : public Material
{
	public:
		Mirror();
		Mirror(Colour);
		Vector3 bounce(Vector3, Vector3);
		Colour getColour(Vector3, Vector3);
};

#endif
