#ifndef C_RAY
#define C_RAY

#include "Vector3.hpp"
#include "Scene.hpp"

class Ray{

		Vector3 location, rotation;
		int color, longevity;
		Scene* sceneRef;

	public:
		Ray();
		Ray(Vector3, Vector3, Scene* sceneRef, int);
		int fire();
		
};

#endif
