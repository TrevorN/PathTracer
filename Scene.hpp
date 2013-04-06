#ifndef C_SCENE
#define C_SCENE

#include "Form.hpp"
#include "Colour.hpp"

class Scene
{

		int amountOfForms;
		int arraySize;
		Colour ambience;
		Form** conglomerateForms;
	public:
		Scene(Colour);
		int formQuantity();
		Colour getAmbience();
		void addForm(Form*);
		Form* getForm(int);
		~Scene();
};

#endif
