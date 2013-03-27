#ifndef C_SCENE
#define C_SCENE

#include "Form.hpp"

class Scene
{

		int amountofForms;
		Color ambience;
		Form* conglomerateForms;
	public:
		Scene();
		int formQuantity();
		Color getAmbience();
		Form* getForms();
};

#endif
