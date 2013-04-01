#include "Ray.hpp"
#include "Form.hpp"
#include <cfloat>

Ray::Ray(Vector3 location, Vector3 focus, int longevity)
{

	/*
	this->direction = focus - location;
	this->direction = this->direction.normalize();
	*/
	this->direction = direction.normalize();
	this->position = location;
	this->longevity = longevity;
}

Colour Ray::fire(Scene* scene){

	Colour rayColour = Colour(0);
	while(longevity > 0){

		int corpusSize = scene->formQuantity();
		double dist = DBL_MAX;;
		int closestForm = -1;
		Form* formList = scene->getForms();
		for(int i = 0; i < corpusSize; i++)
		{

			double tmpdist;
			if((tmpdist = formList[i].getDistance(*this))!=-1)
			{
				if(tmpdist < dist)
				{
					
					closestForm = i;
					dist = tmpdist;

				}
			}
		}

		if(closestForm == -1)
		{
			rayColour = scene->getAmbience();
			break;
		}

		formList[closestForm].collideWith(*this);
		rayColour -= formList[closestForm].getColour(*this);
		longevity--;
	}

	rayColour.normalize();
	return rayColour;

}

Vector3 Ray::getPosition()
{
	return position;
}

Vector3 Ray::getDirection()
{
	return direction;
}

int Ray::getLongeveity()
{
	return longevity;
}
