#include "Ray.hpp"

Ray::Ray(Vector3 location, Vector3 focus, Scene scene, int longevity)
{

	this->rotation = focus - location;
	this->rotation = this->rotation.normalize();;
	this->location = location;
	this->scene = scene;
	this->longevity = longevity;

}

void Ray::fire(){

	while(longevity > 0){

		int corpusSize = Scene->formQuantity();
		int dist = 0;
		int tmpdist = 0;
		int closestForm = -1;
		Form[] formList = Scene->getForms();
		for(int i = 0; i < length; i++){

			if((tmpdist = Form[i].collideWith(position, direction))!=-1){
				if(tmpdist < dist){
					
					closestform = i;
					dist = tmpdist;

				}
			}

		}

		if(closestform == -1){

			color = Scene.getAmbience();
			break;

		}

		Ray refl = Form[closestform].reflect(position, direction);
		color -= Form[closestform].getColor(position, direction);
		longevity--;

	}

	return color;

}
