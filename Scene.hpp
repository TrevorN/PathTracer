#ifndef C_SCENE
#define C_SCENE

#include "Form.hpp"
#include "Colour.hpp"
#include <vector>
#include <utility>

class Scene
{
		Colour ambience;
		std::vector<Form*> conglomerateForms;
	public:
		Scene(Colour = Colour(255, 255, 255));
		int formQuantity() const;
		Colour getAmbience() const;
		void addForm(Form*);
		Form* getForm(int) const;
		void generateBVH();
};

#endif
