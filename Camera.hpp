#ifndef C_CAMERA
#define C_CAMERA

#include "Vector3.hpp"
#include "Scene.hpp"
#include "Colour.hpp"
#include <atomic>
#include <mutex>

class Camera
{
		Vector3 location, rotation, up;
		Scene* environment;
		double focalLen, topWidth;
		int resX, resY, longevity;
		std::atomic<int> samplesTaken;
        std::mutex imageMutex;
        Colour* image;
    public:
		Camera(Scene*, Vector3, Vector3, Vector3, double, double, int, int, int);
		~Camera();
		void takeSample();
        void takeSamples(std::atomic<int>&);
        void capture(int, int);
		Colour* getImage();
};
#endif
