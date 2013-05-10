#ifndef C_RAY
#define C_RAY

#include "Vector3.hpp"
#include "Scene.hpp"
#include "Colour.hpp"

class Scene;

class Ray{

		Vector3 position, direction;
		Colour colour;
		int longevity;

	public:
		Ray();
		Ray(Vector3, Vector3, int);
		Colour fire(Scene*);
		void setLongevity(int);
		void setPosition(Vector3);
		Vector3 getPosition();
		void setDirection(Vector3);
		Vector3 getDirection();
		int getLongeveity();
		
};

#endif
