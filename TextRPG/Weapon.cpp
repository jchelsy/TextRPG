/*  Source Code for Weapon Class  */

/*  Header Libary Import(s)  */
/*  =======================  */
#include "Weapon.h"  // Weapon Class


/*  Constructor(s)  */
Weapon::Weapon()
{  // Default

	// Set all default fall-back variables
	// for the Weapon object.

	// If another Constructor doesn't set
	// any of these variables specifically,
	// it defaults back to these set values.

	setPower(NULL);
}

Weapon::Weapon(std::string name, std::string type, std::string elem, std::string eff, int baseDMG, int dura)
{
	// Set variables for the Weapon object
	setName(name);
	setType(type);
	setPower(baseDMG);

	if (eff != "") setEffect(eff);
	if (elem != "") setElement(elem);
	if (dura != NULL) setDurability(dura);
}


/*  Method(s)  */
void Weapon::Stats()
{
	// Name & Durability - i.e. *** Iron Sword [100%] ***
	std::cout << "\t\t*** " << getName() << " [" << getDurability() << "%]" << " ***" << std::endl;
	// Type
	std::cout << "Weapon Type    : " << getType() << std::endl;
	// Damage
	std::cout << "Weapon Damage  : " << getPower() << std::endl;
	// Element
	std::cout << "Weapon Element : " << getElement() << std::endl;
	// Sp. Effect
	std::cout << "Special Effect : " << getEffect() << std::endl;
}