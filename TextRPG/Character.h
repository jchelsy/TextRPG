/*  Header File for Character Class  */

#pragma once

/*  Header Libary Import(s)  */
/*  =======================  */
#include <algorithm>	// Vector Array Library
#include <vector>		// Mathematical Functions Library
#include <map>			// Map Array Library (contains key value & mapped value)

#include "Equipment.h"	// Equipment Class


/*  Character Class  */
class Character
{
public:
	// Constructors
	Character();
	Character(std::string, std::string, std::string, int=1, int=0);


	// Method(s)
	void Stats();

	void addToInv(Equipment);
	void addMultipleToInv(Equipment, int);
	void removeFromInv(Equipment);
	void viewInv();

	void equipWeapon(Equipment);
	void unequipWeapon(Equipment);
	void equipArmor(Equipment);
	void unequipArmor(Equipment);

	void Overview();


	// Encapsulation Methods
	void setName(std::string);
	void setArea(std::string);
	void setClass(std::string);
	void setLevel(int);
	void setEXP(int);
	void setEXPReq();
	void setHealth(double);
	void setMana(int);
	void setMaxHealth(double);
	void setMaxMana(int);

	std::string getName();
	std::string getArea();
	std::string getClass();
	int getLevel();
	int getEXP();
	int getEXPReq();
	double getHealth();
	int getMana();
	double getMaxHealth();
	int getMaxMana();


	void setSTR(int);
	void setAGI(int);
	void setDEF(int);
	void setSTA(int);
	void setINT(int);
	void setVIT(int);

	int getSTR();
	int getAGI();
	int getDEF();
	int getSTA();
	int getINT();
	int getVIT();


	void setSTRBoost(int);
	void setAGIBoost(int);
	void setDEFBoost(int);
	void setSTABoost(int);
	void setINTBoost(int);
	void setVITBoost(int);

	int getSTRBoost();
	int getAGIBoost();
	int getDEFBoost();
	int getSTABoost();
	int getINTBoost();
	int getVITBoost();


	void setDamageModifier(int);
	int getDamageModifier();
	void setDamage(int);
	int getDamage();

	void setDodgeRate(int);
	double getDodgeRate();

	void setCurrency(int);
	int getCurrency();
	void setGold();
	int getGold();
	void setSilver();
	int getSilver();
	void setCopper();
	int getCopper();

	// Public variables - used for storing equipped items
	Equipment* helm;
	Equipment* chest;
	Equipment* legs;
	Equipment* boots;
	Equipment* mainHand;
	Equipment* offHand;
	Equipment* oneHanded;
	Equipment* shield;

private:
	// Private variables
	std::string NAME;
	std::string LOCATION;
	std::string CLASS;
	int LVL;
	double maxHP;
	int maxMP;
	double HP;
	int MP;
	int EXP;
	int EXPReq;

	int STR; // Stat -- Strength
	int DEF; // Stat -- Defense
	int AGI; // Stat -- Agility
	int STA; // Stat -- Stamina
	int INT; // Stat -- Intelligence
	int VIT; // Stat -- Vitality (determines player HP)

	int STRboost; // Stat boost -- Strength
	int DEFboost; // Stat boost -- Defense
	int AGIboost; // Stat boost -- Agility
	int STAboost; // Stat boost -- Stamina
	int INTboost; // Stat boost -- Intelligence
	int VITboost; // Stat boost -- Vitality

	int atkDamage;	  // Attack Damage
	int dmgModifier;  // Damage Modifier
	double dodgeRate; // Dodge rate ( 0.15 <= x < 0.6 )

	int currencyTotal;			// Currency Total   (total copper)
	int gold;					// Amount of Gold   (calculated from currency)
	int silver;					// Amount of Silver (calculated from currency)
	int copper;					// Amount of Copper (calculated from currency)

	std::vector<int> currency;	// Amount of Currency (gold, silver, copper)

	// Private inventory arrays
	std::vector<Equipment> INVENTORY; // Items in player's inventory
	std::vector<Equipment> EQUIPPED;  // Armor/Weapons equipped by player
};