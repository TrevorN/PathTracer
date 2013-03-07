#ifndef C_SCENE
#define C_SCENE

#include "Form.hpp"

class Scene
{

		int amountofForms;
		int ambience;
		Form* conglomerateForms;
	public:
		Scene();
		int formQuantity();
		int getAmbience();
		Form* getForms();
};

#endif
