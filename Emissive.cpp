#include "Emissive.hpp"
#include "Colour.hpp"
#include <cmath>
#include <cstdlib>

Emissive::Emissive(Colour colour)
{
    this->colour = colour;
}

Vector3 Emissive::bounce(Vector3 rayIn, Vector3 surfaceNormal)
{
    return Vector3(0,0,0);
}

Colour Emissive::getColour(Vector3 rayIn, Vector3 surfaceNormal)
{
    return colour;
}
