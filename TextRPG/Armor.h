/*  Header File for Armor Class  */

#pragma once

/*  Header Libary Import(s)  */
/*  =======================  */
#include "Equipment.h"  // Equipment Class


/*  Armor Class  */
class Armor : public Equipment
{
public:
	// Constructors
	Armor();
	Armor(std::string, std::string, std::string, int, int);

	// Method(s)
	void Stats();
};