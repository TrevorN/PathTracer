#ifndef C_VECTOR3
#define C_VECTOR3

class Vector3{
		double x;
		double y;
		double z;
	public:
		Vector3(double, double, double);//Done
		Vector3();
		double getMagnitude();//Done
		Vector3 normalize();//Done
		Vector3 crossProduct(Vector3);//Done
		int dotProduct(Vector3);//Done
		Vector3 projectOnto(Vector3);//Done
		Vector3 operator*(double);
		Vector3 operator+(Vector3);
		Vector3 operator-(Vector3);
		double getX();//Done
		double getY();//Done
		double getZ();//Done
};

#endif
