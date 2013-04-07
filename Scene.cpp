#include "Scene.hpp"
#include <cstdlib>
#include <cstring>

Scene::Scene()
{

	amountofForms = 0;
	conglomerateForms = 0;

}

Scene::Scene(Colour ambience)
{

	amountofForms = 0;
	conglomerateForms = 0;
	this->ambience = ambience;

}

Scene::~Scene()
{

	delete conglomerateForms;

}

int Scene::formQuantity(){

	return amountofForms;

}

void Scene::addForm(Form* f){

	Form** tmpForms = new Form*[amountofForms+1];
	for(int i = 0; i < amountofForms; i++){

		tmpForms[i] = conglomerateForms[i];

	}
	delete conglomerateForms;
	conglomerateForms = tmpForms;
	conglomerateForms[amountofForms++] = f;

}

Form** Scene::getForms(){

	return conglomerateForms;

}


Colour Scene::getAmbience(){

	return ambience;

}
