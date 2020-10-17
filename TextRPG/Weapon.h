/*  Header File for Weapon Class  */

#pragma once

/*  Header Libary Import(s)  */
/*  =======================  */
#include "Equipment.h"  // Equipment Class

/*  Weapon Class  */
class Weapon : public Equipment
{
public:
	// Constructors
	Weapon();
	Weapon(std::string, std::string, std::string, std::string, int, int);

	// Method(s)
	void Stats();
};