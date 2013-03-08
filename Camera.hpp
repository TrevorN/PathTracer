#ifndef C_CAMERA
#define C_CAMERA

#include "Vector3.hpp"
#include "Scene.hpp"

class Camera
{
		Vector3 location, rotation, up;
		Scene environment;
		double focalLen, topWidth;
		int resX, resY, aaDepth, samplesTaken, longevity;
		bool AA;
		char * image;

	public:
		Camera(Scene, Vector3, Vector3, Vector3, double, double, int, int, int);
		Camera(Scene, Vector3, Vector3, Vector3, double, double, int, int, int, int);
		~Camera();
		void takeSample();
		char * getImage();
};
#endif
