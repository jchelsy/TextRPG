/*  Source Code for Weapon Class  */

/*  Header Libary Import(s)  */
/*  =======================  */
#include "Weapon.h"  // Weapon Class


/*  Constructors  */
Weapon::Weapon()
{  // Default
	setPower(NULL);
}

Weapon::Weapon(std::string name, std::string type, std::string elem, std::string eff, int baseDMG, int dura)
{
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
	std::cout << "\t\t*** " << getName() << " [" << getDurability() << "%]" << " ***" << std::endl;
	std::cout << "Weapon Type    : " << getType() << std::endl;
	std::cout << "Weapon Damage  : " << getPower() << std::endl;
	std::cout << "Weapon Element : " << getElement() << std::endl;
	std::cout << "Special Effect : " << getEffect() << std::endl;
}