/*  Source Code for Character Class  */

/*  Header Libary Import(s)  */
/*  =======================  */
#include "Character.h"  // Character Class


/*  Constructors  */
Character::Character()
{  // Default

	// Set all default fall-back variables
	// for the Character object.

	// If another Constructor doesn't set
	// any of these variables specifically,
	// it defaults back to these set values.

	setName("");
	setClass("");
	setLevel(NULL);

	setSTR(NULL);
	setDEF(NULL);
	setAGI(NULL);
	setSTA(NULL);
	setINT(NULL);
	setVIT(NULL);

	setSTRBoost(NULL);
	setDEFBoost(NULL);
	setAGIBoost(NULL);
	setSTABoost(NULL);
	setINTBoost(NULL);
	setVITBoost(NULL);
}

Character::Character(std::string name, std::string location, std::string profession, int level=1, int experience=0)
{
	// Initialize stat variables
	int strength;
	int defense;
	int agility;
	int stamina;
	int intelligence;
	int vitality;

	// Set variables for the Character object
	setName(name);
	setLocation(location);
	setClass(profession);
	setLevel(level);
	setEXP(experience);
	setEXPReq();

	// If the player chose the Warrior class:
	if (getClass() == "Warrior")
	{
		// Set stat values for class
		strength = 4;
		defense = 4;
		agility = 1;
		stamina = 2;
		intelligence = 1;
		vitality = 20;
	}
	// If the player chose the Archer class:
	else if (getClass() == "Archer")
	{
		// Set stat values for class
		strength = 2;
		defense = 2;
		agility = 4;
		stamina = 2;
		intelligence = 1;
		vitality = 15;
	}
	// If the player chose the Rogue class:
	else if (getClass() == "Rogue")
	{
		// Set stat values for class
		strength = 3;
		defense = 1;
		agility = 5;
		stamina = 2;
		intelligence = 1;
		vitality = 10;
	}
	// If the player chose the Mage class:
	else if (getClass() == "Mage")
	{
		// Set stat values for class
		strength = 1;
		defense = 1;
		agility = 2;
		stamina = 2;
		intelligence = 6;
		vitality = 12;
	}

	// Set player stats
	setSTR(strength);
	setDEF(defense);
	setAGI(agility);
	setSTA(stamina);
	setINT(intelligence);
	setVIT(vitality);

	// Set stat boosts to zero
	setSTRBoost(0);
	setDEFBoost(0);
	setAGIBoost(0);
	setSTABoost(0);
	setINTBoost(0);
	setVITBoost(0);

	// Calculate player's maximum health & mana
	setMaxHealth(getVIT() * 10.0); // VIT Stat x 10
	setMaxMana(getINT() * 20);     // INT Stat x 20

	// Set health & mana to their respective maxes
	setHealth(getMaxHealth());
	setMana(getMaxMana());

	// Set damage modifier to zero & damage to one
	// (this gets set when weapons are equipped)
	setDamageModifier(0);
	setDamage(1);
}


/*  Method(s)  */
void Character::Stats()
{
	// Title
	std::cout << "\t\t=============================" << std::endl;
	std::cout << "\t\t*** Character Information ***" << std::endl;
	std::cout << "\t\t=============================" << std::endl;
	// Basic info
	std::cout << "Name   : " << getName() << std::endl;
	std::cout << "Class  : " << getClass() << std::endl;
	std::cout << "Level  : " << getLevel() << std::endl;
	// Experience
	std::cout << "EXP    : (" << getEXP() << "/" << getEXPReq() << ")" << std::endl;
	// Health / Mana
	std::cout << "Health : (" << getHealth() << "/" << getMaxHealth() << ")" << std::endl;
	std::cout << "Mana   : " << getMana() << "/" << getMaxMana() << ")" << std::endl;
	std::cout << "=====================" << std::endl;
	// Stats
	std::cout << "STR: " << getSTR() << " [+" << getSTRBoost() << "]" << std::endl;
	std::cout << "AGI: " << getAGI() << " [+" << getAGIBoost() << "]" << std::endl;
	std::cout << "DEF: " << getDEF() << " [+" << getDEFBoost() << "]" << std::endl;
	std::cout << "STA: " << getSTA() << " [+" << getSTABoost() << "]" << std::endl;
	std::cout << "INT: " << getINT() << " [+" << getINTBoost() << "]" << std::endl;
}

