#include "Ray.hpp"
#include "Form.hpp"
#include "Vector3.hpp"

Ray::Ray(Vector3 location, Vector3 focus, Scene* scene, int longevity)
{

	this->direction = focus - location;
	this->direction = this->direction.normalize();;
	this->position = location;
	this->scene = scene;
	this->longevity = longevity;
}

Colour Ray::fire(){

	Colour rayColour = Colour(0);
	while(longevity > 0){

		int corpusSize = scene->formQuantity();
		int dist = 0;
		int tmpdist = 0;
		int closestForm = -1;
		Form* formList = scene->getForms();
		for(int i = 0; i < corpusSize; i++)
		{
			if((tmpdist = formList[i].collideWith(position, direction))!=-1)
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

		rayColour -= formList[closestForm].getColour(position, direction);
		formList[closestForm].reflect(position, direction);
		longevity--;
	}

	rayColour.normalize();
	return rayColour;

}
