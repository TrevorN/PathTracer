#ifndef C_CAMERA
#define C_CAMERA

#include "Vector3.hpp"
#include "Scene.hpp"
#include "Colour.hpp"
#include <atomic>

class Camera
{
		const Vector3 & location, rotation, up;
		const Scene & environment;
		double fustrumLen, focalLen, topWidth, blurRadius;
		int resX, resY, longevity;
		std::atomic<int> samplesTaken;
        Colour* image;
    public:
		Camera(const Scene&, const Vector3&, const Vector3&, const Vector3&, double, double, double, double, int, int, int);
		~Camera();
		void takeSample();
        void takeSamples(std::atomic<int>&);
        void capture(int, int);
		Colour* getImage();
};
#endif
