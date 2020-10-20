/*  Main Source Code File  */

/*  Header Library Import(s)  */
/*  ========================  */
#include <thread>		// Execution Thread Library
#include <cstdlib>		// C Standard General Utilities Library
#include <utility>		// Utility Library - std::pair(), std::make_pair(), etc.

#include "Character.h"	// Character Class
#include "Weapon.h"		// Weapon Class
#include "Armor.h"		// Armor Class
#include "Item.h"		// Item Class

#include "Functions.h"
#include "Choices.h"
#include "Colors.h"
#include "Events.h"
#include "Shop.h"
#include "Battle.h"

/*  Function Declaration(s)  */
/*  =======================  */


/*  ===================  */
/*  === Main Method ===  */
/*  ===================  */
int main()
{
	// Initialize local variables
	char userChoice;
	bool choice;
	std::string Name;
	std::string Class;

	std::cout << WHITE;  // Set white text color

	/*  ======================  */
	/*  ===  Set Up Shops  ===  */
	/*  ======================  */

	/*  Warrior Shop  */
	/*  ============  */
	std::vector<std::pair<Equipment, std::pair<int, int>>> warriorShop;

	// Create Weapon/Armor Objects for the Shop
	Weapon ironsword_m("Iron Sword", "M-Sword", "", "", 12, NULL);
	Weapon ironsword_o("Iron Sword", "O-Sword", "", "", 6, NULL);
	Weapon ironsword_1h("Iron Broadsword", "1H-Sword", "", "", 12, NULL);

	Armor ironshield("Iron Shield", "Shield", "", 2, NULL);

	Armor ironhelm("Iron Helmet", "Headpiece", "", 2, NULL);
	Armor ironchest("Iron Plate", "Chestpiece", "", 3, NULL);
	Armor ironlegs("Iron Grieves", "Leggings", "", 3, NULL);
	Armor ironboots("Iron Boots", "Boots", "", 2, NULL);

	// Add each Weapon/Armor Object to the Shop & Set Prices
	warriorShop.push_back(std::make_pair(ironsword_m, std::make_pair(1, 100)));
	warriorShop.push_back(std::make_pair(ironsword_o, std::make_pair(2, 55)));
	warriorShop.push_back(std::make_pair(ironsword_1h, std::make_pair(3, 125)));

	warriorShop.push_back(std::make_pair(ironshield, std::make_pair(4, 125)));

	warriorShop.push_back(std::make_pair(ironhelm, std::make_pair(5, 95)));
	warriorShop.push_back(std::make_pair(ironchest, std::make_pair(6, 115)));
	warriorShop.push_back(std::make_pair(ironlegs, std::make_pair(7, 115)));
	warriorShop.push_back(std::make_pair(ironboots, std::make_pair(8, 95)));


	/*  Archer Shop  */
	/*  ===========  */
	std::vector<std::pair<Equipment, std::pair<int, int>>> archerShop;

	// Create Weapon/Armor Objects for the Shop
	Weapon oakbow("Oak Bow", "Bow", "", "", 14, NULL);

	Armor leatherhelm("Leather Cowl", "Headpiece", "", 1, NULL);
	Armor leatherchest("Leather Tunic", "Chestpiece", "", 2, NULL);
	Armor leatherlegs("Leather Chaps", "Leggings", "", 2, NULL);
	Armor leatherboots("Leather Boots", "Boots", "", 1, NULL);

	// Add each Weapon/Armor Object to the Shop & Set Prices
	archerShop.push_back(std::make_pair(oakbow, std::make_pair(1, 125)));

	archerShop.push_back(std::make_pair(leatherhelm, std::make_pair(2, 65)));
	archerShop.push_back(std::make_pair(leatherchest, std::make_pair(3, 95)));
	archerShop.push_back(std::make_pair(leatherlegs, std::make_pair(4, 95)));
	archerShop.push_back(std::make_pair(leatherboots, std::make_pair(5, 65)));


	/*  Rogue Shop  */
	/*  ==========  */
	std::vector<std::pair<Equipment, std::pair<int, int>>> rogueShop;

	// Create Weapon/Armor Objects for the Shop
	Weapon irondagger_m("Iron Dagger", "M-Dagger", "", "", 14, NULL);
	Weapon irondagger_o("Iron Dagger", "O-Dagger", "", "", 7, NULL);

	Armor clothhelm("Cloth Hood", "Headpiece", "", 1, NULL);
	//	Armor leatherchest("Leather Tunic", "Chestpiece", "", 2, NULL);
	Armor clothlegs("Cloth Pants", "Leggings", "", 1, NULL);
	//	Armor leatherboots("Leather Boots", "Boots", "", 1, NULL);

		// Add each Weapon/Armor Object to the Shop & Set Prices
	rogueShop.push_back(std::make_pair(irondagger_m, std::make_pair(1, 125)));
	rogueShop.push_back(std::make_pair(irondagger_o, std::make_pair(2, 65)));

	rogueShop.push_back(std::make_pair(clothhelm, std::make_pair(3, 65)));
	rogueShop.push_back(std::make_pair(leatherchest, std::make_pair(4, 95)));
	rogueShop.push_back(std::make_pair(clothlegs, std::make_pair(5, 65)));
	rogueShop.push_back(std::make_pair(leatherboots, std::make_pair(6, 65)));


	/*  Mage Shop  */
	/*  =========  */
	std::vector<std::pair<Equipment, std::pair<int, int>>> mageShop;

	// Create Weapon/Armor Objects for the Shop
	Weapon oakwand("Oak Wand", "M-Wand", "", "", 12, NULL);
	Weapon basicspellbook("Book of Spells", "O-Wand", "", "", 12, NULL);

	Armor clothwizardhelm("Wizard's Cloth Hood", "Headpiece", "", 1, NULL);
	Armor clothwizardchest("Wizard's Cloth Robe", "Chestpiece", "", 1, NULL);
	Armor clothwizardlegs("Wizard's Cloth Pants", "Leggings", "", 1, NULL);
	Armor clothwizardboots("Wizard's Cloth Soles", "Boots", "", 1, NULL);

	// Add each Weapon/Armor Object to the Shop & Set Prices
	mageShop.push_back(std::make_pair(oakwand, std::make_pair(1, 100)));
	mageShop.push_back(std::make_pair(basicspellbook, std::make_pair(2, 100)));

	mageShop.push_back(std::make_pair(clothwizardhelm, std::make_pair(3, 65)));
	mageShop.push_back(std::make_pair(clothwizardchest, std::make_pair(4, 65)));
	mageShop.push_back(std::make_pair(clothwizardlegs, std::make_pair(5, 65)));
	mageShop.push_back(std::make_pair(clothwizardboots, std::make_pair(6, 65)));


	/*  Misc. Shop  */
	/*  ==========  */
	std::vector<std::pair<Equipment, std::pair<int, int>>> miscShop;

	// Create Item Objects for the Shop
	Item healthpot("Health Potion", "Potion", "HP+20", 101);

	// Add each Item Object to the Shop & Set Prices
	miscShop.push_back(std::make_pair(healthpot, std::make_pair(0, 50)));
	miscShop.push_back(std::make_pair(healthpot, std::make_pair(0, 100)));
	miscShop.push_back(std::make_pair(healthpot, std::make_pair(0, 150)));


	/*  ==========================  */
	/*  ===  Create Character  ===  */
	/*  ==========================  */
	std::cout << std::endl << std::endl;

	// User inputs their character name
	// Sets it to the 'Name' variable
	Name = getInput("  What is your name?");

	// Choose Character Class
	std::cout << "\n  Please pick a class from the following:";
	std::cout << "\n\tA) Warrior";
	std::cout << "\n\tB) Archer";
	std::cout << "\n\tC) Rogue";
	std::cout << "\n\tD) Mage";
	userChoice = choiceABC("ABCD");

	// If user chooses Warrior class (inputs 'A' / 'a')
	if (userChoice == 'A')
	{
		// Set 'Class' variable to "Warrior"
		Class = "Warrior";
	} // OR...

	// If user chooses Archer class (inputs 'B' / 'b')
	else if (userChoice == 'B')
	{
		// Set 'Class' variable to "Archer"
		Class = "Archer";
	} // OR...

	// If user chooses Rogue class (inputs 'C' / 'c')
	else if (userChoice == 'C')
	{
		// Set 'Class' variable to "Warrior"
		Class = "Rogue";
	} // OR...

	// If user chooses Mage class (inputs 'D' / 'd')
	else if (userChoice == 'D')
	{
		// Set 'Class' variable to "Archer"
		Class = "Mage";
	}

	// Set different locations for the player
	std::string area[6] = { "in town", "on the road", "in the mountains", "in a cave", "in a hole",
		"in a castle" };

	// Create Character Object
	Character player(Name, area[0], Class, 1, 0);


	/*  ====================================  */
	/*  ===  Give Player Starting Items  ===  */
	/*  ====================================  */

	// Set player's starting currency
	player.setCurrency(2500);
	// Add some starting Health Potions to the player's inventory
	player.addMultipleToInv(healthpot, 4);

	// If the player chose the Warrior class
	if (player.getClass() == "Warrior")
	{
		// Create starting Armor & Weapon objects
		Armor rustedplate("Rusted Iron Chestplate", "Chestpiece", "", 1, 70);
		Weapon rustysword("Rusty Sword", "M-Sword", "", "", 8, 65);

		// Have the player equip the starting chestpiece & weapon
		player.equipArmor(rustedplate);
		player.equipWeapon(rustysword);
	} // OR...

	// If the player chose the Archer class
	else if (player.getClass() == "Archer")
	{
		// Create starting Armor & Weapon objects
		Armor worntunic("Worn Leather Tunic", "Chestpiece", "", 1, 70);
		Weapon oldshortbow("Old Shortbow", "Bow", "", "", 6, 65);

		// Have the player equip the starting chestpiece & weapon
		player.equipArmor(worntunic);
		player.equipWeapon(oldshortbow);
	} // OR...

	// If the player chose the Rogue class
	else if (player.getClass() == "Rogue")
	{
		// Create starting Armor & Weapon objects
		Armor wornshoes("Worn Running Shoes", "Boots", "", 1, 70);
		Weapon rustyknife("Rusty Knife", "M-Dagger", "", "", 5, 65);

		// Have the player equip the starting boots & weapon
		player.equipArmor(wornshoes);
		player.equipWeapon(rustyknife);
	} // OR...

	// If the player chose the Mage class
	else if (player.getClass() == "Mage")
	{
		// Create starting Armor & Weapon objects
		Armor tatteredrobe("Tattered Robe", "Chestpiece", "", 0, 70);
		Weapon oldwand("Second-Hand Wand", "M-Wand", "", "", 6, 65);

		// Have the player equip the starting chestpiece & weapon
		player.equipArmor(tatteredrobe);
		player.equipWeapon(oldwand);
	}

	// Clear console window
	clear();


	/*  =================================  */
	/*  ===  Display Starting Status  ===  */
	/*  =================================  */

	player.Overview();  // Display player overview
	std::cout << std::endl << std::endl;  // Line break

	std::this_thread::sleep_for(std::chrono::milliseconds(1000));  // Pause 1 sec


	/*  ====================  */
	/*  ===  Play Intro  ===  */
	/*  ====================  */

	// Welcome message
	std::cout << "\n  Welcome, " << player.getName() << "." << std::endl;
	std::cout << "\n  You find yourself in a modest inn. A tad small, but warm.\n" << 
		"  You look outside and remember that you're " << player.getArea() << "." << std::endl;

	/*  SHOP IN TOWN  */

	// Ask player whether to shop or not
	std::cout << "\n  Your spare change from your last quest is burning a hole in your pocket.\n" <<
		"  Would you like to take a look at the general store before starting on your journey?" << std::endl;
	// Get user input (Yes or No)
	choice = choiceYesNo("Yes", "No");

	// If user chooses to shop (inputs 'Y' / 'y')
	if (choice == true)
	{
		sleep(500);  // Pause 1/2 sec

		clear();  // Clear console window

		// Shopkeep intro
		std::cout << "\n  Shopkeep: Af'ernoon!";
		std::cout << "\n  Shopkeep: What can I get yer' for?" << std::endl;

		// If the player is the Warrior class
		if (player.getClass() == "Warrior")
		{
			// Run the method to open the shop
			// Have the shop display Warrior items
			player = Shop("Warrior", player, warriorShop, miscShop);
		} // OR...

		// If the player is the Archer class
		else if (player.getClass() == "Archer")
		{
			// Run the method to open the shop
			// Have the shop display Archer items
			player = Shop("Archer", player, archerShop, miscShop);
		} // OR...

		// If the player is the Rogue class
		else if (player.getClass() == "Rogue")
		{
			// Run the method to open the shop
			// Have the shop display Rogue items
			player = Shop("Rogue", player, rogueShop, miscShop);
		} // OR...

		// If the player is the Mage class
		else if (player.getClass() == "Mage")
		{
			// Run the method to open the shop
			// Have the shop display Mage items
			player = Shop("Mage", player, mageShop, miscShop);
		}

		std::this_thread::sleep_for(std::chrono::milliseconds(500));  // Pause 1/2 sec

		std::cout << std::endl;	  // Line break
		player.viewInv(); // Display player inventory
		std::cout << std::endl;	  // Line break
	}

	std::cout << "\n  Press ENTER to begin your journey towards the Mountains!";
	std::cin.ignore();

	clear();  // Clear console window

	// Update the player's area to the next one (on the road)
	player.setArea(area[1]);

	std::cout << "\n  You begin your journey towards the Mountains.\n" << std::endl;

	std::cout << "  .";
	sleep(1000);
	std::cout << " .";
	sleep(1000);
	std::cout << " .";
	sleep(1000);
	std::cout << " .";
	sleep(1000);
	std::cout << " .";
	sleep(1000);
	std::cout << " .";
	sleep(1000);
	std::cout << " .";
	sleep(1000);
	std::cout << " .";
	sleep(1000);
	std::cout << " .";
	sleep(1000);
	std::cout << " .";
	sleep(1000);

	/*  ======================  */
	/*  ===  First Battle  ===  */
	/*  ======================  */

	// Output scene intro
	std::cout << "\n\n  After a couple of hours " << player.getArea() << ", a group of goblins suddenly jump out at you!";

	sleep(2500);

	std::cout << "\n\n  It's an ambush!!";

	sleep(1500);

	std::cout << std::endl;

	// Run the first battle
	// Upon completion, the player object
	// is updated with any added experience,
	// increased levels/stats, and updated
	// status (health, mana, etc.)
	player = Battle1(player);

	// Completion notification
	//   - Currently, only 1 battle is included
	std::cout << "\n  After the fight with the goblins, you make your way" << std::endl;
	std::cout << "  to the mountains and find the treasure you were looking for." << std::endl;

	std::cout << "\n  Congratulations! You have completed your epic quest!" << std::endl;

	return 0; // End Program
}



/*

- Make MP (Mana) calculated as a double (MP is currently an int)

- Set more realistic attack damage variations between classes in Character::setDamage()

- Change item names for clarification
- i.e. Iron Sword (1H) --> Iron Broadsword (1H)

- Add a coin amount to enemies for collection upon death (similar to enemy experience)

- Decide upon a reasonable starting currency amount for players
- i.e. Enough to buy some items, but not a full equip

- Alter the getDamage() algorithm to incorporate a proper damage decrease for "dodging"
  a full blow with agility (include an algorithm-based random chance for attack miss)

- Add another battle after the first one

- Overhaul the Battle() method to generalize it for any type & number of enemies.

*/