void Character::addToInv(Equipment item)
{
	// Add the given Equipment (Weapon, Armor, or Item)
	// object to the vector<Equipment> 'INVENTORY'
	INVENTORY.push_back(item);
}
void Character::addMultipleToInv(Equipment item, int num)
{
	// Add the given # of Equipment (Item) objects
	// to the vector<Equipment> 'INVENTORY'
	INVENTORY.insert(INVENTORY.end(), num, item);
}
void Character::removeFromInv(Equipment item)
{
	// Initalize variables
	std::vector<std::string> items;
	int index;
	// Get the Equipment (Weapon, Armor, or Item) object name
	std::string itemToRemove = item.getName();

	// Loop for the amount items in the player inventory
	for (unsigned int i = 0; i < INVENTORY.size(); i++)
		// Make a copy of each item name in the player inventory
		items.insert(items.begin() + i, INVENTORY[i].getName());

	// Initialize an iterator to find the index of the item name to remove
	std::vector<std::string>::iterator itr = find(items.begin(), items.end(), itemToRemove);

	// Get the item's index to remove
	if (itr != items.cend()) index = distance(items.begin(), itr);

	// Erase the object from the player inventory
	INVENTORY.erase(INVENTORY.begin() + index);
}
void Character::viewInv()
{
	// Title
	std::cout << "\n=================";
	std::cout << "\n*** Equipment ***";
	std::cout << "\n=================\n";

	// Initialize strings for every wearable equipment
	std::string helmS;
	std::string chestS;
	std::string legsS;
	std::string bootsS;
	std::string mainHandS;
	std::string offHandS;
	std::string oneHandedS;
	std::string shieldS;

	// Loop for the amount items the player has equipped
	for (unsigned int i = 0; i < EQUIPPED.size(); i++)
	{
		// Get the values for all equipped items and override
		// their public variables in the Character object
		if (EQUIPPED[i].getType() == "Headpiece")
			helm = &EQUIPPED[i];

		else if (EQUIPPED[i].getType() == "Chestpiece")
			chest = &EQUIPPED[i];

		else if (EQUIPPED[i].getType() == "Leggings")
			legs = &EQUIPPED[i];

		else if (EQUIPPED[i].getType() == "Boots")
			boots = &EQUIPPED[i];


		else if (EQUIPPED[i].getType().rfind("M-", 0) == 0)
			mainHand = &EQUIPPED[i];

		else if (EQUIPPED[i].getType().rfind("O-", 0) == 0)
			offHand = &EQUIPPED[i];

		else if (EQUIPPED[i].getType().rfind("1H-", 0) == 0 || EQUIPPED[i].getType() == "Bow")
			oneHanded = &EQUIPPED[i];

		else if (EQUIPPED[i].getType() == "Shield")
			shield = &EQUIPPED[i];
	}

	/*	After all items have been detected:
		( items not equipped have their corresponding
		  Equipment* pointer still set to NULL )
	   =============================================== */

	// Check if each type of armor is equipped or not
	// If an armor piece is equipped, retrieve its name
	if (helm != NULL) helmS = helm->getName();
	else helmS = "N/A";

	if (chest != NULL) chestS = chest->getName();
	else chestS = "N/A";

	if (legs != NULL) legsS = legs->getName();
	else legsS = "N/A";

	if (boots != NULL) bootsS = boots->getName();
	else bootsS = "N/A";

	// Check if each type of weapon is equipped or not
	// If a weapon is equipped, retrieve its name
	if (mainHand != NULL) mainHandS = mainHand->getName();

	if (offHand != NULL) offHandS = offHand->getName();

	if (oneHanded != NULL) oneHandedS = oneHanded->getName();

	if (shield != NULL) shieldS = shield->getName();

	/*	After all string names have been set:
		( items not equipped have their corresponding
		  string names set to "N/A" )
	   ===============================================	*/

	// If a headpiece is equipped, output its defense boost value
	if (helm != NULL) std::cout << "    Headpiece  : " << helmS << " [DEF+" << helm->getDefense() << "]" << std::endl;
	// Otherwise, don't
	else std::cout << "    Headpiece  : " << helmS << std::endl;

	// If a chestpiece is equipped, output its defense boost value
	if (chest != NULL) std::cout << "    Chestpiece : " << chestS << " [DEF+" << chest->getDefense() << "]" << std::endl;
	// Otherwise, don't
	else std::cout << "    Chestpiece : " << chestS << std::endl;

	// If leggings are equipped, output its defense boost value
	if (legs != NULL) std::cout << "    Leggings   : " << legsS << " [DEF+" << legs->getDefense() << "]" << std::endl;
	// Otherwise, don't
	else std::cout << "    Leggings   : " << legsS << std::endl;

	// If boots are equipped, output its defense boost value
	if (boots != NULL) std::cout << "    Boots      : " << bootsS << " [DEF+" << boots->getDefense() << "]" << std::endl;
	// Otherwise, don't
	else std::cout << "    Boots      : " << bootsS << std::endl;


	/* Output Equipped Weapon(s) */

	// One-Handed
	if (oneHanded != NULL && (mainHand == NULL && offHand == NULL) && shield == NULL)
		std::cout << "\n    Weapon: " << oneHandedS << " [DMG: " << oneHanded->getPower() << "]" << std::endl;
	// Main-Hand & Off-Hand
	else if (oneHanded == NULL && (mainHand != NULL && offHand != NULL) && shield == NULL)
	{
		std::cout << "\n    Main Hand : " << mainHandS << " [DMG: " << mainHand->getPower() << "]" << std::endl;
		std::cout << "    Off Hand  : " << offHandS << " [DMG: " << offHand->getPower() << "]" << std::endl;
	}
	// Main-Hand
	else if (oneHanded == NULL && (mainHand != NULL && offHand == NULL) && shield == NULL)
	{
		std::cout << "\n    Main Hand : " << mainHandS << " [DMG: " << mainHand->getPower() << "]" << std::endl;
		std::cout << "    Off Hand  : N/A" << std::endl;
	}
	// Off-Hand
	else if (oneHanded == NULL && (mainHand == NULL && offHand != NULL) && shield == NULL)
	{
		std::cout << "\n    Main Hand : N/A" << std::endl;
		std::cout << "    Off Hand  : " << offHandS << " [DMG: " << offHand->getPower() << "]" << std::endl;
	}
	// Main-Hand & Shield
	else if (oneHanded == NULL && (mainHand != NULL && offHand == NULL) && shield != NULL)
	{
		std::cout << "\n    Main Hand : " << mainHandS << " [DMG: " << mainHand->getPower() << "]" << std::endl;
		std::cout << "    Off Hand  : " << shieldS << " [DEF+" << shield->getDefense() << "]" << std::endl;
	}
	// Shield
	else if (oneHanded == NULL && (mainHand == NULL && offHand == NULL) && shield != NULL)
	{
		std::cout << "\n    Main Hand : N/A" << std::endl;
		std::cout << "    Off Hand  : " << shieldS << " [DEF+" << shield->getDefense() << "]" << std::endl;
	}
	// Empty
	else std::cout << "\n    Weapon(s): N/A" << std::endl;


	/* Output Inventory */
	/* ================ */

	// Title
	std::cout << "\n=================";
	std::cout << "\n*** Inventory ***";
	std::cout << "\n=================" << std::endl;

	// Initalize variables
	std::vector<std::string> items;
	std::map<std::string, size_t> results;

	// Loop for the amount items in the player inventory
	for (unsigned int i = 0; i < INVENTORY.size(); i++)
	{
		// Copy all item names from player inventory
		items.insert(items.begin() + i, INVENTORY[i].getName());
		// Make a pair of all item names from the player inventory and zero
		//   (0 is the starting number for getting item amounts)
		// i.e. ("Health Potion", 4)  =  4 health potion
		results.insert(make_pair(INVENTORY[i].getName(), 0));
	}

	// For each item, add 1 to their item # (2nd map value)
	for_each(begin(items), end(items), [&](std::string const& s) { ++results[s]; });

	// Loop for the amount items in the player inventory
	for (auto it = results.cbegin(); it != results.cend(); ++it)
		// Output player inventory with # of items
		//   i.e. "Health Potion (x4)"
		std::cout << "    " << it->first << " (x" << it->second << ")" << std::endl;


	/* Output Currency */
	/* =============== */

	// Title
	std::cout << "\n===================";
	std::cout << "\n*** Money Pouch ***";
	std::cout << "\n===================" << std::endl;
	// Amount of Gold
	std::cout << "    Gold   : " << getGold() << std::endl;
	// Amount of Silver
	std::cout << "    Silver : " << getSilver() << std::endl;
	// Amount of Copper
	std::cout << "    Copper : " << getCopper() << std::endl;
}

