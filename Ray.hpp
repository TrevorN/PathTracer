#ifndef C_RAY
#define C_RAY

#include "Vector3.hpp"
#include "Scene.hpp"

class Ray{

		Vector3 location, rotation;
		int color, longevity;
		Scene* scene;

	public:
		Ray();
		Ray(Vector3, Vector3, Scene* scene, int);
		int fire();
		
};
#endif

