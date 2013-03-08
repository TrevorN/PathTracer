#ifndef C_FORM
#define C_FORM

#include "Vector3.hpp"

class Form{

		int colour;	

	public:

		virtual int collideWith(Vector3, Vector3) = 0;
		virtual Vector3 reflect(Vector3, Vector3) = 0;
		virtual int getColour(Vector3, Vector3)= 0;

};

#endif
