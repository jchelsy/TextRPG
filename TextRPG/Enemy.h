/*  Header File for Enemy Class  */

#pragma once

/*  Header Libary Import(s)  */
/*  =======================  */
#include "Character.h"  // Character Class

/*  Enemy Class  */
class Enemy : public Character
{
public:
	// Constructors
	Enemy();
	Enemy(std::string, int, int, int, int, int, int);
	Enemy(std::string, std::string, int, int, int, int, int, int, int, int, int);

	// Method(s)
	void Stats();

	// Encapsulation Methods
	void setType(std::string);
	std::string getType();

private:
	// Private variable(s)
	std::string TYPE;
};