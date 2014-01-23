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
		Scene();
		Scene(Colour);
		~Scene();
		int formQuantity() const;
		Colour getAmbience() const;
		void addForm(Form*);
		Form* getForm(int) const;
};

#endif
