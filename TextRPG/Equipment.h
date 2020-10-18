/*  Header File for Equipment Class  */

#pragma once

/*  Header Libary Import(s)  */
/*  =======================  */
#include "Functions.h"
#include "Choices.h"


/*  Equipment Class  */
class Equipment
{
public:
	// Constructors
	Equipment();
	Equipment(std::string, std::string, std::string, std::string, int);

	// Encapsulation Methods
	void setName(std::string);
	std::string getName();
	void setType(std::string);
	std::string getType();
	void setElement(std::string);
	std::string getElement();
	void setEffect(std::string);
	std::string getEffect();
	void setDurability(int);
	int getDurability();

	void setPower(int);
	int getPower();

	void setDefense(int);
	int getDefense();

private:
	// Private variables
	std::string NAME;		// Item Name
	std::string TYPE;		// Equipment Classification
	std::string ELEMENT;	// Magic Element / Non-Elemental Type
	std::string EFFECT;		// Special Effect
	int DURABILITY;			// Durability (0-100%)

	int POWER;				// Base Damage
	int PROTECTION;			// Defense Value
};