void Character::equipWeapon(Equipment item)
{
	// Add the given Equipment (weapon) object to the 'EQUIPPED' vector
	EQUIPPED.push_back(item);
	// Update the player's damage modifer (by adding the weapon's damage)
	setDamageModifier(getDamageModifier() + item.getPower());
	// Update the player's base damage with the newly updated damage modifier
	setDamage(getDamageModifier());
}
void Character::equipArmor(Equipment item)
{
	// Add the given Equipment (Armor) object to the 'EQUIPPED' vector
	EQUIPPED.push_back(item);
	// Update the player's Defense stat boost (by adding the weapon's defense modifier)
	setDEFBoost(getDEFBoost() + item.getDefense());
}

void Character::unequipWeapon(Equipment item)
{
	// Initialize variables
	std::vector<std::string> items;
	int index;
	// Get Equipment (Weapon) object name
	std::string itemToRemove = item.getName();

	// Update the player's damage modifier (by subtracting the weapon's damage)
	setDamageModifier(getDamageModifier() - item.getPower());

	// If the updated damage modifer is greater than 0 (another weapon is still equipped):
	//     Update the player's base damage with the new damage modifier
	if (getDamageModifier() > 0) setDamage(getDamageModifier());
	// If the player has no weapons equipped, set the damage modifier back to the default (1)
	else setDamage(1);

	// Loop for the amount items the player has equipped
	for (unsigned int i = 0; i < EQUIPPED.size(); i++)
		// Make a copy of each item name the player has equipped
		items.insert(items.begin() + i, EQUIPPED[i].getName());

	// Initialize an iterator to find the index of the item name to unequip
	std::vector<std::string>::iterator itr = find(items.begin(), items.end(), itemToRemove);

	// Get the item's index to remove
	if (itr != items.cend()) index = distance(items.begin(), itr);

	// Erase the object from the 'EQUIPPED' vector
	EQUIPPED.erase(EQUIPPED.begin() + index);
}
void Character::unequipArmor(Equipment item)
{
	// Initalize variables
	std::vector<std::string> items;
	int index;
	// Get Equipment (Armor) object name
	std::string itemToRemove = item.getName();

	// Update the player's Defense boost modifier (by subtracting the armor's defense value)
	setDEFBoost(getDEFBoost() - item.getDefense());

	// Loop for the amount items the player has equipped
	for (unsigned int i = 0; i < EQUIPPED.size(); i++)
		// Make a copy of each item name the player has equipped
		items.insert(items.begin() + i, EQUIPPED[i].getName());

	// Initialize an iterator to find the index of the item name to unequip
	std::vector<std::string>::iterator itr = find(items.begin(), items.end(), itemToRemove);

	// Get the item's index to remove
	if (itr != items.cend()) index = distance(items.begin(), itr);

	// Erase the object from the 'EQUIPPED' vector
	EQUIPPED.erase(EQUIPPED.begin() + index);
}


