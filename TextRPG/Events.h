/*  'Events' Header File  */

#pragma once

/*  Header Libary Import(s)  */
/*  =======================  */
#include "Character.h"
#include "Enemy.h"


/*  Function Declaration(s)  */
/*  =======================  */
Character CalculateEXP(Character, Enemy);
Character LevelUp(Character);
void Death();

std::vector<int> GetItemCost(int);
std::string GetFormattedItemCost(int);

bool IsNumber(const std::string&);