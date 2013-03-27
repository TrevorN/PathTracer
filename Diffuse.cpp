#include "Diffuse.hpp"
#include "Color.hpp"i
#include <cmath>

const double pi = 4.0 * atan(1.0);

Diffuse::Diffuse(double hardness)
{
	//lol nobody cares about hardness.
}

Ray Diffuse::bounce(Vector3 rayIn, Vector3 surfaceNormal)
{
	double phi = rand() * 2 * pi;
	double theta = asin(rand);

	double x = r * cos(theta) * cos(phi);
	double y = r * cos(theta) * sin(phi);
	double z = r * sin(theta);
}
