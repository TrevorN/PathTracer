#ifndef C_FORM
#define C_FORM

#include "Vector3.hpp"
#include "Ray.hpp"
#include "Material.hpp"

class Ray;

class Form
{

		Material material;
		Vector3 location, rotation, up;

	public:

		virtual int getDistance(Ray) = 0;
		virtual Ray collideWith(Ray) = 0;
		virtual Colour getColour(Ray) = 0;

};

#endif
