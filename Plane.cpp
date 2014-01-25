#include "Plane.hpp"

Plane::Plane(Vector3 location, Vector3 up, Material* material)
{
	this->location = location;
	this->up = up.normalize();
	this->material = material;
}

double Plane::getDistance(Ray* ray) const
{
	Vector3 rayPosition = ray->getPosition();
	Vector3 rayDirection = ray->getDirection();
    
    //rayPosition = rayPosition + rayDirection * .1;
    
    double distance = up.dotProduct(location - rayPosition) / up.dotProduct(rayDirection);

    if(distance < .001)
    {
        return -1;
    }

    return distance;
}

void Plane::collideWith(Ray* ray) const
{
    double distance = getDistance(ray);
    Vector3 rayPosition = ray->getPosition();
    Vector3 rayDirection = ray->getDirection();
    Vector3 newPosition = rayPosition + (rayDirection.normalize() * distance);
    Vector3 newDirection = material->bounce(rayDirection, up);

    ray->setPosition(newPosition);
    ray->setDirection(newDirection);
}

Colour Plane::getColour(Ray* ray) const
{
    return material->getColour(ray->getDirection(), ray->getPosition());
}

Plane::~Plane()
{
    delete material;
}
