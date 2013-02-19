#include "Vector3.hpp"
#include <iostream>

using namespace std;

int main()
{
	Vector3 myVec = Vector3(1.0, 0.0, 0.0);
	Vector3 youVec = Vector3(0.0, 1.0, 0.0);
	Vector3 theVec = myVec.crossProduct(youVec);
	cout << "theVec->x: " << theVec.getX() << endl;
	cout << "theVec->y: " << theVec.getY() << endl;
	cout << "theVec->z: " << theVec.getZ() << endl;
	return 0;
}