/*  Encapsulation Methods  */
// NAME
void Character::setName(std::string name)
{
	NAME = name;
}
std::string Character::getName()
{
	return NAME;
}

// LOCATION
void Character::setLocation(std::string area)
{
	LOCATION = area;
}
std::string Character::getLocation()
{
	return LOCATION;
}

// CLASS
void Character::setClass(std::string type)
{
	CLASS = type;
}
std::string Character::getClass()
{
	return CLASS;
}

// LVL
void Character::setLevel(int level)
{
	LVL = level;
}
int Character::getLevel()
{
	return LVL;
}

// EXP
void Character::setEXP(int xp)
{
	EXP = xp;
}
int Character::getEXP()
{
	return EXP;
}

// EXPReq
void Character::setEXPReq()
{
	EXPReq = 70 + ((getLevel() * getLevel()) * 35);
}
int Character::getEXPReq()
{
	return EXPReq;
}

// maxHP
void Character::setMaxHealth(double hp_max)
{
	maxHP = hp_max;
}
double Character::getMaxHealth()
{
	return maxHP;
}

// maxMP
void Character::setMaxMana(int mp_max)
{
	maxMP = mp_max;
}
int Character::getMaxMana()
{
	return maxMP;
}

// HP
void Character::setHealth(double hp)
{
	HP = hp;
}
double Character::getHealth()
{
	return HP;
}

