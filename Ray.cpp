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

Color Ray::fire(Scene* scene){

	while(longevity > 0){

		int corpusSize = scene->formQuantity();
		double dist = DBL_MAX;;
		int closestForm = -1;
		Form* formList = scene->getForms();
		for(int i = 0; i < corpusSize; i++)
		{
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
			color = scene->getAmbience();
			break;
		}

		color -= formList[closestForm].getColor(*this);
		formList[closestForm].collideWith(*this);
		longevity--;
	}

	return color;

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
