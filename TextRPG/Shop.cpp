/*  'Shop' Source Code  */

/*  Header Libary Import(s)  */
/*  =======================  */
#include "Character.h"
#include "Shop.h"
#include "Events.h"


/*  ===================  */
/*  === Shop Method ===  */
/*  ===================  */
Character Shop(std::string type, Character player, std::vector<std::pair<Equipment, std::pair<int, int>>> classShop, std::vector<std::pair<Equipment, std::pair<int, int>>> miscShop)
{
	// Initialize variables
	int numAmount;
	int numChoice;
	std::string strChoice;
	bool boolChoice;
	bool isNum = false;
	std::vector<int> itemCost;

	// Create a separator
	int length = 14 + (int)type.length();
	std::string separator(length, '=');

	do
	{
		// Title (Class Goods)
		std::cout << "\n\n\t\t" << separator << std::endl;
		std::cout << "\t\t*** " << type << " Goods ***" << std::endl;
		std::cout << "\t\t" << separator << std::endl;

		// Create a typedef vector for both shop items
		typedef std::vector<std::pair<Equipment, std::pair<int, int>>> CLASS;
		typedef std::vector<std::pair<Equipment, std::pair<int, int>>> MISC;

		// Create iterators for both shop vectors with the typedef vectors
		CLASS::iterator it = classShop.begin();
		MISC::iterator in = miscShop.begin();

		// Equipment title
		std::cout << "\n  Equipment:" << std::endl;

		/*  'spaceCount' and 'spaceCount2' are used for formatting everything properly  */
		std::string spaceCount;
		std::string spaceCount2;

		// Loop for the amount of classShop vector items
		for (it; it != classShop.end(); ++it)
		{
			// Reset the spaceCount variables to its default
			spaceCount = "                        ";
			spaceCount2 = "                    ";

			// Output the item # in the shop
			std::cout << "\t" << it->second.first << ") ";

			// Loop for the # of characters of the current index's item name length
			for (unsigned counter = 0; counter < it->first.getName().length(); ++counter)
			{
				// If 'spaceCount' still has content (spaces)
				if (!spaceCount.empty())
					// Remove the last character in the string(one of the spaces)
					spaceCount.pop_back();

				// if 'spaceCount2' still has content (spaces)
				if (!spaceCount2.empty())
					// Remove the last character in the string (one of the spaces)
					spaceCount2.pop_back();
			}

			// If the Equipment is a Weapon:
			// #############################
			if (it->first.getType() == "M-Sword" || it->first.getType() == "O-Sword" ||
				it->first.getType() == "M-Dagger" || it->first.getType() == "O-Dagger" ||
				it->first.getType() == "M-Wand" || it->first.getType() == "O-Wand" ||
				it->first.getType() == "1H-Sword" || it->first.getType() == "1H-Wand" ||
				it->first.getType() == "M-Crossbow" || it->first.getType() == "O-Crossbow" ||
				it->first.getType() == "Bow")
			{
				// If the Equipment is a mainhand weapon (object type string begins with "M-")
				if (it->first.getType().rfind("M-", 0) == 0)
					// Output the item info to the shop details
					std::cout << it->first.getName() << spaceCount << "[" << it->first.getDurability() << "%]\t-  " << "(DMG: " << it->first.getPower() << ")" << "\tCost: { " << GetFormattedItemCost(it->second.second) << " }" << std::endl;

				// If the Equipment is an offhand weapon (object type string begins with "O-")
				if (it->first.getType().rfind("O-", 0) == 0)
					// Output the item info to the shop details
					std::cout << it->first.getName() << "(OH)" << spaceCount2 << "[" << it->first.getDurability() << "%]\t-  " << "(DMG: " << it->first.getPower() << ")" << "\tCost: { " << GetFormattedItemCost(it->second.second) << " }" << std::endl;

				// If the Equipment is a one-handed weapon (object type string begins with "1H-" or is type "Bow")
				if (it->first.getType().rfind("1H-", 0) == 0 || it->first.getType() == "Bow")
					// Output the item info to the shop details
					std::cout << it->first.getName() << "(1H)" << spaceCount2 << "[" << it->first.getDurability() << "%]\t-  " << "(DMG: " << it->first.getPower() << ")" << "\tCost: { " << GetFormattedItemCost(it->second.second) << " }" << std::endl;
			}


			// If the Equipment is a Shield:
			// #############################
			else if (it->first.getType() == "Shield")
				// Output the item info to the shop details
				std::cout << it->first.getName() << "(OH)" << spaceCount2 << "[" << it->first.getDurability() << "%]\t-  " << "[DEF+" << it->first.getDefense() << "]" << "\tCost: { " << GetFormattedItemCost(it->second.second) << " }" << std::endl;


			// If the Equipment is Armor:
			// #############################
			else if (it->first.getType() == "Headpiece" || it->first.getType() == "Chestpiece" || it->first.getType() == "Leggings" || it->first.getType() == "Boots")
				// Output the item info to the shop details
				std::cout << it->first.getName() << spaceCount << "[" << it->first.getDurability() << "%]\t-  " << "[DEF+" << it->first.getDefense() << "]" << "\tCost: { " << GetFormattedItemCost(it->second.second) << " }" << std::endl;
		}

		////////////////////////////////////////
		////////////////////////////////////////

		// Output Title (Misc. Goods)
		std::cout << "\n\n\t\t===================" << std::endl;
		std::cout << "\t\t*** Misc. Goods ***" << std::endl;
		std::cout << "\t\t===================" << std::endl;

		/* Potions Section */
		std::cout << "\n  Potions:" << std::endl;

		// Set the Equipment iterator to the last index
		it = classShop.end() - 1;

		// Set integer 'counter' to the item # of the last item in the Class Shop vector.
		int counter = it->second.first;

		// Loop for the amount of 'miscShop' vector items
		for (in; in != miscShop.end(); ++in)
		{
			// Add one to the counter
			++counter;

			// Set the first value in the pair of the second vector item (second.first)
			// to the # one higher than previous (counter)
			in->second.first = counter;


			/*  This if/else ensures proper formatting. When the item #
				is less than 10, it adds an extra space to keep it equal
			*/

			// If this number is less than 10, output the item #'s output (with a space)
			if (in->second.first < 10) std::cout << "\t " << in->second.first << ") ";
			// Otherwise (if it's over 10), output the item #'s output (without a space)
			else std::cout << "\t" << in->second.first << ") ";


			// If the miscShop item is a potion
			if (in->first.getType() == "Potion")
				// Output the item info to the shop details
				std::cout << in->first.getName() << " [" << in->first.getEffect() << "]" << "\tCost: { " << GetFormattedItemCost(in->second.second) << " }" << std::endl;
		}

		// Set the vector<int> 'itemCost' to the calculated
		// gold (index 0), silver (index 1), & copper (index 2)
		// values of the player's currency amount
		itemCost = GetItemCost(player.getCurrency());

		// Output the player's total amount of gold, silver, and copper
		std::cout << "\n\t\t=======================================" << std::endl;
		std::cout << "\t\t   Your Coin Pouch: " << itemCost[0] << "g - " << itemCost[1] << "s - " << itemCost[2] << "c   " << std::endl;
		std::cout << "\t\t=======================================" << std::endl;

		// Clear the vector<int> 'itemCost' to go back to default
		//   (So that when it is set again, it will set the values to index 0, 1, & 2 -- not 3, 4, & 5)
		itemCost.clear();

		// Ask the user for anything else.
		std::cout << "\n  Shopkeep: Anythin' interest ya?" << std::endl;

		// When goto restartShop: is called, it goes to this location and plays from here
		restartShop:

		// Ask user to input item # to buy
		std::cout << "\n  Please say an item number to buy or 'exit' to leave.";
		std::cout << std::endl;

		// When goto tryAgain: is called, it goes to this location and plays from here
		tryAgain:

		// Get user input
		strChoice = getInput("  >>>");

		// Set integer 'numChoice' as 0
		numChoice = 0;

		// Determine if the string 'strChoice' contains an integer or a string
		// If it IS an integer, set boolean 'isNum' to the returned value true
		// If it ISN't, set boolean 'isNum' to the returned value false
		isNum = IsNumber(strChoice);

		// Set iterator 'it' back to the beginning index of vector 'classShop'
		it = classShop.begin();
		// Set iterator 'in' back to the beginning index of vector 'miscShop'
		in = miscShop.begin();

		// If boolean 'isNum' is true (if the user inputted a number, to specify which item # to buy)
		if (isNum == true)
		{
			// Convert the string 'strChoice' to an integer and set it to integer 'numChoice'
			numChoice = stoi(strChoice);

			// Loop the # of times of the amount of classShop vector items
			for (it = classShop.begin();it != classShop.end();++it)
			{
				// If the user inputted number is equivalent to the matching Class Shop index's item # value
				if (numChoice == it->second.first)
				{
					// If the player has enough currency to afford the item
					if (player.getCurrency() >= it->second.second)
					{
						// Subtract the item's cost from the player's currency
						player.setCurrency(player.getCurrency() - it->second.second);

						// Set the item's gold (index 0), silver (index 1), and copper (index 2) cost
						// to vector<int> 'itemCost'
						itemCost = GetItemCost(it->second.second);
						// Output item purchase notification with the amount the item was purchased for
						std::cout << "\n  You bought a(n) " << it->first.getName() << " for " <<
							itemCost[0] << " gold, " << itemCost[1] << " silver, and " <<
							itemCost[2] << " copper pieces." << std::endl;

						// If the Equipment purchased was a mainhand weapon
						if (it->first.getType() == "M-Sword" || it->first.getType() == "M-Dagger" ||
							it->first.getType() == "M-Wand" || it->first.getType() == "M-Crossbow")
						{
							// If there are no held weapon conflictions
							//   (If there is no mainhand or one-handed weapon currently equipped --
							//      offhand weapon doesn't matter, since mainhand can be equipped WITH offhand)
							if (player.mainHand == NULL && player.oneHanded == NULL)
							{
								// Equip the user-chosen Weapon object
								player.equipWeapon(it->first);

								// Set the public Equipment* pointer 'mainHand'
								// to the reference of the chosen Equipment object.
								//   (for usage in determining whether or not a mainhand
								//    weapon is currently equipped or not)
								player.mainHand = &it->first;

								// Output item equipped notification
								std::cout << "\n  You have equipped the " << it->first.getName() << "!";

								// Go to the location of 'shopAgain:' and play from there (exits the loop)
								goto shopAgain;
							}

							// Otherwise (If there IS a held weapon confliction)...
							else {
								// If the player currently has a mainhand Weapon object equipped
								if (player.mainHand != NULL && player.oneHanded == NULL)
								{
									// Ask the player whether or not to equip the new Weapon just purchased
									std::cout << "  You currently have your " << player.mainHand->getName() << " equipped. " <<
										"Would you like to equip your new " << it->first.getName() << "?" << std::endl;
									// Get user input
									boolChoice = choiceYesNo("Yes", "No");

									// If the player chose "Yes" ('Y'/'y')
									if (boolChoice == true)
									{
										// Output to the player that the new Weapon object was equipped
										std::cout << "\n  " << it->first.getName() << " equipped!";
										// Output to the player that the old Weapon object was moved to the inventory
										//   (Equipment* pointer 'mainHand' is set when user equips a mainhand weapon)
										std::cout << "\n  " << player.mainHand->getName() << " moved to inventory." << std::endl;

										// Add the previously equipped Weapon object to the player's inventory
										player.addToInv(*player.mainHand);
										// Unequip the previously equipped Weapon object
										player.unequipWeapon(*player.mainHand);
										// Equip the new Weapon object just purchased
										player.equipWeapon(it->first);

										// Set the Equipment* pointer 'mainHand' to the newly equipped Weapon object
										player.mainHand = &it->first;

										// Go to the location of 'shopAgain:' and play from there (exits the loop)
										goto shopAgain;
									}  // OR
									// If the player chose "No" ('N'/'n')
									else if (boolChoice == false)
									{
										// Output confirmation. Tell the player that the new Weapon object was added to their inventory
										std::cout << "\n  Confirmed. " << it->first.getName() << " added to inventory." << std::endl;

										// Add the newly purchased Weapon object to the player's inventory
										player.addToInv(it->first);

										// Go to the location of 'shopAgain:' and play from there (exits the loop)
										goto shopAgain;
									}
								}  // OR

								// If the player currently has a one-handed Weapon object equipped
								else if (player.mainHand == NULL && player.oneHanded != NULL)
								{
									// Ask the player whether or not to equip the new Weapon just purchased
									std::cout << "  You currently have your " << player.oneHanded->getName() << " equipped. " <<
										"Would you like to equip your new " << it->first.getName() << "?" << std::endl;
									// Get user input
									boolChoice = choiceYesNo("Yes", "No");

									// If the player chose "Yes" ('Y'/'y')
									if (boolChoice == true)
									{
										// Output to the player that the new Weapon object was equipped
										std::cout << "\n  " << it->first.getName() << " equipped!";
										// Output to the player that the old Weapon object was moved to the inventory
										//   (Equipment* pointer 'oneHanded' is set when the user equips a one-handed weapon)
										std::cout << "\n  " << player.oneHanded->getName() << " moved to inventory." << std::endl;

										// Add the previously equipped Weapon object to the player's inventory
										player.addToInv(*player.oneHanded);
										// Unequip the previously equipped Weapon object
										player.unequipWeapon(*player.oneHanded);
										// Equip the new Weapon object just purchased
										player.equipWeapon(it->first);

										// Set the Equipment* pointer 'oneHanded' to NULL
										player.oneHanded = NULL;
										// Set the Equipment* pointer 'mainhand' to the newly equipped Weapon object reference
										player.mainHand = &it->first;

										// Go to the location of 'shopAgain:' and play from there (exits the loop)
										goto shopAgain;
									}  // OR
									// If the player chose "No" ('N'/'n')
									else if (boolChoice == false)
									{
										// Output confirmation. Tell the player that the new Weapon object was added to their inventory
										std::cout << "\n  Confirmed. " << it->first.getName() << " added to inventory." << std::endl;

										// Add the newly purchased Weapon object to the player's inventory
										player.addToInv(it->first);

										// Go to the location of 'shopAgain:' and play from there (exits the loop)
										goto shopAgain;
									}
								}

								// Otherwise (Logically, this should never pass)...
								else
								{
									// Output error message
									std::cout << "\n\n\t\t&)%@(&#!  ERROR!!!  &!$(&%#$\nUNACCOUNTED WEAPON COMBO WHEN EQUIPPING MAIN-HAND WEAPON" <<
										"\n\t\t&)%@(&#!  ERROR!!!  &!$(&%#$\n\n";

									// Go to the location of 'shopAgain:' and play from there (exits the loop)
									goto shopAgain;
								}
							}
						}  // OR

						// If the Equipment purchased was an offhand weapon
						else if (it->first.getType() == "O-Sword" || it->first.getType() == "O-Dagger" ||
							it->first.getType() == "O-Wand" || it->first.getType() == "O-Crossbow")
						{
							// If there are no held weapon conflictions
							//   (If there is no mainhand, offhand, or onehanded weapon currently equipped)
							if (player.offHand == NULL && player.shield == NULL && player.oneHanded == NULL)
							{
								// Equip the user-chosen Weapon object
								player.equipWeapon(it->first);

								// Set the public Equipment* pointer 'offHand'
								// to the reference of the chosen Equipment object.
								//   (for usage in determining whether or not an offhand
								//    weapon is currently equipped or not)
								player.offHand = &it->first;

								// Output item equipped notification
								std::cout << "\n  You have equipped the " << it->first.getName() << "(OH)!" << std::endl;

								// Go to the location of 'shopAgain:' and play from there (exits the loop)
								goto shopAgain;
							}

							// Otherwise (If there IS a held weapon confliction)...
							else
							{
								// If the player currently has an offhand Weapon object equipped
								if (player.offHand != NULL && player.shield == NULL && player.oneHanded == NULL)
								{
									// Ask the player whether or not to equip the new Weapon just purchased
									std::cout << "  You currently have your " << player.offHand->getName() << "(OH) equipped. " <<
										"Would you like to equip your new " << it->first.getName() << "(OH)?" << std::endl;
									// Get user input
									boolChoice = choiceYesNo("Yes", "No");

									// If player chose "Yes" ('Y'/'y')
									if (boolChoice == true)
									{
										// Output to the player that the new Weapon object was equipped
										std::cout << "\n  " << it->first.getName() << "(OH) equipped!";
										// Output to the player that the old Weapon object was moved to the inventory
										//   (Equipment* pointer 'offHand' is set when user equips an offhand weapon)
										std::cout << "\n  " << player.offHand->getName() << "(OH) moved to inventory." << std::endl;

										// Add the previously equipped Weapon object to the player's inventory
										player.addToInv(*player.offHand);
										// Unequip the previously equipped Weapon object
										player.unequipWeapon(*player.offHand);
										// Equip the new Weapon object just purchased
										player.equipWeapon(it->first);

										// Set the Equipment* pointer 'offHand' to the newly equipped Weapon object
										player.offHand = &it->first;

										// Go to the location of 'shopAgain:' and play from there (exits the loop)
										goto shopAgain;
									}  // OR
									// If the player chose "No" ('N'/'n')
									else if (boolChoice == false)
									{
										// Output confirmation. Tell the player that the new Weapon object was added to their inventory
										std::cout << "\n  Confirmed. " << it->first.getName() << "(OH) added to inventory." << std::endl;

										// Add the newly purchased Weapon object to the player's inventory
										player.addToInv(it->first);

										// Go to the location of 'shopAgain:' and play from there (exits the loop)
										goto shopAgain;
									}
								}  // OR

								// If the player currently has a one-handed Weapon object equipped
								else if (player.offHand == NULL && player.shield == NULL && player.oneHanded != NULL)
								{
									// Ask the player whether or not to equip the new Weapon just purchased
									std::cout << "  You currently have your " << player.oneHanded->getName() << "(1H) equipped. " <<
										"Would you like to equip your new " << it->first.getName() << "(OH)?" << std::endl;
									// Get user input
									boolChoice = choiceYesNo("Yes", "No");

									// If the player chose "Yes" ('Y'/'y')
									if (boolChoice == true)
									{
										// Output to the player that the new Weapon object was equipped
										std::cout << "\n  " << it->first.getName() << "(OH) equipped!";
										// Output to the player that the old Weapon object was moved to the inventory
										//   (Equipment* pointer 'oneHanded' is set when the user equips a one-handed weapon)
										std::cout << "\n  " << player.oneHanded->getName() << "(1H) moved to inventory." << std::endl;

										// Add the previously equipped Weapon object to the player's inventory
										player.addToInv(*player.oneHanded);
										// Unequip the previously equipped Weapon object
										player.unequipWeapon(*player.oneHanded);
										// Equip the new Weapon object just purchased
										player.equipWeapon(it->first);

										// Set the Equipment* pointer 'oneHanded' to NULL
										player.oneHanded = NULL;
										// Set the Equipment* pointer 'offHand' to the newly equipped Weapon object reference
										player.offHand = &it->first;

										// Go to the location of 'shopAgain:' and play from there (exits the loop)
										goto shopAgain;
									}  // OR
									// If the player chose "No" ('N'/'n')
									else if (boolChoice == false)
									{
										// Output confirmation. Tell the player that the new Weapon object was added to their inventory
										std::cout << "\n  Confirmed. " << it->first.getName() << " added to inventory." << std::endl;

										// Add the newly purchased Weapon object to the player's inventory
										player.addToInv(it->first);

										// Go to the location of 'shopAgain:' and play from there (exits the loop)
										goto shopAgain;
									}
								}  // OR

								// If the player currently has a shield Armor object equipped
								else if (player.offHand == NULL && player.shield != NULL && player.oneHanded == NULL)
								{
									// Ask the player whether or not to equip the new Weapon just purchased
									std::cout << "  You currently have your " << player.shield->getName() << "(OH) equipped. " <<
										"Would you like to equip your new " << it->first.getName() << "(OH)?" << std::endl;
									// Get user input
									boolChoice = choiceYesNo("Yes", "No");

									// If the player chose "Yes" ('Y'/'y')
									if (boolChoice == true)
									{
										// Output to the player that the new Weapon object was equipped
										std::cout << "\n  " << it->first.getName() << "(OH) equipped!";
										// Output to the player that the old Armor object was moved to the inventory
										//   (Equipment* pointer 'shield' is set when the user equips a shield)
										std::cout << "\n  " << player.shield->getName() << "(OH) moved to inventory." << std::endl;

										// Add the previously equipped Armor object to the player's inventory
										player.addToInv(*player.shield);
										// Unequip the previously equipped Armor object
										player.unequipArmor(*player.shield);
										// Equip the new Weapon object just purchased
										player.equipWeapon(it->first);

										// Set the Equipment* pointer 'shield' to NULL
										player.shield = NULL;
										// Set the Equipment* pointer 'offHand' to the newly equipped Weapon object reference
										player.offHand = &it->first;

										// Go to the location of 'shopAgain:' and play from there (exits the loop)
										goto shopAgain;
									}  // OR
									// If the player chose "No" ('N'/'n')
									else if (boolChoice == false)
									{
										// Output confirmation. Tell the player that the new Weapon object was added to their inventory
										std::cout << "\n  Confirmed. " << it->first.getName() << "(OH) added to inventory." << std::endl;

										// Add the newly purchased weapon to the player's inventory
										player.addToInv(it->first);

										// Go to the location of 'shopAgain:' and play from there (exits the loop)
										goto shopAgain;
									}
								}

								// Otherwise (Logically, this should never pass)...
								else
								{
									// Output error message
									std::cout << "\n\n\t\t&)%@(&#!  ERROR!!!  &!$(&%#$\nUNACCOUNTED WEAPON COMBO WHEN EQUIPPING OFF-HAND WEAPON" <<
										"\n\t\t&)%@(&#!  ERROR!!!  &!$(&%#$\n\n";
								}
							}
						}  // OR

						// If the Equipment purchased was a one-handed weapon
						else if (it->first.getType() == "1H-Sword" || it->first.getType() == "1H-Wand" ||
							it->first.getType() == "Bow")
						{
							// If there are no held weapon conflictions
							//   (If there is no mainhand, offhand, or one-handed weapon or a shield equipped
							if (player.oneHanded == NULL && player.mainHand == NULL && player.offHand == NULL && player.shield == NULL)
							{
								// Equip the user-chosen Weapon object
								player.equipWeapon(it->first);

								// Set the public Equipment* pointer 'oneHanded'
								// to the reference of the chosen Equipment object
								//   (for usage in determining whether or not a onehanded
								//    weapon is currently equipped or not)
								player.oneHanded = &it->first;

								// Output item equipped notification
								std::cout << "\n  You have equipped the " << it->first.getName() << "(1H)!" << std::endl;

								// Go to the location of 'shopAgain:' and play from there (exits the loop)
								goto shopAgain;
							}

							// Otherwise (If there IS a held weapon confliction)...
							else
							{
								// If the player currently has a mainhand & offhand Weapon object equipped
								if (player.mainHand != NULL && player.offHand != NULL && player.oneHanded == NULL && player.shield == NULL)
								{
									// Ask the player whether or not to equip the new Weapon just purchased
									std::cout << "  You currently have your " << player.mainHand->getName() << " and your " <<
										player.offHand->getName() << "(OH) equipped.\n\nWould you like to equip your new " <<
										it->first.getName() << "(1H)?" << std::endl;
									// Get user input
									boolChoice = choiceYesNo("Yes", "No");

									// If the player chose "Yes" ('Y'/'y')
									if (boolChoice == true)
									{
										// Output to the player that the new Weapon object was equipped
										std::cout << "\n  " << it->first.getName() << "(1H) equipped!";
										// Output to the player that the old Weapon objects were moved to the inventory
										//   (Equipment* pointers 'mainHand' & 'offHand' are set when the user equips
										//    a mainhand/offhand weapon)
										std::cout << "\n  " << player.mainHand->getName() << " moved to inventory.";
										std::cout << "\n  " << player.offHand->getName() << "(OH) moved to inventory." << std::endl;

										// Add the previously equipped mainhand & offhand Weapon objects to the player's inventory
										player.addToInv(*player.mainHand);
										player.addToInv(*player.offHand);
										// Unequip the previously equipped mainhand & offhand Weapon objects
										player.unequipWeapon(*player.mainHand);
										player.unequipWeapon(*player.offHand);
										// Equip the new Weapon object just purchased
										player.equipWeapon(it->first);

										// Set the Equipment* pointers 'mainhand' & 'offHand' to NULL
										player.mainHand = NULL;
										player.offHand = NULL;
										// Set the Equipment* pointer 'oneHanded' to the newly equipped Weapon object
										player.oneHanded = &it->first;

										// Go to the location of 'shopAgain:' and play from there (exits the loop)
										goto shopAgain;
									}  // OR
									// If the player chose "No" ('N'/'n')
									else if (boolChoice == false)
									{
										// Output confirmation. Tell the player that the new Weapon object was added to their inventory
										std::cout << "\n  Confirmed. " << it->first.getName() << "(1H) added to inventory." << std::endl;

										// Add the newly purchased Weapon object to the player's inventory
										player.addToInv(it->first);

										// Go to the location of 'shopAgain:' and play from there (exits the loop)
										goto shopAgain;
									}
								}  // OR

								// If the player currently has a one-handed Weapon object equipped
								else if (player.mainHand == NULL && player.offHand == NULL && player.oneHanded != NULL && player.shield == NULL)
								{
									// Ask the player whether or not to equip the new Weapon just purchased
									std::cout << "  You currently have your " << player.oneHanded->getName() << "(1H) equipped. " <<
										"Would you like to equip your new " << it->first.getName() << "(1H)?" << std::endl;
									// Get user input
									boolChoice = choiceYesNo("Yes", "No");

									// If the player chose "Yes" ('Y'/'y')
									if (boolChoice == true)
									{
										// Output to the player that the new Weapon object was equipped
										std::cout << "\n  " << it->first.getName() << "(1H) equipped!";
										// Output to the player that the old Weapon object was moved to the inventory
										//   (Equipment* pointer 'oneHanded' is set when the user equips a one-handed weapon)
										std::cout << "\n  " << player.oneHanded->getName() << "(1H) moved to inventory." << std::endl;

										// Add the previously equipped Weapon object to the player's inventory
										player.addToInv(*player.oneHanded);
										// Unequip the previously equipped Weapon object
										player.unequipWeapon(*player.oneHanded);
										// Equip the new Weapon object just purchased
										player.equipWeapon(it->first);

										// Set the Equipment* pointer 'oneHanded' to the newly equipped Weapon object reference
										player.oneHanded = &it->first;

										// Go to the location of 'shopAgain:' and play from there (exits the loop)
										goto shopAgain;
									}  // OR
									// If the player chose "No" ('N'/'n')
									else if (boolChoice == false)
									{
										// Output confirmation. Tell the player that the new Weapon object was added to their inventory
										std::cout << "\n  Confirmed. " << it->first.getName() << "(1H) added to inventory." << std::endl;

										// Add the newly purchased Weapon object to the player's inventory
										player.addToInv(it->first);

										// Go to the location of 'shopAgain:' and play from there (exits the loop)
										goto shopAgain;
									}
								}  // OR

								// If the player currently has a mainhand Weapon object equipped
								else if (player.mainHand != NULL && player.offHand == NULL && player.oneHanded == NULL && player.shield == NULL)
								{
									// Ask the player whether or not to equip the new Weapon just purchased
									std::cout << "  You currently have your " << player.mainHand->getName() << " equipped. " <<
										"Would you like to equip your new " << it->first.getName() << "(1H)?" << std::endl;
									// Get user input
									boolChoice = choiceYesNo("Yes", "No");

									// If the player chose "Yes" ('Y'/'y')
									if (boolChoice == true)
									{
										// Output to the player that the new Weapon object was equipped
										std::cout << "\n  " << it->first.getName() << "(1H) equipped!";
										// Output to the player that the old Weapon object was moved to the inventory
										//   (Equipment* pointer 'mainHand' is set when the user equips a mainhand weapon)
										std::cout << "\n  " << player.mainHand->getName() << " moved to inventory." << std::endl;

										// Add the previously equipped Weapon object to the player's inventory
										player.addToInv(*player.mainHand);
										// Unequip the previously equipped Weapon object
										player.unequipWeapon(*player.mainHand);
										// Equip the new Weapon object just purchased
										player.equipWeapon(it->first);

										// Set the Equipment* pointer 'mainHand' to NULL
										player.mainHand = NULL;
										// Set the Equipment* pointer 'oneHanded' to the newly equipped Weapon object reference
										player.oneHanded = &it->first;

										// Go to the location of 'shopAgain:' and play from there (exits the loop)
										goto shopAgain;
									}  // OR
									// If the player chose "No" ('N'/'n')
									else if (boolChoice == false)
									{
										// Output confirmation. Tell the player that the new Weapon object was added to their inventory
										std::cout << "\n  Confirmed. " << it->first.getName() << "(1H) added to inventory." << std::endl;

										// Add the newly purchased Weapon object to the player's inventory
										player.addToInv(it->first);

										// Go to the location of 'shopAgain:' and play from there (exits the loop)
										goto shopAgain;
									}
								}  // OR

								// If the player currently has an offhand Weapon object equipped
								else if (player.mainHand == NULL && player.offHand != NULL && player.oneHanded == NULL && player.shield == NULL)
								{
									// Ask the player whether or not to equip the new Weapon just purchased
									std::cout << "  You currently have your " << player.offHand->getName() << "(OH) equipped. " <<
										"Would you like to equip your new " << it->first.getName() << "(1H)?" << std::endl;
									// Get user input
									boolChoice = choiceYesNo("Yes", "No");

									// If the player chose "Yes" ('Y'/'y')
									if (boolChoice == true)
									{
										// Output to the player that the new Weapon object was equipped
										std::cout << "\n  " << it->first.getName() << "(1H) equipped!";
										// Output to the player that the old Weapon object was moved to the inventory
										//   (Equipment* pointer 'offHand' is set when the user equips an offhand weapon)
										std::cout << "\n  " << player.offHand->getName() << "(OH) moved to inventory." << std::endl;

										// Add the previously equipped Weapon object to the player's inventory
										player.addToInv(*player.offHand);
										// Unequip the previously equipped Weapon object
										player.unequipWeapon(*player.offHand);
										// Equip the new Weapon object just purchased
										player.equipWeapon(it->first);

										// Set the Equipment* pointer 'offHand' to NULL
										player.offHand = NULL;
										// Set the Equipment* pointer 'oneHanded' to the newly equipped Weapon object reference
										player.oneHanded = &it->first;

										// Go to the location of 'shopAgain:' and play from there (exits the loop)
										goto shopAgain;
									}  // OR
									// If the player chose "No" ('N'/'n')
									else if (boolChoice == false)
									{
										// Output confirmation. Tell the player that the new Weapon object was added to their inventory
										std::cout << "\n  Confirmed. " << it->first.getName() << "(1H) added to inventory." << std::endl;

										// Add the newly purchased Weapon object to the player's inventory
										player.addToInv(it->first);

										// Go to the location of 'shopAgain:' and play from there (exits the loop)
										goto shopAgain;
									}
								}  // OR

								// If the player currently has a shield Armor object equipped
								else if (player.mainHand == NULL && player.offHand == NULL && player.oneHanded == NULL && player.shield != NULL)
								{
									// Ask the player whether or not to equip the new Weapon just purchased
									std::cout << "  You currently have your " << player.shield->getName() << "(OH) equipped. " <<
										"Would you like to equip your new " << it->first.getName() << "(1H)?" << std::endl;
									// Get user boolChoice
									boolChoice = choiceYesNo("Yes", "No");

									// If the player chose "Yes" ('Y'/'y')
									if (boolChoice == true)
									{
										// Output to the player that the new Weapon object was equipped
										std::cout << "\n  " << it->first.getName() << "(1H) equipped!";
										// Output to the player that the old Armor object was moved to the inventory
										//   (Equipment* pointer 'shield' is set when the user equips a shield)
										std::cout << "\n  " << player.shield->getName() << "(OH) moved to inventory." << std::endl;

										// Add the previously equipped Armor object to the player's inventory
										player.addToInv(*player.shield);
										// Unequip the previously equipped Armor object
										player.unequipArmor(*player.shield);
										// Equip the new Weapon object just purchased
										player.equipWeapon(it->first);

										// Set the Equipment* pointer 'shield' to NULL
										player.shield = NULL;
										// Set the Equipment* pointer 'oneHanded' to the newly equipped Weapon object reference
										player.oneHanded = &it->first;

										// Go to the location of 'shopAgain:' and play from there (exits the loop)
										goto shopAgain;
									}  // OR
									// If the player chose "No" ('N'/'n')
									else if (boolChoice == false)
									{
										// Output confirmation. Tell the player that the new Weapon object was added to their inventory
										std::cout << "\n  Confirmed. " << it->first.getName() << "(1H) added to inventory." << std::endl;

										// Add the newly purchased Weapon object to the player's inventory
										player.addToInv(it->first);

										// Go to the location of 'shopAgain:' and play from there (exits the loop)
										goto shopAgain;
									}
								}  // OR

								// If the player currently has a mainhand Weapon object AND a shield Armor object equipped
								else if (player.mainHand != NULL && player.offHand == NULL && player.oneHanded == NULL && player.shield != NULL)
								{
									// Ask the player whether or not to equip the new Weapon just purchased
									std::cout << "  You currently have your " << player.mainHand->getName() << " and your " <<
										player.shield << "(OH) equipped.\nWould you like to equip your new " <<
										it->first.getName() << "(1H)? ";
									// Get user input
									boolChoice = choiceYesNo("Yes", "No");

									// If the player chose "Yes" ('Y'/'y')
									if (boolChoice == true)
									{
										// Output to the player that the new Weapon object was equipped
										std::cout << "\n  " << it->first.getName() << "(1H) equipped!";
										// Output to the player that the old Weapon & Armor objects were moved to the inventory
										//   (Equipment* pointers 'mainHand' & 'shield' are set when the user equips a mainhand
										//    weapon/shield)
										std::cout << "\n  " << player.mainHand->getName() << " moved to inventory.";
										std::cout << "\n  " << player.shield->getName() << "(OH) moved to inventory." << std::endl;

										// Add the previously equipped Weapon & Armor objects to the player's inventory
										player.addToInv(*player.mainHand);
										player.addToInv(*player.shield);
										// Unequip the previously equpped Weapon & Armor objects
										player.unequipWeapon(*player.mainHand);
										player.unequipWeapon(*player.shield);
										// Equip the new Weapon object just purchased
										player.equipWeapon(it->first);

										// Set the Equipment* pointers 'mainHand' & 'shield' to NULL
										player.mainHand = NULL;
										player.shield = NULL;
										// Set the Equipment* pointer 'oneHanded' to the newly equipped Weapon object
										player.oneHanded = &it->first;

										// Go to the location of 'shopAgain:' and play from there (exits the loop)
										goto shopAgain;
									}   // OR
									// If the player chose "No" ('N'/'n')
									else if (boolChoice == false)
									{
										// Output confirmation. Tell the player that the new Weapon object was added to their inventory
										std::cout << "\n  Confirmed. " << it->first.getName() << "(1H) added to inventory." << std::endl;

										// Add the newly purchased Weapon object to the player's inventory
										player.addToInv(it->first);

										// Go to the location of 'shopAgain:' and play from there (exits the loop)
										goto shopAgain;
									}
								}

								// Otherwise (Logically, this should never pass)...
								else
								{
									// Output error
									std::cout << "\n\n\t\t&)%@(&#!  ERROR!!!  &!$(&%#$\nUNACCOUNTED WEAPON COMBO WHEN EQUIPPING 1H WEAPON" <<
										"\n\t\t&)%@(&#!  ERROR!!!  &!$(&%#$\n\n";
								}
							}
						}  // OR

						// If the Equipment purchased was a shield
						else if (it->first.getType() == "Shield")
						{
							// If there are no held weapon conflictions
							//   (If there is no shield, offhand weapon, or mainhand weapon currently equipped)
							if (player.shield == NULL && player.offHand == NULL && player.oneHanded == NULL)
							{
								// Equip the user-chosen Armor object
								player.equipArmor(it->first);

								// Set the public Equipment* pointer 'shield'
								// to the reference of the chosen Equipment object
								//   (for usage in determining whether or not a
								//    shield is currently equipped or not)
								player.shield = &it->first;

								// Output item equipped notification
								std::cout << "\n  You have equipped the " << it->first.getName() << "!" << std::endl;

								// Go to the location of 'shopAgain:' and play from there (exits the loop)
								goto shopAgain;
							}

							// Otherwise (If there IS a held weapon confliction)...
							else
							{
								// If the player currently has an offhand Weapon object equipped
								if (player.shield == NULL && player.offHand != NULL && player.oneHanded == NULL)
								{
									// Ask the player whether or not to equip the new Shield just purchased
									std::cout << "  You currently have your " << player.offHand->getName() << "(OH) equipped. " <<
										"Would you like to equip your new " << it->first.getName() << "(OH)?" << std::endl;
									// Get user input
									boolChoice = choiceYesNo("Yes", "No");

									// If the player chose "Yes" ('Y'/'y')
									if (boolChoice == true)
									{
										// Output to the player that the new Armor object was equipped
										std::cout << "\n  " << it->first.getName() << "(OH) equipped!";
										// Output to the player that the old Weapon object was moved to the inventory
										//   (Equipment* pointer 'offHand' is set when the user equips an offhand weapon)
										std::cout << "\n  " << player.offHand->getName() << "(OH) moved to inventory." << std::endl;

										// Add the previously equipped Weapon object to the player's inventory
										player.addToInv(*player.offHand);
										// Unequip the previously equipped Weapon object
										player.unequipWeapon(*player.offHand);
										// Equip the new Armor object just purchased
										player.equipArmor(it->first);

										// Set the Equipment* pointer 'offHand' to NULL
										player.offHand = NULL;
										// Set the Equipment* pointer 'shield' to the newly equipped Armor object reference
										player.shield = &it->first;

										// Go to the location of 'shopAgain:' and play from there (exits the loop)
										goto shopAgain;
									}  // OR
									// If the player chose "No" ('N'/'n')
									else if (boolChoice == false)
									{
										// Output confirmation. Tell the player that the new Armor object was added to their inventory
										std::cout << "\n  Confirmed. " << it->first.getName() << " added to inventory." << std::endl;

										// Add the newly purchased Armor object to the player's inventory
										player.addToInv(it->first);

										// Go to the location of 'shopAgain:' and play from there (exits the loop)
										goto shopAgain;
									}
								}  // OR

								// If the player currently has a shield Armor object equipped
								else if (player.shield != NULL && player.offHand == NULL && player.oneHanded == NULL)
								{
									// Ask the player whether or not to equip the new Shield just purchased
									std::cout << "  You currently have your " << player.shield->getName() << "(OH) equipped. " <<
										"Would you like to equip your new " << it->first.getName() << "(OH)?" << std::endl;
									// Get user input
									boolChoice = choiceYesNo("Yes", "No");

									// If the player chose "Yes" ('Y'/'y')
									if (boolChoice == true)
									{
										// Output to the player that the new Armor object was equipped.
										std::cout << "\n  " << it->first.getName() << "(OH) equipped!";
										// Output to the player that the old Armor object was moved to the inventory
										//   (Equipment* pointer 'shield' is set when the user equips a shield)
										std::cout << "\n  " << player.shield->getName() << "(OH) moved to inventory." << std::endl;

										// Add the previously equipped Armor object to the player's inventory
										player.addToInv(*player.shield);
										// Unequip the previously equipped Armor object
										player.unequipArmor(*player.shield);
										// Equip the new Armor object just purchased
										player.equipArmor(it->first);

										// Set the Equipment* pointer 'shield' to the newly equipped Armor object reference
										player.shield = &it->first;

										// Go to the location of 'shopAgain:' and play from there (exits the loop)
										goto shopAgain;
									}  // OR
									// If the player chose "No ('N'/'n')
									else if (boolChoice == false)
									{
										// Output confirmation. Tell the player that the new Armor object was added to their inventory
										std::cout << "\n  Confirmed. " << it->first.getName() << " added to inventory." << std::endl;

										// Add the newly purchased Armor object to the player's inventory
										player.addToInv(it->first);

										// Go to the location of 'shopAgain:' and play from there (exits the loop)
										goto shopAgain;
									}
								}  // OR

								   // If the player currently has a one-handed Weapon object equipped
								else if (player.shield == NULL && player.offHand == NULL && player.oneHanded != NULL)
								{
									// Ask the player whether or not to equip the new Shield just purchased
									std::cout << "  You currently have your " << player.oneHanded->getName() << "(1H) equipped. " <<
										"Would you like to equip your new " << it->first.getName() << "(OH)?" << std::endl;
									// Get user input
									boolChoice = choiceYesNo("Yes", "No");

									// If the player chose "Yes" ('Y'/'y')
									if (boolChoice == true)
									{
										// Output to the player that the new Armor object was equipped
										std::cout << "\n  " << it->first.getName() << "(OH) equipped!";
										// Output to the player that the old Weapon object was moved to the inventory
										//   (Equipment* pointer 'oneHanded' is set when the user equips a one-handed weapon)
										std::cout << "\n  " << player.oneHanded->getName() << "(1H) moved to inventory." << std::endl;

										// Add the previously equipped Weapon object to the player's inventory
										player.addToInv(*player.oneHanded);
										// Unequip the previously equipped Weapon object
										player.unequipWeapon(*player.oneHanded);
										// Equip the new Armor object just purchased
										player.equipArmor(it->first);

										// Set the Equipment* pointer 'oneHanded' to NULL
										player.oneHanded = NULL;
										// Set the Equipment* pointer 'shield' to the newly equipped Armor object reference
										player.shield = &it->first;

										// Go to the location of 'shopAgain:' and play from there (exits the loop)
										goto shopAgain;
									}  // OR
									// If the player chose "No" ('N'/'n')
									else if (boolChoice == false)
									{
										// Output confirmation. Tell the player that the new Armor object was added to their inventory
										std::cout << "\n  Confirmed. " << it->first.getName() << " added to inventory." << std::endl;

										// Add the newly purchased Armor object to the player's inventory
										player.addToInv(it->first);

										// Go to the location of 'shopAgain:' and play from there (exits the loop)
										goto shopAgain;
									}
								}

								// Otherwise (Logically, this should never pass)...
								else
								{
									std::cout << "\n\n\t\t&)%@(&#!  ERROR!!!  &!$(&%#$\nUNACCOUNTED WEAPON COMBO WHEN EQUIPPING SHIELD" <<
										"\n\t\t&)%@(&#!  ERROR!!!  &!$(&%#$\n\n";
								}
							}
						}  // OR

						// If the Equipment purchased was a head item
						else if (it->first.getType() == "Headpiece")
						{
							// If there is not a previously equipped head item
							if (player.helm == NULL)
							{
								// Equip the user-chosen Armor object
								player.equipArmor(it->first);

								// Set the public Equipment* pointer 'helm'
								// to the reference of the chosen Equipment object
								//   (for usage in determining whether or not a
								//    head item is currently equipped or not)
								player.helm = &it->first;

								// Output item equipped notification
								std::cout << "\n  You have equipped the " << it->first.getName() << "!" << std::endl;

								// Go to the location of 'shopAgain:' and play from there (exits the loop)
								goto shopAgain;
							}  // OR

							// If there IS a previously equipped head item
							else if (player.helm != NULL)
							{
								// Ask the player whether or not to equip the new Armor just purchased
								std::cout << "  You currently have your " << player.helm->getName() << " equipped. " <<
									"Would you like to equip your new " << it->first.getName() << "?" << std::endl;
								// Get user input
								boolChoice = choiceYesNo("Yes", "No");

								// If the player chose "Yes" ('Y'/'y')
								if (boolChoice == true)
								{
									// Output to the player that the new Armor object was equipped
									std::cout << "\n  " << it->first.getName() << " equipped!";
									// Output to the player that the old Armor object was moved to the inventory
									//   (Equipment* pointer 'helm' is set when user equips a head item)
									std::cout << "\n  " << player.helm->getName() << " moved to inventory." << std::endl;

									// Add the previously equipped Armor object to the player's inventory
									player.addToInv(*player.helm);
									// Unequip the previously equipped Armor object
									player.unequipArmor(*player.helm);
									// Equip the new Armor object just purchased
									player.equipArmor(it->first);

									// Set the Equipment* pointer 'helm' to the newly equipped Armor object
									player.helm = &it->first;

									// Go to the location of 'shopAgain:' and play from there (exits the loop)
									goto shopAgain;
								}  // OR
								// If the player chose "No" ('N'/'n')
								else if (boolChoice == false)
								{
									// Output confirmation. Tell the player that the new Armor object was added to their inventory
									std::cout << "\n  Confirmed. " << it->first.getName() << " added to inventory." << std::endl;

									// Add the newly purchased Armor object to the player's inventory
									player.addToInv(it->first);

									// Go to the location of 'shopAgain:' and play from there (exits the loop)
									goto shopAgain;
								}
							}

							// Otherwise (Logically, this should never pass)...
							else
							{
								// Output error message
								std::cout << "\n\n\t\t&)%@(&#!  ERROR!!!  &!$(&%#$\nUNACCOUNTED ARMOR COMBO WHEN EQUIPPING HELMET" <<
									"\n\t\t&)%@(&#!  ERROR!!!  &!$(&%#$\n\n";
							}
						}  // OR

						// If the Equipment purchased was a chest item
						else if (it->first.getType() == "Chestpiece")
						{
							// If there is not a previously equipped chest item
							if (player.chest == NULL)
							{
								// Equip the user-chosen Armor object
								player.equipArmor(it->first);

								// Set the public Equipment* pointer 'chest'
								// to the reference of the chosen Equipment object
								//   (for usage in determining whether or not a
								//    chest item is currently equipped or not)
								player.chest = &it->first;

								// Output item equipped notification
								std::cout << "\n  You have equipped the " << it->first.getName() << "!" << std::endl;

								// Go to the location of 'shopAgain:' and play from there (exits the loop)
								goto shopAgain;
							}  // OR

							// If there IS a previously equipped chest item
							else if (player.chest != NULL)
							{
								// Ask the player whether or not to equip the new Armor just purchased
								std::cout << "  You currently have your " << player.chest->getName() << " equipped. " <<
									"Would you like to equip your new " << it->first.getName() << "?" << std::endl;
								// Get user input
								boolChoice = choiceYesNo("Yes", "No");

								// If the player chose "Yes" ('Y'/'y')
								if (boolChoice == true)
								{
									// Output to the player that the new Armor object was equipped
									std::cout << "\n  " << it->first.getName() << " equipped!";
									// Output to the player that the old Armor object was moved to the inventory
									//   (Equipment* pointer 'chest' is set when user equips a chest item)
									std::cout << "\n  " << player.chest->getName() << " moved to inventory." << std::endl;

									// Add the previously equipped Armor object to the player's inventory
									player.addToInv(*player.chest);
									// Unequip the previously equipped Armor object
									player.unequipArmor(*player.chest);
									// Equip the new Armor object just purchased
									player.equipArmor(it->first);

									// Set the Equipment* pointer 'chest' to the newly equipped Armor object
									player.chest = &it->first;

									// Go to the location of 'shopAgain:' and play from there (exits the loop)
									goto shopAgain;
								}  // OR

								// If the player chose "No" ('N'/'n')
								else if (boolChoice == false)
								{
									// Output confirmation. Tell the player that the new Armor object was added to their inventory
									std::cout << "\n  Confirmed. " << it->first.getName() << " added to inventory." << std::endl;

									// Add the newly purchased Armor object to the player's inventory
									player.addToInv(it->first);

									// Go to the location of 'shopAgain:' and play from there (exits the loop)
									goto shopAgain;
								}
							}

							// Otherwise (Logically, this should never pass)...
							else
							{
								// Output error message
								std::cout << "\n\n\t\t&)%@(&#!  ERROR!!!  &!$(&%#$\nUNACCOUNTED ARMOR COMBO WHEN EQUIPPING CHESTPIECE" <<
									"\n\t\t&)%@(&#!  ERROR!!!  &!$(&%#$\n\n";
							}
						}  // OR

						// If the Equipment purchased was a leg item
						else if (it->first.getType() == "Leggings")
						{
							// If there is not a previously equipped leg item
							if (player.legs == NULL)
							{
								// Equip the user-chosen Armor object
								player.equipArmor(it->first);

								// Set the public Equipment* pointer 'legs'
								// to the reference of the chosen Equipment object
								//   (for usage in determining whether or not a
								//    leg item is currently equipped or not)
								player.legs = &it->first;

								// Output item equipped notification
								std::cout << "\n  You have equipped the " << it->first.getName() << "!" << std::endl;

								// Go to the location of 'shopAgain:' and play from there (exits the loop)
								goto shopAgain;
							}  // OR

							// If there IS a previously equipped leg item
							else if (player.legs != NULL)
							{
								// Ask the player whether or not to equip the new Armor just purchased
								std::cout << "  You currently have your " << player.legs->getName() << " equipped. " <<
									"Would you like to equip your new " << it->first.getName() << "?" << std::endl;
								// Get user input
								boolChoice = choiceYesNo("Yes", "No");

								// If the player chose "Yes" ('Y'/'y')
								if (boolChoice == true)
								{
									// Output to the player that the new Armor object was equipped
									std::cout << "\n  " << it->first.getName() << " equipped!";
									// Output to the player that the old Armor object was moved to the inventory
									//   (Equipment* pointer 'legs' is set when user equips a head item)
									std::cout << "\n  " << player.legs->getName() << " moved to inventory." << std::endl;

									// Add the previously equipped Armor object to the player's inventory
									player.addToInv(*player.legs);
									// Unequip the previously equipped Armor object
									player.unequipArmor(*player.legs);
									// Equip the new Armor object just purchased
									player.equipArmor(it->first);

									// Set the Equipment* pointer 'legs' to the newly equipped Armor object
									player.legs = &it->first;

									// Go to the location of 'shopAgain:' and play from there (exits the loop)
									goto shopAgain;
								}  // OR
								// If the player chose "No" ('N'/'n')
								else if (boolChoice == false)
								{
									// Output confirmation. Tell the player that the new Armor object was added to their inventory
									std::cout << "\n  Confirmed. " << it->first.getName() << " added to inventory." << std::endl;

									// Add the newly purchased Armor object to the player's inventory
									player.addToInv(it->first);

									// Go to the location of 'shopAgain:' and play from there (exits the loop)
									goto shopAgain;
								}
							}

							// Otherwise (Logically, this should never pass)...
							else
							{
								std::cout << "\n\n\t\t&)%@(&#!  ERROR!!!  &!$(&%#$\nUNACCOUNTED ARMOR COMBO WHEN EQUIPPING LEGGINGS" <<
									"\n\t\t&)%@(&#!  ERROR!!!  &!$(&%#$\n\n";
							}
						}  // OR

						// If the Equipment purchased was a foot item
						else if (it->first.getType() == "Boots")
						{
							// If there is not a previously equipped foot item
							if (player.boots == NULL) {
								// Equip the user-chosen Armor object
								player.equipArmor(it->first);

								// Set the public Equipment* pointer 'boots'
								// to the reference of the chosen Equipment object
								//   (for usage in determining whether or not a
								//    foot item is currently equipped or not)
								player.boots = &it->first;

								// Output item equipped notification
								std::cout << "\n  You have equipped the " << it->first.getName() << "!" << std::endl;

								// Go to the location of 'shopAgain:' and play from there (exits the loop)
								goto shopAgain;
							}  // OR

							// If there IS a previously equipped foot item
							else if (player.boots != NULL)
							{
								// Ask the player whether or not to equip the new Armor just purchased
								std::cout << "  You currently have your " << player.boots->getName() << " equipped. " <<
									"Would you like to equip your new " << it->first.getName() << "?" << std::endl;
								// Get user input
								boolChoice = choiceYesNo("Yes", "No");

								// If the player chose "Yes" ('Y'/'y')
								if (boolChoice == true)
								{
									// Output to the player that the new Armor object was equipped
									std::cout << "\n  " << it->first.getName() << " equipped!";
									// Output to the player that the old Armor object was moved to the inventory
									//   (Equipment* pointer 'boots' is set when user equips a foot item)
									std::cout << "\n  " << player.boots->getName() << " moved to inventory." << std::endl;

									// Add the previously equipped Armor object to the player's inventory
									player.addToInv(*player.boots);
									// Unequip the previously equipped Armor object
									player.unequipArmor(*player.boots);
									// Equip the new Armor object just purchased
									player.equipArmor(it->first);

									// Set the Equipment* pointer 'boots' to the newly equipped Armor object
									player.boots = &it->first;

									// Go to the location of 'shopAgain:' and play from there (exits the loop)
									goto shopAgain;
								}  // OR
								// If the player chose "No" ('N'/'n')
								else if (boolChoice == false)
								{
									// Output confirmation. Tell the player that the new Armor object was added to their inventory
									std::cout << "\n  Confirmed. " << it->first.getName() << " added to inventory." << std::endl;

									// Add the newly purchased Armor object to the player's inventory
									player.addToInv(it->first);

									// Go to the location of 'shopAgain:' and play from there (exits the loop)
									goto shopAgain;
								}
							}

							// Otherwise (Logically, this should never pass)...
							else
							{
								std::cout << "\n\n\t\t&)%@(&#!  ERROR!!!  &!$(&%#$\nUNACCOUNTED ARMOR COMBO WHEN EQUIPPING BOOTS" <<
									"\n\t\t&)%@(&#!  ERROR!!!  &!$(&%#$\n\n";
							}
						}

						// Otherwise (Logically, this should never pass)...
						else
						{
							// Output an error message
							std::cout << "\n\n\t&)%@(&#!  ERROR!!!  &!$(&%#$\nUNACCOUNTED EQUIPMENT TYPE" <<
								"\n\t&)%@(&#!  ERROR!!!  &!$(&%#$\n\n";
							// Go to the location of 'shopAgain:' and play from there
							goto shopAgain;
						}
					}

					// Otherwise (If the player CANNOT afford the item) -- player's currency < item cost
					else
					{
						// Output to player they cannot afford the item
						std::cout << "\n\n  You cannot afford this!\n\n";
						// Go to the location of 'shopAgain:' and play from there
						goto shopAgain;
					}
					// This occurs after all actions have been completed, when the item selected IS a valid Class Shop item:
					// Go to the location of 'shopAgain:' and play from there
					goto shopAgain;
				}  // OR

				// If the user inputted number is equivalent to the matching Misc. Shop index's item # value
				else if (numChoice != it->second.first)
				{
					// Loop the # of times of the amount of miscShop vector items
					for (in = miscShop.begin();in != miscShop.end();++in)
					{
						// If the user inputted number is equivalent to the matching Class Shop index's item # value
						if (numChoice == in->second.first)
						{
							// If the player has enough currency to afford the item
							if (player.getCurrency() >= in->second.second)
							{
								// When goto restartMisc: is called, it goes to this location and plays from there
								restartMisc:

								// Ask the player how many items they want to buy
								std::cout << "\n  Shopkeep: How many would you like?" << std::endl;
								// Get user input
								numAmount = choiceNum("  >>>");

								// If the # of items the user chose is 1 or higher
								if (numAmount > 0)
								{
									// If the player has enough currency to afford the # of items specified
									if (player.getCurrency() >= in->second.second * numAmount)
									{
										// Subtract the cost of the item(s) from the player's currency
										player.setCurrency(player.getCurrency() - (in->second.second * numAmount));

										// Set the item's gold (index 0), silver (index 1), and copper (index 2) cost
										// to vector<int> 'itemCost'
										itemCost = GetItemCost(in->second.second * numAmount);
										// Output item purchase notification with the amount the items were purchased for
										std::cout << "\n  You bought " << numAmount << " " << in->first.getName() <<
											"(s) [" << in->first.getEffect() << "] for " << itemCost[0] << " gold, " <<
											itemCost[1] << " silver, and " << itemCost[2] << " copper pieces." << std::endl;

										// If the Equipment object (Item) purchased was a potion
										if (in->first.getType() == "Potion")
										{
											// Add the # given of items purchased to the player's inventory
											player.addMultipleToInv(in->first, numAmount);

											// Go to the location of 'shopAgain:' and play from there (exits the loop)
											goto shopAgain;
										}
										// Otherwise (Logically, this should never pass)...
										else
										{
											// Output error message
											std::cout << "\n\n\t\t&)%@(&#!  ERROR!!!  &!$(&%#$\nUNACCOUNTED ITEM TYPE" <<
												"\n\t\t&)%@(&#!  ERROR!!!  &!$(&%#$\n\n";
										}
									}
									// Otherwise (If the player cannot afford all of the items)...
									else
									{
										// Output an error message & tell the player the actual amount that the player CAN afford
										std::cout << "\n  Shopkeep: You cannot afford that many! You can only afford " <<
											(player.getCurrency() / in->second.second) << "!" << std::endl;

										// Go to the location of 'restartMisc:' and play from there (exits the loop)
										goto restartMisc;
									}
								}
								// Otherwise (If the user inputted a number less than 1)...
								else
								{
									// Output to the player that they can't buy less than 1
									std::cout << "\n  Shopkeep: Haha! Ye' can't buy less than one, laddy!" << std::endl;

									// Go to the location of 'restartMisc:' and play from there (exits the loop)
									goto restartMisc;
								}
							}
							// Otherwise (If the player CANNOT afford a single item)...
							else
							{
								// Output to the player that they cannot afford the item they chose
								std::cout << "\n  You cannot afford this!" << std::endl;

								// Go to the location of 'shopAgain:' and play from there (exits the loop)
								goto shopAgain;
							}
						}
					}
				}
			}
			// If the player chose a number higher than the highest item # (which is the last item of the miscShop)
			if (numChoice > (miscShop.end() - 1)->second.first)
			{
				// If the item number inputted is not one listed, restart
				std::cout << "\n  Shopkeep: Pard'n? I didn' catch that, young'un." << std::endl;


				// Go to the location of 'shopAgain:' and play from there (exits the loop)
				goto tryAgain;
			}
		}

		// If the user input is NOT comprised of an integer (is a string)
		else if (isNum == false)
		{
			// Convert the entire string to lowercase
			// (This way, the user can include any variety of lowercase or uppercase)
			transform(strChoice.begin(), strChoice.end(), strChoice.begin(), ::tolower);

			// If the player inputted "exit"
			if (strChoice == "exit") {
				clear();  // Clear console window

				// Output a goodbye message (to leave the shop)
				std::cout << "\n\n  Shopkeep: Hav' a g'night!" << std::endl;

				// Go to the location of 'end:' and play from there (exits the loop)
				goto end;
			}
			// Otherwise (If any other string is entered)...
			else {
				// Output error message
				std::cout << "\n  Shopkeep: Pard'n? I didn' catch that, young'un." << std::endl;

				// Go to the location of 'restart:' and play from there (restarts the loop)
				goto restartShop;
			}
		}

		// When goto shopAgain: is called, it goes to this location and plays from here
		shopAgain:

		// Ask the player if they want to purchase anything else
		std::cout << "\n\n  Shopkeep: Anythin' else 'fer 'yer this af'ernoon? ";
		// Get user input
		boolChoice = choiceYesNo("Yes", "No");

		// If the player chose "Yes" ('Y'/'y')
		if (boolChoice == true)
		{
			std::this_thread::sleep_for(std::chrono::milliseconds(500));  // Pause 1/2 sec

			clear();  // Clear console window

			// Output confirmation to the player
			std::cout << "\n  Shopkeep: Alrigh' then.";

			// There is no goto, so it will reach the end of the
			// loop and restart from the top.

		}  // OR
		// If the player chose "No" ('N'/'n')
		else if (boolChoice == false)
		{
			clear();  // Clear console window

			// Output goodbye message to the player
			std::cout << "\n  Shopkeep: Hav' a g'night!";

			std::this_thread::sleep_for(std::chrono::milliseconds(500));  // Pause 1/2 sec

			// Go to the location of 'end:' and play from there (starts outside the loop)
			goto end;
		}
	} while (true);  // Loop infinitely until broken out of internally

	// When goto end: is called in the above loop, it breaks out
	// of the loop, goes to this location, and plays from here
	end:

	// Return updated player object
	return player;
}