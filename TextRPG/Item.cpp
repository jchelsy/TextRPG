/*  Source Code for Item Class  */

/*  Header Libary Import(s)  */
/*  =======================  */
#include "Item.h"  // Item Class


/*  Constructors  */
Item::Item()
{  // Default

}

Item::Item(std::string name, std::string type, std::string eff, int dura)
{
	setName(name);
	setType(type);

	if (eff != "") setEffect(eff);
	if (dura != NULL) setDurability(dura);
}


/*  Method(s)  */
void Item::Stats()
{
	// Item WITHOUT durability
	if (getDurability() == 101) {
		std::cout << "\t\t*** " << getName() << " ***" << std::endl;
	}
	// Item WITH durability (0-100)
	else {
		std::cout << "\t\t*** " << getName() << " [" << getDurability() << "%]" << " ***" << std::endl;
	}
	std::cout << "Item Type  : " << getType() << std::endl;
	std::cout << "Sp. Effect : " << getEffect() << std::endl;
}