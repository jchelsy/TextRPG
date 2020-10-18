/*  Source Code for Equipment Class  */

/*  Header Libary Import(s)  */
/*  =======================  */
#include "Equipment.h"  // Equipment Class

/*  Constructor(s)  */
Equipment::Equipment()
{  // Default

	// Set all default fall-back variables
	// for the Equipment object.

	// If another Constructor doesn't set
	// any of these variables specifically,
	// it defaults back to these set values.

	setName("");
	setType("");
	setElement("N/A");
	setEffect("N/A");
	setDurability(100);
}

Equipment::Equipment(std::string name, std::string type, std::string elem, std::string eff, int dura)
{
	// Set variables for the Equipment object
	setName(name);
	setType(type);

	if (eff != "") setEffect(eff);
	if (elem != "") setElement(elem);
	if (dura != NULL) setDurability(dura);
}


/*  Encapsulation Methods  */
// NAME
void Equipment::setName(std::string name)
{
	NAME = name;
}
std::string Equipment::getName()
{
	return NAME;
}

// TYPE
void Equipment::setType(std::string type)
{
	TYPE = type;
}
std::string Equipment::getType()
{
	return TYPE;
}

// ELEMENT
void Equipment::setElement(std::string elem)
{
	ELEMENT = elem;
}
std::string Equipment::getElement()
{
	return ELEMENT;
}

// EFFECT
void Equipment::setEffect(std::string eff)
{
	EFFECT = eff;
}
std::string Equipment::getEffect()
{
	return EFFECT;
}

// DURABILITY
void Equipment::setDurability(int dura)
{
	DURABILITY = dura;
}
int Equipment::getDurability()
{
	return DURABILITY;
}

// POWER
void Equipment::setPower(int dmg)
{
	POWER = dmg;
}
int Equipment::getPower()
{
	return POWER;
}

// PROTECTION
void Equipment::setDefense(int prot)
{
	PROTECTION = prot;
}
int Equipment::getDefense()
{
	return PROTECTION;
}