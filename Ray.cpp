#include "Ray.hpp"
#include "Form.hpp"
#include <cfloat>
#include <iostream>

Ray::Ray(Vector3 location, Vector3 direction, int longevity)
{

	/*
	   this->direction = focus - location;
	   this->direction = this->direction.normalize();
	   */
	this->direction = direction.normalize();
	this->position = location;
	this->longevity = longevity;
}

Colour Ray::fire(Scene* scene)
{

	Colour rayColour = Colour(0, 0, 0);
	while(longevity > 0){

		int corpusSize = scene->formQuantity();
		double dist = DBL_MAX;
		int closestForm = -1;

		for(int i = 0; i < corpusSize; i++)
		{
			Form* toCollide = scene->getForm(i);
			double tmpdist;
			if((tmpdist = toCollide->getDistance(this))!=-1)
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
			rayColour += scene->getAmbience();
			break;
		}


		rayColour -= scene->getForm(closestForm)->getColour(this);
		scene->getForm(closestForm)->collideWith(this);
		longevity--;
	}

	//rayColour.normalize();
	return rayColour;

}

void Ray::setPosition(Vector3 position)
{
	this->position = position;
}

Vector3 Ray::getPosition()
{
	return position;
}

void Ray::setDirection(Vector3 direction)
{
	this->direction = direction.normalize();
}

Vector3 Ray::getDirection()
{
	return direction;
}

int Ray::getLongeveity()
{
	return longevity;
}
