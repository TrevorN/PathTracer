#ifndef C_RAY
#define C_RAY
#include "Vector3.hpp"
#include "Scene.hpp"
#include "Colour.hpp"

class Scene;

class Ray{

		Vector3 position, direction;
		int longevity;

	public:
		Ray();
		Ray(Vector3, Vector3, int);
		Colour fire(Scene*);
		Vector3 getPosition();
		Vector3 getDirection();
		int getLongeveity();
		
};

#endif
