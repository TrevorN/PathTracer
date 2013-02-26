#include "Ray.hpp"

Ray::Ray(Vector3 location, Vector3 direction, Scene scene)
{

	this.direction = direction.normalize;
	this.position = position;
	this.scene = scene;
	this.color = color;
	life = 15;

}

Ray::Ray(Vector3 location, Vector3 direction, Scene scene, int life)
{

	this.direction = direction.normalize();
	this.position = position;
	this.scene = scene;
	this.color = color;
	this.life = life;

}

void Ray::fire(){

	while(life){

		int length = Scene.formQuantity();
		int dist = 0;
		int tmpdist = 0;
		int closestform = -1;
		Form[] formlist = Scene->getForms();
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
