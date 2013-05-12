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
        Triangle(const Triangle&);
        Triangle& operator=(Triangle);
        double getDistance(Ray*);
        void collideWith(Ray*);
        Colour getColour(Ray*);
};

#endif
