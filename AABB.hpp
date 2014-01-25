#ifndef C_AABB
#define C_AABB

#include "Vector3.hpp"
#include "Diffuse.hpp"
#include "Ray.hpp"
#include "Colour.hpp"

class AABB
{
	Vector3 bounds [2];
public:
	AABB(Vector3, Vector3);
	~AABB();
	double getDistance(Ray*) const;
	void collideWith(Ray*) const;
	Colour getColour(Ray*) const;
};

#endif