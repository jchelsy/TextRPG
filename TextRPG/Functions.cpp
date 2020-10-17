/*  Header Library Imports  */
/*  ======================  */
#include "Functions.h"

#include "Colors.h"
#include "Exceptions.h"

// Method to get user input (string)
std::string getInput(std::string question, bool toLower=false)
{
	// Initialize variable(s)
	std::string answer;

	// Output question
	std::cout << question << ": ";
	// Get user input
	std::getline(std::cin, answer);

	if (toLower)
		// Transform answer to lowercase
		std::transform(answer.begin(), answer.end(), answer.begin(), ::tolower);

	// Return user input
	return answer;
}

// Method to get user input (integer)
int choiceNum(std::string question)
{
	while (true)
	{
		try
		{
			// Get user input
			std::string answer = getInput(question);
			// Convert user input to an integer
			int numAnswer = stoi(answer);

			// Return user input (integer)
			return numAnswer;
		}
		catch (std::invalid_argument const& e)
		{
			std::cout << RED << "    [INVALID ARGUMENT: Please input a vaid integer]\n" << RESET << std::endl;
		}
		catch (std::out_of_range const& e)
		{
			std::cout << RED << "    [OUT OF BOUNDS: Please input a smaller integer]\n" << RESET << std::endl;
		}
	}
}

// Method to get user input (boolean)
bool choiceYesNo(std::string Yes, std::string No)
{
	// Get the 1st letter of both choices (uppercase)
	std::string upperY(1, toupper(Yes[0]));
	std::string upperN(1, toupper(No[0]));

	// Convert both choices to lowercase
	transform(Yes.begin(), Yes.end(), Yes.begin(), ::tolower);
	transform(No.begin(), No.end(), No.begin(), ::tolower);

	// Get the 1st letter of both choices (lowercase)
	std::string Y(1, Yes[0]);
	std::string N(1, No[0]);

	while (true)
	{
		try
		{
			// Get user input
			std::string answer = getInput("(" + upperY + "/" + upperN + ")");

			// Convert user input to lowercase (for case insensitive checks)
			transform(answer.begin(), answer.end(), answer.begin(), ::tolower);

			// If user chose YES ('yes' / 'y'):
			if (answer == Yes || answer == Y)
				return true;
			// If user chose NO ('no' / 'n'):
			else if (answer == No || answer == N)
				return false;
			// Otherwise (invalid input):
			else
				throw InvalidInputException();
		}
		catch (InvalidInputException& e)
		{
			std::cout << RED << "    [" << e.messageTitle() << ": Please choose only "
				<< upperY << " or " << upperN << "]" << RESET << std::endl;
		}
	}
}

// Method to get user input (char)
char choiceABC(std::string letterChoices) {
	// Initialize local variables
	const char* choices = letterChoices.c_str();
	std::string answer;

	while (true)
	{
		// Get user input
		answer = getInput("\nChoice", true);

		try
		{
			if (answer.size() == 1)
			{
				for (size_t i = 0; i < letterChoices.length(); i++)
				{
					// If the user input is a valid choice, return it
					if (answer[0] == choices[i])
						return choices[i];
				}
				// When the user input is not a valid choice
				throw InvalidInputException();
			}
			else {
				// When the user input is more than a single character
				throw InvalidInputException();
			}
		}
		catch (InvalidInputException& e)
		{
			std::cout << RED << "    [" << e.messageTitle() << ": Try again]" << RESET << std::endl;
		}

	}
}

//char choiceABCDE() {
//	string choice;
//	choice = userChoiceString("\nChoice");
//	do {
//		if (choice == "A" || choice == "a") {
//			return 'A';
//		}
//		else if (choice == "B" || choice == "b") {
//			return 'B';
//		}
//		else if (choice == "C" || choice == "c") {
//			return 'C';
//		}
//		else if (choice == "D" || choice == "d") {
//			return 'D';
//		}
//		else if (choice == "E" || choice == "e") {
//			return 'E';
//		}
//		// If anything else is inputted (other than 'A', 'a', 'B', 'b', 'C', 'c', 'D', 'd', 'E', 'e'
//		else {
//			cout << "Please choose only from ";
//			choice = userChoiceString("A,B,C,D,E");
//		}
//	} while (true);
//}