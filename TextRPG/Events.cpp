/*  'Events' Source Code  */

/*  Header Libary Import(s)  */
/*  =======================  */
#include "Events.h"

#include <thread>		// Execution Thread Library
#include <chrono>		// Time Manipulation Library
#include <sstream>		// Typedef Input/Output Library


/*  ==================================  */
/*  === Experience Updating Method ===  */
/*  ==================================  */
Character CalculateEXP(Character player, Enemy enemy)
{
	// Title
	std::cout << "\n  ###############\n  Calculating EXP\n  ###############" << std::endl;

	std::this_thread::sleep_for(std::chrono::milliseconds(1000));  // Pause 1 sec

	// Add EXP gained from slaying the enemy
	player.setEXP(player.getEXP() + enemy.getEXP());

	// Output updated player EXP
	std::cout << "  EXP: (" << player.getEXP() << "/" << player.getEXPReq() << ")" << std::endl;

	// If the player now has enough EXP to LVL-Up, run the LevelUp() method
	if (player.getEXP() >= player.getEXPReq())
		player = LevelUp(player);

	// Return updated player object
	return player;
}

/*  =======================  */
/*  === Level-Up Method ===  */
/*  =======================  */
Character LevelUp(Character player)
{
	// Add 1 to player level
	player.setLevel(player.getLevel() + 1);

	// Subtract required EXP for LVL-Up
	player.setEXP(abs(player.getEXP() - player.getEXPReq()));

	// Update required EXP for next LVL-Up
	player.setEXPReq();

	// Set player health back to full
	player.setHealth(player.getMaxHealth());

	// Output LVL-Up message
	std::cout << "\n  Level Up! You are now level " << player.getLevel() << "!\n";
	std::cout << "  EXP: (" << player.getEXP() << "/" << player.getEXPReq() << ")\n" << std::endl;
	
	// Output updated player stats
	player.Stats();

	// Return updated player object
	return player;
}

/*  ===========================  */
/*  === Player Death Method ===  */
/*  ===========================  */
void Death()
{
	// Output death message
	std::cout << "\n  You have died and failed your epic quest!!" << std::endl;
}

/*  =======================================================  */
/*  === Method to Format a Currency Total Into a Vector ===  */
/*  =======================================================  */
std::vector<int> GetItemCost(int amount)
{
	// Initialize vector<int> 'currency'
	std::vector<int> currency;

	// Initialize integers for currency types
	int gold;
	int silver;
	int copper;

	// If the cost divides by 1000 evenly
	//   (multiple of 1000 -- 1000, 2000, 3000, etc.)
	if (amount % 1000 == 0)
	{
		// Calculate the # of gold from the total cost
		gold = (amount / 1000);

		// Add the # of gold to currency[0]
		currency.push_back(gold);
		// Add 0 silver currency[1]
		currency.push_back(0);
		// Add 0 copper currency[2]
		currency.push_back(0);
	}  // OR

	// If the cost is greater than 1000 (but not an exact multiple)
	else if (amount > 1000)
	{
		// Calculate the # of gold from the total cost
		gold = (amount / 1000);
		// Calculate the # of silver from the total cost
		silver = ((amount - (gold * 1000)) / 100);
		// Calculate the # of copper from the total cost
		copper = (amount - (gold * 1000) - (silver * 100));

		// Add the # of gold to currency[0]
		currency.push_back(gold);
		// Add the # of silver to currency[1]
		currency.push_back(silver);
		// Add the # of copper to currency[2]
		currency.push_back(copper);
	}  // OR

	// If the cost divides by 100 evenly
	//   (multiple of 100 -- 100, 200, 300, etc.)
	else if (amount % 100 == 0)
	{
		// Calculate the # of silver from the total cost
		silver = (amount / 100);

		// Add 0 gold to currency[0]
		currency.push_back(0);
		// Add the # of silver to currency[1]
		currency.push_back(silver);
		// Add 0 copper to currency[2]
		currency.push_back(0);
	}  // OR

	// If the cost is greater than 100 (but not an exact multiple)
	else if (amount > 100)
	{
		// Calculate the # of silver from the total cost
		silver = (amount / 100);
		// Calculate the # of copper from the total cost
		copper = (amount - (silver * 100));

		// Add 0 gold to currency[0]
		currency.push_back(0);
		// Add the # of silver to currency[1]
		currency.push_back(silver);
		// Add the # of copper to currency[2]
		currency.push_back(copper);
	}  // Otherwise...
	// If the cost is less than 100 (just copper, no silver or gold)
	else
	{
		// Set the # of copper to the cost
		copper = amount;

		// Add 0 gold to currency[0]
		currency.push_back(0);
		// Add 0 silver to currency[1]
		currency.push_back(0);
		// Add the # of copper to currency[2]
		currency.push_back(copper);
	}

	// Return vector<int> 'currency' --
	//   -   gold is stored in currency[0]
	//   - silver is stored in currency[1]
	//   - copper is stored in currency[2]
	return currency;
}

