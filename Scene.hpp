#ifndef C_SCENE
#define C_SCENE

#include "Form.hpp"
#include "Colour.hpp"

class Scene
{

		int amountofForms;
		Colour ambience;
		Form* conglomerateForms;
	public:
		Scene();
		Scene(Colour);
		int formQuantity();
		Colour getAmbience();
		Form* getForms();
};

#endif
