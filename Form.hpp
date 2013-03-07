#ifndef C_FORM
#define C_FORM

#include "Vector3.hpp"

class Form{

		int colour;	

	public:
		Form();
		int collideWith(Vector3, Vector3);
		Vector3 reflect(Vector3, Vector3);
		int getColour(Vector3, Vector3);

};

#endif
