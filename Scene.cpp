#include "Scene.hpp"

Scene::Scene(Colour ambience) : ambience(ambience)
{
}

int Scene::formQuantity() const
{
	return conglomerateForms.size();
}

Colour Scene::getAmbience() const
{
	return ambience;
}

Form* Scene::getForm(int index) const
{
	return conglomerateForms[index];
}

void Scene::addForm(Form *newbie)
{
	conglomerateForms.push_back(newbie);
}

void Scene::generateBVH()
{
	
}