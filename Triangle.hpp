#ifndef C_TRIANGLE
#define C_TRIANGLE

#include "Ray.hpp"
#include "Vector3.hpp"

class Triangle : public Form
{
        Vector3 points[3];
    public:
        Triangle(Vector3, Vector3, Vector3, Material*);
        ~Triangle();
        double getDistance(Ray*) const;
        void collideWith(Ray*) const;
        Colour getColour(Ray*) const;
};

#endif
