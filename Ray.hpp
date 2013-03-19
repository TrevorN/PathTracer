#ifndef C_RAY
#include "Vector3.hpp"
#include "Scene.hpp"
#include "Colour.hpp"
class Ray{

		Vector3 position, direction;
		int longevity;
		Scene* scene;

	public:
		Ray();
		Ray(Vector3, Vector3, Scene*, int);
		Colour fire();
		
};

#endif
