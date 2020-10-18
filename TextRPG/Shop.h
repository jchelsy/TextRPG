/*  'Shop' Header File  */

#pragma once

/*  Header Libary Import(s)  */
/*  =======================  */
#include <thread>		// Execution Thread Library
#include <chrono>		// Time Manipulation Library


/*  Function Declaration(s)  */
/*  =======================  */
Character Shop(std::string, Character, std::vector<std::pair<Equipment, std::pair<int, int>>>, std::vector<std::pair<Equipment, std::pair<int, int>>>);