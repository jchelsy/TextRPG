/*  Source Code for Armor Class  */

/*  Header Libary Import(s)  */
/*  =======================  */
#include "Armor.h"  // Armor Class


/*  Constructors  */
Armor::Armor()
{  // Default

	// Set all default fall-back variables
	// for the Armor object.

	// If another Constructor doesn't set
	// any of these variables specifically,
	// it defaults back to these set values.

	setDefense(NULL);
}

Armor::Armor(std::string name, std::string type, std::string eff, int prot, int dura)
{
	// Set variables for the Armor object
	setName(name);
	setType(type);
	setDefense(prot);

	if (eff != "") setEffect(eff);
	if (dura != NULL) setDurability(dura);
}


/*  Method(s)  */
void Armor::Stats()
{
	// Name & Durability - i.e. *** Iron Helmet [100%] ***
	std::cout << "\t\t*** " << getName() << " [" << getDurability() << "%]" << " ***" << std::endl;
	// Type
	std::cout << "Armor Type     : " << getType() << std::endl;
	// Defense Rating (DEF Boost)
	std::cout << "Defense Rating : " << getDefense() << std::endl;
	// Sp. Effect
	std::cout << "Special Effect : " << getEffect() << std::endl;
}