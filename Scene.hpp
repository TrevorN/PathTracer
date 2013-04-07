#ifndef C_SCENE
#define C_SCENE

#include "Form.hpp"
#include "Colour.hpp"

class Form;

class Scene
{

		int amountOfForms;
		int arraySize;
		Colour ambience;
		Form** conglomerateForms;
	public:
		Scene();
		Scene(Colour);
		~Scene();
		int formQuantity();
		Colour getAmbience();
		void addForm(Form*);
		Form* getForm(int);
};

#endif
