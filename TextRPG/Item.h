/*  Header File for Item Class  */

#pragma once

/*  Header Libary Import(s)  */
/*  =======================  */
#include "Equipment.h"  // Equipment Class

/*  Equipment Class  */
class Item : public Equipment
{
public:
	// Constructors
	Item();
	Item(std::string, std::string, std::string, int);

	// Method(s)
	void Stats();
};