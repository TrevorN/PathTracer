#ifndef C_RAY
#include "Vector3.hpp"
#include "Scene.hpp"
class Ray{

		Vector3 position, direction;
		int color, longevity;
		Scene* scene;

	public:
		Ray();
		Ray(Vector3, Vector3, Scene*, int);
		int fire();
		
};

#endif