// MP
void Character::setMana(int mp)
{
	MP = mp;
}
int Character::getMana()
{
	return MP;
}



// STR
void Character::setSTR(int strength)
{
	STR = strength;
}
int Character::getSTR()
{
	return STR;
}

// DEF
void Character::setDEF(int defense)
{
	DEF = defense;
}
int Character::getDEF()
{
	return DEF;
}

// AGI
void Character::setAGI(int agility)
{
	AGI = agility;
	setDodgeRate(agility);
}
int Character::getAGI()
{
	return AGI;
}

// STA
void Character::setSTA(int stamina)
{
	STA = stamina;
}
int Character::getSTA()
{
	return STA;
}

// INT
void Character::setINT(int intelligence)
{
	INT = intelligence;
}
int Character::getINT()
{
	return INT;
}

// VIT
void Character::setVIT(int vitality)
{
	VIT = vitality;
}
int Character::getVIT()
{
	return VIT;
}



// STRboost
void Character::setSTRBoost(int boost)
{
	STRboost = boost;
}
int Character::getSTRBoost()
{
	return STRboost;
}

// DEFboost
void Character::setDEFBoost(int boost)
{
	DEFboost = boost;
}
int Character::getDEFBoost()
{
	return DEFboost;
}

// AGIboost
void Character::setAGIBoost(int boost)
{
	AGIboost = boost;
	setDodgeRate(getAGI() + boost);
}
int Character::getAGIBoost()
{
	return AGIboost;
}

// STAboost
void Character::setSTABoost(int boost)
{
	STAboost = boost;
}
int Character::getSTABoost()
{
	return STAboost;
}

// INTboost
void Character::setINTBoost(int boost)
{
	INTboost = boost;
}
int Character::getINTBoost()
{
	return INTboost;
}

// VITboost
void Character::setVITBoost(int boost)
{
	VITboost = boost;
}
int Character::getVITBoost()
{
	return VITboost;
}



// atkDamage
void Character::setDamage(int dmg)
{
	// Warrior
	if (getClass() == "Warrior")
		atkDamage = (dmg * (getLevel()) + ((getSTR() * getLevel()) / 2));
	// Archer
	else if (getClass() == "Archer")
		atkDamage = (dmg * (getLevel()) + ((getAGI() * getLevel()) / 2));
	// Rogue
	else if (getClass() == "Rogue")
		atkDamage = (dmg * (getLevel()) + ((getSTR() * getLevel()) / 2));
	// Mage
	else if (getClass() == "Mage")
		atkDamage = (dmg * (getLevel()) + ((getINT() * getLevel()) / 2));
	// DEFAULT
	else
		atkDamage = (5 * (getLevel()) + ((getSTR() * getLevel()) / 2));
}
int Character::getDamage()
{
	return atkDamage;
}

// dmgModifier
void Character::setDamageModifier(int modifier)
{
	dmgModifier = modifier;
}
int Character::getDamageModifier()
{
	return dmgModifier;
}

// dodgeRate
void Character::setDodgeRate(int agi)
{
	int DIVIDE = agi + 3;
	dodgeRate = ((.6 * agi) / DIVIDE);
}
double Character::getDodgeRate()
{
	return dodgeRate;
}



// currency
void Character::setCurrency(int amount)
{
	currency = amount;

	setGold();
	setSilver();
	setCopper();
}
int Character::getCurrency()
{
	return currency;
}

// gold
void Character::setGold()
{
	gold = (getCurrency() / 1000);
}
int Character::getGold()
{
	return gold;
}

// silver
void Character::setSilver()
{
	silver = ((getCurrency() - (gold * 1000)) / 100);
}
int Character::getSilver()
{
	return silver;
}

// copper
void Character::setCopper()
{
	copper = (getCurrency() - (gold * 1000) - (silver * 100));
}
int Character::getCopper()
{
	return copper;
}



// TYPE
