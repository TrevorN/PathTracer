#include "Plane.hpp"

Plane::Plane(Vector3 location, Vector3 up, Material* material)
{
	this->location = location;
	this->up = up.normalize();
	this->material = material;
    this->distance = 0;
}

double Plane::getDistance(Ray* ray)
{
	Vector3 rayPosition = ray->getPosition();
	Vector3 rayDirection = ray->getDirection();

    rayPosition = rayPosition + rayDirection * .1;
    
    distance = up.dotProduct(location - rayPosition) / up.dotProduct(rayDirection);

    Vector3 stoPos = rayPosition + (rayDirection.normalize() * distance);

    if(rayDirection.getY() * (stoPos - rayPosition).getY() < 0)
    {
        return -1;
    }

    return distance;
}

void Plane::collideWith(Ray* ray)
{

    Vector3 rayPosition = ray->getPosition();
    Vector3 rayDirection = ray->getDirection();
    Vector3 newPosition = rayPosition + (rayDirection.normalize() * distance);
    Vector3 newDirection = material->bounce(rayDirection, up);

    ray->setPosition(newPosition);
    ray->setDirection(newDirection);
}

Colour Plane::getColour(Ray* ray)
{
    return material->getColour(ray->getDirection(), ray->getPosition());
}

Plane::~Plane()
{
    delete material;
}
