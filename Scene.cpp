#include "Scene.hpp"
#include "Colour.hpp"

Scene::Scene(Colour ambience)
{
	amountOfForms = 0;
	arraySize = 25;
	conglomerateForms = new Form*[arraySize];
	this->ambience = ambience;
}

int Scene::formQuantity():w
{
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

void Scene::addForm(Form newbie)
{
	if(amountOfForms + 1 > arraySize)
	{
		//Make the array bigger
		Form** tempArr = new Form*[arraySize * 2];
		::memcpy(tempArr, conglomerateForms, arraySize * sizeof(Form*));
		delete [] conglomerateForms;
		conglomerateForms = tempArr;
		arraySize *= 2;
		//Array resized!
	}

	conglomerateForms[amountOfForms++] = newbie;
}

Scene::~Scene()
{
	delete [] conglomerateForms;
}
