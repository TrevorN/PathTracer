#include "Ray.hpp"
#include "Form.hpp"

Ray::Ray(Vector3 location, Vector3 focus, Scene* sceneRef, int longevity)
{

	this->rotation = focus - location;
	this->rotation = this->rotation.normalize();;
	this->location = location;
	this->sceneRef = sceneRef;
	this->longevity = longevity;

}

int Ray::fire(){

	while(longevity > 0){

		int corpusSize = sceneRef->formQuantity();
		int dist = 0;
		int tmpdist = 0;
		int closestForm = -1;
		Form* formList = sceneRef->getForms();
		for(int i = 0; i < corpusSize; i++){

			if((tmpdist = formList[i].collideWith(location, rotation))!=-1){
				if(tmpdist < dist){
					
					closestForm = i;
					dist = tmpdist;

				}
			}

		}

		if(closestForm == -1){

			color = sceneRef->getAmbience();
			break;

		}

		Vector3 l = formList[closestForm].reflect(location, rotation);
		color -= formList[closestForm].getColour(location, rotation);
		longevity--;

	}

	return color;

}
