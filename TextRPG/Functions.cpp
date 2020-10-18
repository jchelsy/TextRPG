/*  'Functions' Source Code  */

/*  Header Library Import(s)  */
/*  ========================  */
#include "Functions.h"

#include "Colors.h"
#include "Exceptions.h"


// Method to clear the console window
void clear()
{
	std::cout << "\x1B[2J\x1B[H";
}

void sleep(int delay)
{
	std::this_thread::sleep_for(std::chrono::milliseconds(delay));
}