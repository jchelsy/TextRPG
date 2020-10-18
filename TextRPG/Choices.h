/*  'Choices' Header File  */

#pragma once

/*  Header Library Import(s)  */
/*  ========================  */
#include <iostream>		// Input/Output Library
#include <string>		// String Library
#include <algorithm>	// Mathematical Function Library


/*  Function Declaration(s) for 'Choices.cpp'  */
/*  =========================================  */
std::string getInput(std::string, bool = false);
int choiceNum(std::string);
bool choiceYesNo(std::string, std::string);
char choiceABC(std::string);




//std::string userChoiceString(std::string text);
//char userChoiceChar();
//int userChoiceInteger();
//bool choiceYesNo(std::string, std::string);
//char choiceAB();
//char choiceABC();
//char choiceABCD();
//char choiceABCDE();