/*  Main Source Code File  */

/*  Header Library Imports  */
/*  ======================  */
#include <thread>		// Execution Thread Library
#include <cstdlib>		// C Standard General Utilities Library
#include <utility>		// Utility Library - pair(), make_pair(), etc.
#include <sstream>		// Typedef Input/Output Library

#include "Character.h"	// Character Class
#include "Functions.h"	// Import Useful Methods



int main() {
	// Initialize local variables
	std::string strChoice;  // userChoice
	bool boolChoice;
	std::string Name;
	std::string Class;



	return 0;
}


/*

- Make MP (Mana) calculated as a double (MP is currently an int)

- Set more realistic attack damage variations between classes in Character::setDamage()

- Change item names for clarification
- i.e. Iron Sword (1H) --> Iron Broadsword (1H)

- Add a Misc. Shop to the Shopping() method

- Add a coin amount to enemies for collection upon death (similar to enemy experience)

- Decide upon a reasonable starting currency amount for players
- i.e. Enough to buy some items, but not a full equip

- Alter the getDamage() algorithm to incorporate a proper damage decrease for "dodging"
  a full blow with agility (include an algorithm-based random chance for attack miss)

- Add another battle after the first one

- Overhaul the Battle() method to generalize it for any type & number of enemies.

*/