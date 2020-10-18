/*  Source Code for Enemy Class  */

/*  Header Libary Import(s)  */
/*  =======================  */
#include "Enemy.h"  // Enemy Class


/*  Constructor(s)  */
Enemy::Enemy()
{  // Default

	// Set all default fall-back variables
	// for the Enemy object.

	// If another Constructor doesn't set
	// any of these variables specifically,
	// it defaults back to these set values.

	setName("");
	setType("");
	setLevel(NULL);
	setMaxHealth(NULL);
	setMaxMana(NULL);

	setSTR(NULL);
	setAGI(NULL);
	setDEF(NULL);
	setSTA(NULL);
	setINT(NULL);

	setEXP(NULL);
}

Enemy::Enemy(std::string type, int level, int hp, int strength, int agility, int defense, int exp)
{  // Standard enemy with basic stats & no magic

	// Set variables for the Enemy object
	setType(type);
	setLevel(level);
	setMaxHealth(hp); // Enemy Max HP
	setHealth(hp);    // Enemy HP

	// Set stats for the Enemy object
	setSTR(strength);
	setDEF(defense);

	// Set experience to be collected upon the Enemy's death
	setEXP(exp);

	// Set the Enemy's damage
	setDamage(5);
}

Enemy::Enemy(std::string name, std::string type, int level, int hp, int mp, int strength, int agility, int defense, int stamina, int intelligence, int exp)
{  // Intelligent enemy with a name & magic ability

	// Set variables for the Enemy object
	setName(name);
	setType(type);
	setLevel(level);
	setMaxHealth(hp); // Enemy Max HP
	setHealth(hp);    // Enemy HP
	setMaxMana(mp);   // Enemy Max MP
	setMana(mp);      // Enemy MP

	// Set stats for the Enemy object
	setSTR(strength);
	setAGI(agility);
	setDEF(defense);
	setSTA(stamina);
	setINT(intelligence);

	// Set experience to be collected upon the Enemy's death
	setEXP(exp);

	// Set the Enemy's damage
	setDamage(5);
}


/*  Method(s)  */
void Enemy::Stats()
{
	// Title
	std::cout << "\t\t=========================" << std::endl;
	std::cout << "\t\t*** Enemy Information ***" << std::endl;
	std::cout << "\t\t=========================" << std::endl;

	// Output Enemy name (if the enemy has one)
	if (getName() != "") std::cout << "Name   : " << getName() << std::endl;

	// Output basic Enemy information
	std::cout << "Type   : " << getType() << std::endl;
	std::cout << "Level  : " << getLevel() << std::endl;
	std::cout << "Health : (" << getHealth() << "/" << getMaxHealth() << ")" << std::endl;

	// Output Enemy Mana (if it has intelligence)
	if (getINT() != NULL) std::cout << "Mana   : ( " << getMana() << "/" << getMaxMana() << ")" << std::endl;

	// Output Enemy stats
	std::cout << "================" << std::endl;
	std::cout << "STR: " << getSTR() << std::endl;
	std::cout << "AGI: " << getAGI() << std::endl;
	std::cout << "DEF: " << getDEF() << std::endl;
	// Output if the Enemy has Stamina & Intelligence Stats
	if (getSTA() != NULL && getINT() != NULL) {
		std::cout << "STA: " << getSTA() << std::endl;
		std::cout << "INT: " << getINT() << std::endl;
	}
	// Output experience received on Enemy's death
	std::cout << "================" << std::endl;
	std::cout << "On Death: [+" << getEXP() << " EXP]";
}


/*  Encapsulation Methods  */
// TYPE
void Enemy::setType(std::string type)
{
	TYPE = type;
}
std::string Enemy::getType()
{
	return TYPE;
}