/*  ===============================================  */
/*  === Method to Format the Cost of Shop Items ===  */
/*  ===============================================  */
std::string GetFormattedItemCost(int cost)
{
	// Initalize integer variables of currency types
	int gold = 0;
	int silver = 0;
	int copper = 0;

	// Initalize string 'itemCost' (final return value)
	std::string itemCost;
	// Initialize stringstream 'ss'
	std::stringstream ss;

	// If the cost divides by 1000 evenly
	//   (multiple of 1000 -- 1000, 2000, 3000, etc.)
	if (cost % 1000 == 0)
	{
		// Calculate the # of gold from the total cost
		gold = (cost / 1000);

		// If gold is 100+ (3 digits)
		if (gold > 99) {
			// Set the stringstream to # of gold (formatted)
			ss << "    -    - " << gold << "g";
		}  // OR
		// If gold is 10+ (2 digits)
		else if (gold > 9) {
			// Set the stringstream to # of gold (formatted - 1 space after 'g')
			ss << "    -    - " << gold << "g ";
		}  // Otherwise...
		// If gold is 1-9 (1 digit)
		else {
			// Set the stringstream to # of gold (formatted - 2 spaces after 'g')
			ss << "    -    - " << gold << "g  ";
		}
		// Set string 'itemCost' to the concatenated stringstream
		itemCost = ss.str();

	}  // OR

	// If the cost is greater than 1000 (but not an exact multiple)
	else if (cost > 1000)
	{
		// Calculate the # of gold from the total cost
		gold = (cost / 1000);
		// Calculate the # of silver from the total cost
		silver = ((cost - (gold * 1000)) / 100);
		// Calculate the # of copper from the total cost
		copper = (cost - (gold * 1000) - (silver * 100));

		/*  100 copper = 1 silver, so only 1 & 2 digit copper is calculated  */

		// If copper is 10+ (2 digits)
		if (copper > 9) {
			// Set the stringstream to # of copper (formatted)
			ss << copper << "c - ";
		}  // Otherwise...
		// If copper is 1-9 (1 digit)
		else {
			// Set the stringstream to # of copper (formatted - 1 space after 'c')
			ss << copper << "c  - ";
		}

		/*  10 silver = 1 gold, so only 1 digit silver is calculated  */

		// Add # of silver to the stringstream (formatted)
		ss << silver << "s - ";

		// If gold is 100+ (3 digits)
		if (gold > 99) {
			// Add # of gold to the stringstream (formatted)
			ss << gold << "g";
		}  // OR
		// If gold is 10+ (2 digits)
		else if (gold > 9) {
			// Add # of gold to the stringstream (formatted - 1 space after 'g')
			ss << gold << "g ";
		}  // Otherwise...
		// If gold is 1-9 (1 digit)
		else {
			// Add # of gold to the stringstream (formatted - 2 spaces after 'g')
			ss << gold << "g  ";
		}

		// Set string 'itemCost' to the concatenated stringstream
		itemCost = ss.str();
	}  // OR
	// If the cost divides by 100 evenly
	//   (multiple of 100 -- 100, 200, 300, etc.)
	else if (cost % 100 == 0)
	{
		/*  10 silver = 1 gold, so only 1 digit silver is calculated  */

		// Calculate the # of silver from the total cost
		silver = (cost / 100);

		// Set the stringstream to # of silver (formatted)
		ss << "    - " << silver << "s - ";

		// Add extra space to stringstream
		//   (to fill up the empty space that gold would be)
		ss << "    ";

		// Set string 'itemCost' to the concatenated stringstream
		itemCost = ss.str();

	}  // OR

	// If the cost is greater than 100 (but not an exact multiple)
	else if (cost > 100)
	{
		// Calculate the # of silver from the total cost
		silver = (cost / 100);
		// Calculate the # of copper from the total cost
		copper = (cost - (silver * 100));

		/*  100 copper = 1 silver, so only 1 & 2 digit copper is calculated  */

		// If copper is 10+ (2 digits)
		if (copper > 9) {
			// Set the stringstream to # of copper (formatted)
			ss << copper << "c - ";
		}  // Otherwise...
		// If copper is 1-9 (1 digit)
		else {
			// Set the stringstream to # of copper (formatted - 1 space after 'c')
			ss << copper << "c  - ";
		}

		/*  10 silver = 1 gold, so only 1 digit silver is calculated  */

		// Add # of silver to the stringstream (formatted)
		ss << silver << "s - ";

		// Add extra space to stringstream
		//   (to fill up the empty space that gold would be)
		ss << "    ";

		// Set string 'itemCost' to the concatenated stringstream
		itemCost = ss.str();

	}  // Otherwise...

	// If the cost is less than 100 (just copper, no silver or gold)
	else
	{
		// Set the # of copper to the cost
		copper = cost;

		/*  100 copper = 1 silver, so only 1 & 2 digit copper is calculated  */

		// If copper is 10+ (2 digits)
		if (copper > 9) {
			// Set the stringstream to # of copper (formatted)
			ss << copper << "c - ";
		}  // Otherwise...
		// If copper is 1-9 (1 digit)
		else {
			// Set the stringstream to # of copper (formatted - 1 space after 'c')
			ss << copper << "c  - ";
		}

		// Add extra space to stringstream
		//   (to fill up the empty space that silver & gold would be)
		ss << "   -     ";

		// Set string 'itemCost' to the concatenated stringstream
		itemCost = ss.str();
	}

	// Return string 'itemCost' -- the formatted item cost in gold, silver, & copper
	return itemCost;
}

/*  =========================================================  */
/*  === Method to Determine if a String Contains a Number ===  */
/*  =========================================================  */
bool IsNumber(const std::string& s)
{
	// Search through the entire string:
	//   If a non-digit character is found, return false
	//   If not, return true
	return !s.empty() && find_if(s.begin(),
		s.end(), [](unsigned char c) { return !isdigit(c); }) == s.end();
}