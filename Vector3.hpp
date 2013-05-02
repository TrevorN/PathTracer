#ifndef C_VECTOR3
#define C_VECTOR3

class Vector3{
		double x;
		double y;
		double z;
	public:
		Vector3(double, double, double);
		Vector3();
		double getMagnitude();
		Vector3 normalize();
		Vector3 crossProduct(Vector3);
		double angleBetween(Vector3);
		double dotProduct(Vector3);
		Vector3 projectOnto(Vector3);
		Vector3 operator*(double);
		Vector3 operator+(Vector3);
		Vector3 operator-(Vector3);
		bool operator==(const Vector3&) const;
		bool operator!=(const Vector3&) const;
		bool signEqual(const Vector3&) const;
		double getX() const;
		double getY() const;
		double getZ() const;
};

#endif
