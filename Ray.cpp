#include "Ray.hpp"

Ray::Ray(Vector3 location, Vector3 direction, Scene scene)
{

	this.direction = direction.normalize;
	this.position = position;
	this.scene = scene;
	this.color = color;
	longevity = 15;

}

Ray::Ray(Vector3 location, Vector3 direction, Scene scene, int longevity)
{

	this.direction = direction.normalize();
	this.position = position;
	this.scene = scene;
	this.color = color;
	this.longevity = longevity;

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
		color -= Form[closestform].getColor(&position, &direction);
		Form[closestform].reflect(&position, &direction);

		life--;

	}

	return color;

}
