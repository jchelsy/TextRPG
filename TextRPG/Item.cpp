/*  Source Code for Item Class  */

/*  Header Libary Import(s)  */
/*  =======================  */
#include "Item.h"  // Item Class


/*  Constructor(s)  */
Item::Item()
{  // Default

}

Item::Item(std::string name, std::string type, std::string eff, int dura)
{
	// Set variables for the Item object
	setName(name);
	setType(type);

	if (eff != "") setEffect(eff);
	if (dura != NULL) setDurability(dura);
}


/*  Method(s)  */
void Item::Stats()
{
	// WITHOUT Durability (-1 >= DURABILITY >= 101)
	if (getDurability() > 100 || getDurability() < 0) std::cout << "\t\t*** " << getName() << " ***" << std::endl;

	// WITH Durability (0-100)
	else std::cout << "\t\t*** " << getName() << " [" << getDurability() << "%]" << " ***" << std::endl;

	// Type
	std::cout << "Item Type  : " << getType() << std::endl;
	// Sp. Effect
	std::cout << "Sp. Effect : " << getEffect() << std::endl;
}