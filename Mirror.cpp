#include "Mirror.hpp"

Mirror::Mirror()
{
	
	this->colour = Colour(0);

}

Mirror::Mirror(Colour colour)
{
	
	this->colour = colour;

}

Vector3 Mirror::bounce(Vector3 direction, Vector3 normal)
{

	Vector3 projection = direction.projectOnto(normal);
	Vector3 resultant = direction - (projection * 2);
	return resultant;

}

Colour Mirror::getColour(Vector3, Vector3)
{

	return colour;

}
