#include "Ray.hpp"
#include "Form.hpp"
#include "Vector3.hpp"

Ray::Ray(Vector3 location, Vector3 focus, int longevity)
{

	this->direction = focus - location;
	this->direction = this->direction.normalize();;
	this->position = location;
	this->longevity = longevity;
}

Color Ray::fire(Scene* scene)
{

	Colour rayColour = Colour(0);
	while(longevity > 0){

		int corpusSize = scene->formQuantity();
		double dist = DBL_MAX;
		int closestForm = -1;
		for(int i = 0; i < corpusSize; i++)
		{
			Form toCollide = scene->getForm(i);
			if((double tmpdist = formList[i].getDistance(*this))!=-1)
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

		color -= formList[closestForm].getColor(*this);
		formList[closestForm].collideWith(*this);
		rayColour -= formList[closestForm].getColour(position, direction);
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
