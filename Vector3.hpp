#ifndef C_VECTOR3
#define C_VECTOR3

class Vector3{
        double comps[3];
    public:
        Vector3(double = 0, double = 0, double = 0);
        double getMagnitude() const;
        Vector3 normalize() const;
        Vector3 crossProduct(const Vector3&) const;
        double angleBetween(const Vector3&) const;
        double dotProduct(const Vector3&) const;
        Vector3 projectOnto(const Vector3&) const;
        Vector3 operator*(double) const;
        Vector3 operator+(const Vector3&) const;
        Vector3 operator-(const Vector3&) const;
        bool operator==(const Vector3&) const;
        bool operator!=(const Vector3&) const;
        bool signEqual(const Vector3&) const;
        double getX() const;
        double getY() const;
        double getZ() const;
};

#endif
