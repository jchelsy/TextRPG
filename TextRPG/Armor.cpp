/*  Source Code for Armor Class  */

/*  Header Libary Import(s)  */
/*  =======================  */
#include "Armor.h"  // Armor Class


/*  Constructors  */
Armor::Armor()
{  // Default
	setDefense(NULL);
}

Armor::Armor(std::string name, std::string type, std::string eff, int prot, int dura)
{
	setName(name);
	setType(type);
	setDefense(prot);

	if (eff != "") setEffect(eff);
	if (dura != NULL) setDurability(dura);
}


/*  Method(s)  */
void Armor::Stats()
{
	std::cout << "\t\t*** " << getName() << " [" << getDurability() << "%]" << " ***" << std::endl;
	std::cout << "Armor Type     : " << getType() << std::endl;
	std::cout << "Defense Rating : " << getDefense() << std::endl;
	std::cout << "Special Effect : " << getEffect() << std::endl;
}