#include "Scene.hpp"

Scene::Scene()
{

	amountofForms = 0;

}

Scene::Scene(Colour ambience)
{

	amountofForms = 0;
	this->ambience = ambience;

}

int Scene::formQuantity(){

	return amountofForms;

}

Form* Scene::getForms(){

	return conglomerateForms;

}

Colour Scene::getAmbience(){

	return ambience;

}
