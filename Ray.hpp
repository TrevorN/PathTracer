#include "Vector3.hpp"
class Ray{

		Vector3 location;
		Vector3 direction;
		int color = 0;
		Scene* scene;
		int longevity = 0;

	public:
		Ray(Vector3, Vector3, Scene* scene);
		Ray(Vector3, Vector3, Scene* scene, int);
		int fire();
		
}
