#include "Scene.hpp"

Scene::Scene()
{

}

int Scene::formQuantity(){

	return amountofForms;

}

Form* Scene::getForms(){

	return conglomerateForms;

}

Color Scene::getAmbience(){

	return ambience;

}
