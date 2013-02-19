#include <Vector3.hpp>
#include <stdio>

int Main(String[] args)
{
	Vector3 myVec = new Vector3(1, 0, 0);
	Vector3 youVec = new Vector3(0, 1, 0);
	Vector3 theVec = myVec->crossProduct(youVec);
	cout << "theVec->x: " << theVec->getX() << endl;
	cout << "theVec->y: " << theVec->getY() << endl;
	cout << "theVec->z: " << theVec->getZ() << endl;
	return 0;
}
