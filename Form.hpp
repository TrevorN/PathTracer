#ifndef C_FORM
#define C_FORM

#include "Vector3.hpp"
#include "Ray.hpp"
#include "Material.hpp"
#include "AABB.hpp"

class Ray;

class Form
{
	protected:
		Material* material;
		AABB boundingBox;
	public:
		virtual double getDistance(Ray*) const = 0;
		virtual void collideWith(Ray*) const = 0;
		virtual Colour getColour(Ray*) const = 0;
};

#endif
