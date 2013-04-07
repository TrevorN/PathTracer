#include "Scene.hpp"
Scene::Scene()
{

	amountOfForms = 0;
	conglomerateForms = 0;

}

Scene::Scene(Colour ambience)
{

	this->ambience = ambience;
	amountOfForms = 0;
	arraySize = 25;
	conglomerateForms = new Form*[arraySize];
}

int Scene::formQuantity(){

	return amountOfForms;

}

Form* Scene::getForm(int index)
{
	return conglomerateForms[index];
}

Colour Scene::getAmbience()
{
	return ambience;
}

void Scene::addForm(Form* newbie)
{
	if(amountOfForms + 1 > arraySize)
	{
		//Make the array bigger
		Form** tempArr = new Form*[arraySize * 2];
		for(int i = 0; i < amountOfForms; i++){

			tempArr[i] = conglomerateForms[i];

		}
		delete conglomerateForms;
		conglomerateForms = tempArr;
		arraySize *= 2;
		//Array resized!
	}

	conglomerateForms[amountOfForms++] = newbie;
}

Scene::~Scene()
{
	delete conglomerateForms;
}
