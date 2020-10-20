/*  'Battle' Source Code  */

/*  Header Libary Import(s)  */
/*  =======================  */
#include "Battle.h"
#include "Functions.h"
#include "Events.h"

Character startBattle(Character player)
{
	return player;
}




/* PSEUDOCODE OF GENERALIZED BATTLE METHOD:
* 
Character Battle(Character player, Enemy[] enemArray) {
	COUT: "What enemy to attack first?"

	for (i = 0; i < enemArray.length(); i++) {
		if (enemArray[i].GetHealth() >= 0) {
			"A: " + enemArray[i]

			.......
			(second iteration -- "B: " + enemArray[i])
		}
	}
	// Get user input

	while (<chosen enemy>.GetHealth() >= 0) {
		// Turn-by-turn battle loop
	}

	int enemyHealthCount = 0;

	// If all enemies are dead, enemyHealthCount will result as 0
	for (i = 0; i < enemArray.length(); i++) {
		enemyHealthCount += enemArray[i].GetHealth();
	}

	if (enemyHealthCount > 0) {
		// One or more enemies alive. Start another battle.
		Battle(player, enemArray);
	}
	else {
		// ALL ENEMIES DEAD!
	}
}
* 
*/





// To handle base case of below recursive 
// Variadic function Template 
void print() { }

// Variadic function Template that takes
// variable number of arguments and prints
// all of them.
template <typename T, typename... Types>
void print(T var1, Types... var2)
{
	std::cout << var1 << std::endl;

	print(var2...);
}



/*  ==============================  */
/*  === Battle Scenario Method ===  */
/*  ==============================  */
Character Battle1(Character player)
{
	// Initialize variables for user input
	bool option;
	char optionChar;
	// Initialize variables for player attack
	int attack;
	int fAttack;
	// Initialize variables for enemy attacks
	int mobAttack1;
	int mobAttack2;
	int mobAttack3;
	int fMobAttack1;
	int fMobAttack2;
	int fMobAttack3;
	// Initialize variables for dodge rate calculations
	int numIncrease;
	int numIncrease2;
	int randomDodge;
	double dodgeRate;
	double agilityModifier;
	bool fullDodge;
	// Initialize variable for player's lost hp
	double hpLost;

	std::this_thread::sleep_for(std::chrono::milliseconds(500));  // Pause 1/2 sec

	// Seed the pseudo random number generator that rand() uses
	srand((unsigned)time(NULL));

	// Create Enemy objects for all three Goblins
	//   - Level 1
	//   - Random health of 50-100
	//   - Random STR stat of 2-4
	//   - Random AGI stat of 1-4
	//   - Random DEF stat of 1-4
	//   - 100 experience on death
	Enemy goblin1("Goblin", 1, (50 + (rand() % (100 - 50 + 1))), (2 + (rand() % (4 - 2 + 1))), (1 + (rand() % (4 - 1 + 1))), (1 + (rand() % (4 - 1 + 1))), 100);
	Enemy goblin2("Goblin", 1, (50 + (rand() % (100 - 50 + 1))), (2 + (rand() % (4 - 2 + 1))), (1 + (rand() % (4 - 1 + 1))), (1 + (rand() % (4 - 1 + 1))), 100);
	Enemy goblin3("Goblin", 1, (50 + (rand() % (100 - 50 + 1))), (2 + (rand() % (4 - 2 + 1))), (1 + (rand() % (4 - 1 + 1))), (1 + (rand() % (4 - 1 + 1))), 100);

	// Enemy information title
	std::cout << "\n  =====================================================================" << std::endl;
	std::cout << "                        *** Enemy Information ***                      " << std::endl;
	std::cout << "  =====================================================================" << std::endl;

	// Output all three goblins' information (all three are formatted to be displayed next to each other)
	std::cout << "    Type   : " << goblin1.getType() << " 1\tType   : " << goblin2.getType() << " 2\tType   : " << goblin3.getType() << " 3" << std::endl;
	std::cout << "    Level  : " << goblin1.getLevel() << "\t\tLevel  : " << goblin2.getLevel() << "\t\tLevel  : " << goblin3.getLevel() << std::endl;
	std::cout << "    Health : (" << goblin1.getHealth() << "/" << goblin1.getMaxHealth() << ")\tHealth : (" << goblin2.getHealth() << "/" << goblin2.getMaxHealth() << ")\tHealth : (" << goblin3.getHealth() << "/" << goblin3.getMaxHealth() << ")" << std::endl;
	std::cout << "    ================\t================\t================" << std::endl;
	std::cout << "    STR: " << goblin1.getSTR() << "\t\t\tSTR: " << goblin2.getSTR() << "\t\t\tSTR: " << goblin3.getSTR() << std::endl;
	std::cout << "    AGI: " << goblin1.getAGI() << "\t\t\tAGI: " << goblin2.getAGI() << "\t\t\tAGI: " << goblin3.getAGI() << std::endl;
	std::cout << "    DEF: " << goblin1.getDEF() << "\t\t\tDEF: " << goblin2.getDEF() << "\t\t\tDEF: " << goblin3.getDEF() << std::endl;
	std::cout << "    ================\t================\t================" << std::endl;
	std::cout << "    On Death: [+" << goblin1.getEXP() << " EXP]\tOn Death: [+" << goblin2.getEXP() << " EXP]\tOn Death: [+" << goblin3.getEXP() << " EXP]" << std::endl;

	std::this_thread::sleep_for(std::chrono::milliseconds(500));  // Pause 1/2 sec

	// Output to the player that the battle is starting
	std::cout << "\n\n  Get ready for battle!" << std::endl;

	std::this_thread::sleep_for(std::chrono::milliseconds(350));  // Pause 0.35 seconds

	// Ask the player which Goblin to target first
	std::cout << "\n\n  Which enemy will you target first?" << std::endl;
	std::cout << "\tA) Goblin 1 (" << goblin1.getHealth() << "/" << goblin1.getMaxHealth() << ")" << std::endl;
	std::cout << "\tB) Goblin 2 (" << goblin2.getHealth() << "/" << goblin2.getMaxHealth() << ")" << std::endl;
	std::cout << "\tC) Goblin 3 (" << goblin3.getHealth() << "/" << goblin3.getMaxHealth() << ")" << std::endl;
	// Get user input
	optionChar = choiceABC("ABC");

	// If user chose Goblin 1 ('A'/'a')
	// ATTACK GOBLIN 1 -- GOBLIN 2/3 STILL ALIVE
	if (optionChar == 'A')
	{
		// Block of code to loop while Goblin 1 is alive
		do {
			// Output health status of player & all enemies
			std::cout << "\n\n  ###############################\n  HP:       (" << player.getHealth() << "/" << player.getMaxHealth() << ")\n  " <<
				"Goblin 1: (" << goblin1.getHealth() << "/" << goblin1.getMaxHealth() << ")\n  " <<
				"Goblin 2: (" << goblin2.getHealth() << "/" << goblin2.getMaxHealth() << ")\n  " <<
				"Goblin 3: (" << goblin3.getHealth() << "/" << goblin3.getMaxHealth() << ")\n  " <<
				"###############################" << std::endl;

			std::this_thread::sleep_for(std::chrono::milliseconds(200));  // Pause 0.2 seconds

			// Ask the player to either Attack or Retreat
			std::cout << "\n  Attack or Retreat? ";
			// Get user input
			option = choiceYesNo("Attack", "Retreat");

			clear();  // Clear console window

			// If option is false -- user chose "Retreat" ('R'/'r')
			if (option == false) {
				// If a random number of 1-3 is 1 (33% chance)
				if ((rand() % 3) == 1) {
					// Output successful escape notification
					std::cout << "\n  You have successfully escaped." << std::endl;

					// Set the health of all enemies to 0
					goblin1.setHealth(0);
					goblin2.setHealth(0);
					goblin3.setHealth(0);

					// Go to the location of 'END:' and play from there
					//   (exits the loop & ends the battle)
					goto END;
				}
				// Otherwise (If the random number is not 1 -- the 66% chance of failed retreat passes)...
				else {
					std::this_thread::sleep_for(std::chrono::milliseconds(200));  // Pause 0.2 seconds

					// Output failed escape notification
					std::cout << "\n  Retreat failed." << std::endl;

					// If Goblin 1 is still alive
					if (goblin1.getHealth() > 0) {
						// Output free attack
						std::cout << "\n  Goblin 1 got in a free attack. [-10 HP]" << std::endl;

						// Subtract 10 health from the player
						player.setHealth(player.getHealth() - 10);
					}
					// If Goblin 2 is still alive
					if (goblin2.getHealth() > 0) {
						// Output free attack
						std::cout << "  Goblin 2 got in a free attack. [-10 HP]" << std::endl;

						// Subtract 10 health from the player
						player.setHealth(player.getHealth() - 10);
					}
					// If Goblin 3 is still alive
					if (goblin3.getHealth() > 0) {
						// Output free attack
						std::cout << "  Goblin 3 got in a free attack. [-10 HP]" << std::endl;

						// Subtract 10 health from the player
						player.setHealth(player.getHealth() - 10);
					}
					// Set option to true
					//   (so that the player attack occurs next)
					option = true;
				}
			}
			// If option is true -- user chose "Attack" ('A'/'a') or failed to retreat
			if (option == true) {
				std::this_thread::sleep_for(std::chrono::milliseconds(350));  // Pause 0.35 seconds

				// Set the player's lost hp to 0 (to reset upon loop repeat)
				hpLost = 0;

				// Random Player Damage between: 1/2 Base Atk Damage - Full Base Atk Damage
				attack = ((player.getDamage() / 2) + (rand() % (player.getDamage() - (player.getDamage() / 2) + 1)));
				// Random Enemy Damage between: 1/2 Base Atk Damage - Full Base Atk Damage
				mobAttack1 = ((goblin1.getDamage() / 2) + (rand() % (goblin1.getDamage() - (goblin1.getDamage() / 2) + 1)));
				mobAttack2 = ((goblin2.getDamage() / 2) + (rand() % (goblin2.getDamage() - (goblin2.getDamage() / 2) + 1)));
				mobAttack3 = ((goblin3.getDamage() / 2) + (rand() % (goblin3.getDamage() - (goblin3.getDamage() / 2) + 1)));

				// Modify Player attack to subtract 1/2 DEF Stat Value Multiplied by Level (Higher Defense & Higher Level = Less Damage Taken)
				fAttack = attack - ((goblin1.getLevel() * goblin1.getDEF()) / 2);
				// Modify Enemy attack to subtract 1/2 True DEF Stat Value Multiplied by Level (Higher Defense & Higher Level = Less Damage Taken)
				fMobAttack1 = mobAttack1 - ((player.getLevel() * (player.getDEF() + player.getDEFBoost())) / 2);
				fMobAttack2 = mobAttack2 - ((player.getLevel() * (player.getDEF() + player.getDEFBoost())) / 2);
				fMobAttack3 = mobAttack3 - ((player.getLevel() * (player.getDEF() + player.getDEFBoost())) / 2);

				// If any attack damages are less than zero
				// Set them to zero (there can't be negative damage)
				if (fAttack < 0) {
					fAttack = 0;
				}
				if (fMobAttack1 < 0) {
					fMobAttack1 = 0;
				}
				if (fMobAttack2 < 0) {
					fMobAttack2 = 0;
				}
				if (fMobAttack3 < 0) {
					fMobAttack3 = 0;
				}

				// Set the player's dodge rate to double variable 'dodgeRate'
				//   (for dodge rate percentage calculations)
				dodgeRate = player.getDodgeRate();

				// Subtract Goblin 1's health by the player's attack damage
				goblin1.setHealth(goblin1.getHealth() - fAttack);

				// Output attack notification
				std::cout << "\n  You attack Goblin 1 for " << fAttack << " damage!" << std::endl;

				std::this_thread::sleep_for(std::chrono::milliseconds(200));  // Pause 0.2 seconds

				// If Goblin 1 is alive
				if (goblin1.getHealth() > 0) {
					// Output that Goblin 1 is beginning a counter attack
					std::cout << "\n  [Goblin 1 begins their counter attack.]" << std::endl;

					// Set integer variable 'agilityModifier' to 0 (to reset upon loop repeat)
					agilityModifier = 0;

					// Set integer variable 'randomDodge' to a random number of 1-100
					//   (for matching usage to determine player's dodge percentage)
					randomDodge = (1 + (rand() % ((100 - 1) + 1)));

					// Set boolean 'fullDodge' to false (to reset upon loop repeat)
					//   (this is used to break out of the loop
					//    if the first dodge check is a success)
					fullDodge = false;

					// 'numIncrease' & 'numIncrease2' are used as the two values
					// for the range of the dodge rate checker, used with 'randomDodge'

					// Set integer 'numIncrease' to 1
					numIncrease = 1;
					// Set integer 'numIncrease2' to the player's dodge rate times 100
					//   (decimal of 0.01-1 to a whole # of 1-100)
					numIncrease2 = (int)(dodgeRate * 100);

					// FIRST DODGE CHECK:
					// If the dodge check is a success
					//   (randomized num of 1-100 is within the
					//    starting range of the dodge rate checker)
					if (randomDodge > numIncrease && randomDodge <= numIncrease2) {
						// Set boolean 'fullDodge' to true
						fullDodge = true;
					}
					// Otherwise...
					else {
						// Increase the range of the
						// dodge rate checker up one notch
						numIncrease = numIncrease2;
						numIncrease2 = numIncrease2 + 20;
					}

					// Loop five times (after 5 times, dodge rate is guaranteed 0%)
					for (unsigned i = 0;i < 5;++i) {
						// If 'fullDodge' is true (if first check above succeeded)
						if (fullDodge == true) {
							// Break out of the loop
							break;
						}

						// If the modifier is between 0 and 1 (but not actually 1)
						if (agilityModifier < 1.0 && agilityModifier >= 0.0) {
							// Increase the modifier by 0.25 (25% less damage avoided)
							agilityModifier = agilityModifier + 0.25;  // Dodges: 100% - 75% - 50% - 25% - 0%
						}
						// If the modifier is equal to 1 (0% damage avoided)
						if (agilityModifier == 1.0) {
							// Break out of the loop
							break;
						}

						// If 'numIncrease' or 'numIncrease2' reaches 100
						//   (the loop ran through all checks to 100%)
						if (numIncrease > 100 || numIncrease2 > 100) {
							// Break out of the loop
							break;
						}
						// NEXT DODGE CHECK:
						// If the dodge check is a success
						//   (randomized num of 1-100 is within the
						//    increased range of the dodge rate checker)
						if (randomDodge > numIncrease && randomDodge <= numIncrease2) {
							// Break out of the loop
							break;
						}

						// Increase the two values of the range of the dodge rate checker
						numIncrease = numIncrease + 20;
						numIncrease2 = numIncrease2 + 20;
					}

					// If the modifier is equal to 0 -- 100% damage avoided (0 x dmg = no dmg taken)
					if (agilityModifier == 0.0) {
						// Output that the player avoided 100% of Goblin 1's damage
						std::cout << "\n  You avoided Goblin 1's attack [" << fMobAttack1 << " DMG] with your agility!" << std::endl;
					}  // OR
					// If the modifier is equal to 1 -- 0% damage avoided (1 x dmg = full dmg taken)
					else if (agilityModifier == 1.0) {
						// Subtract 100% of Goblin 1's attack from the player's health
						player.setHealth(player.getHealth() - fMobAttack1);

						// Output that the player took 100% of Goblin 1's attack
						std::cout << "\n  Goblin 1 counter attacks for " << fMobAttack1 << " damage!" << std::endl;

						// Add the damage the player received to variable 'hpLost'
						//   (for output after the round ends)
						hpLost = (hpLost + fMobAttack1);
					}
					// Otherwise (If the modifer is more than 0 and less than 1 -- 0.25, 0.5, 0.75)...
					else {
						// Subtract Goblin 1's attack (minus the avoided damage) from the player's health
						//   - atk x 0.25 = 75% dmg avoided (Player gets damaged 25% of the enemy's dmg)
						//   - atk x 0.5  = 50% dmg avoided (Player gets damaged 50% of the enemy's dmg)
						//   - atk x 0.75 = 25% dmg avoided (Player gets damaged 75% of the enemy's dmg)
						player.setHealth(player.getHealth() - (fMobAttack1 * agilityModifier));

						// Output the % of damage the player negated and how much damage the player took
						std::cout << "\n  You have negated " << ((1 - agilityModifier) * 100) << "% of Goblin 1's attack damage [" << fMobAttack1 << " DMG] " <<
							"by maneuvering with your agility! You only take " << (fMobAttack1 * agilityModifier) << " damage!" << std::endl;

						// Add the damage the player received to variable 'hpLost'
						//   (for output after the round ends)
						hpLost = (hpLost + (fMobAttack1 * agilityModifier));
					}
				}

				// Otherwise (If Goblin 1 is dead)...
				else {
					// Output that Goblin 1 has perished & how much experience the player gets
					std::cout << "\n  [Goblin 1 has perished.]\n  [EXP+" << goblin1.getEXP() << "]" << std::endl;
				}

				// If Goblin 2 is alive
				if (goblin2.getHealth() > 0) {
					// Output that the other goblins are beginning their attacks
					std::cout << "\n\n  [The other goblins begin their attacks.]" << std::endl;

					// Set integer variable 'agilityModifier' to 0 (to reset upon loop repeat)
					agilityModifier = 0;

					// Set integer variable 'randomDodge' to a random number of 1-100
					//   (for matching usage to determine player's dodge percentage)
					randomDodge = (1 + (rand() % ((100 - 1) + 1)));

					// Set boolean 'fullDodge' to false (to reset upon loop repeat)
					//   (this is used to break out of the loop
					//    if the first dodge check is a success)
					fullDodge = false;

					// 'numIncrease' & 'numIncrease2' are used as the two values
					// for the range of the dodge rate checker, used with 'randomDodge'

					// Set integer 'numIncrease' to 1
					numIncrease = 1;
					// Set integer 'numIncrease2' to the player's dodge rate times 100
					//   (decimal of 0.01-1 to a whole # of 1-100)
					numIncrease2 = (int)(dodgeRate * 100);

					// FIRST DODGE CHECK:
					// If the dodge check is a success
					//   (randomized num of 1-100 is within the
					//    starting range of the dodge rate checker)
					if (randomDodge > numIncrease && randomDodge <= numIncrease2) {
						// Set boolean 'fullDodge' to true
						fullDodge = true;
					}
					// Otherwise...
					else {
						// Increase the range of the
						// dodge rate checker up one notch
						numIncrease = numIncrease2;
						numIncrease2 = numIncrease2 + 20;
					}

					// Loop five times (after 5 times, dodge rate is guaranteed 0%)
					for (unsigned i = 0;i < 5;++i) {
						// If 'fullDodge' is true (if first check above succeeded)
						if (fullDodge == true) {
							// Break out of the loop
							break;
						}

						// If the modifier is between 0 and 1 (but not actually 1)
						if (agilityModifier < 1 && agilityModifier >= 0) {
							// Increase the modifier by 0.25 (25% less damage avoided)
							agilityModifier = agilityModifier + 0.25;  // Dodges: 100% - 75% - 50% - 25% - 0%
						}
						// If the modifier is equal to 1 (0% damage avoided)
						if (agilityModifier == 1.0) {
							// Break out of the loop
							break;
						}

						// If 'numIncrease' or 'numIncrease2' reaches 100
						//   (the loop ran through all checks to 100%)
						if (numIncrease > 100 || numIncrease2 > 100) {
							// Break out of the loop
							break;
						}
						// NEXT DODGE CHECK:
						// If the dodge check is a success
						//   (randomized num of 1-100 is within the
						//    increased range of the dodge rate checker)
						if (randomDodge > numIncrease && randomDodge <= numIncrease2) {
							// Break out of the loop
							break;
						}

						// Increase the two values of the range of the dodge rate checker
						numIncrease = numIncrease + 20;
						numIncrease2 = numIncrease2 + 20;
					}

					// If the modifier is equal to 0 -- 100% damage avoided (0 x dmg = no dmg taken)
					if (agilityModifier == 0.0) {
						// Output that the player avoided 100% of Goblin 2's damage
						std::cout << "\n  You avoided Goblin 2's attack [" << fMobAttack2 << " DMG] with your agility!" << std::endl;
					}  // OR
					// If the modifier is equal to 1 -- 0% damage avoided (1 x dmg = full dmg taken)
					else if (agilityModifier == 1.0) {
						// Subtract 100% of Goblin 2's attack from the player's health
						player.setHealth(player.getHealth() - fMobAttack2);

						// Output that the player took 100% of Goblin 2's attack
						std::cout << "\n  Goblin 2 attacks you for " << fMobAttack2 << " damage!" << std::endl;

						// Add the damage the player received to variable 'hplost'
						//   (for output after the round ends)
						hpLost = (hpLost + fMobAttack2);
					}
					// Otherwise (If the modifier is more than 0 and less than 1 -- 0.25, 0.5, 0.75)...
					else {
						// Subtract Goblin 2's attack (minus the avoided damage) from the player's health
						//   - atk x 0.25 = 75% dmg avoided (Player gets damaged 25% of the enemy's dmg)
						//   - atk x 0.5  = 50% dmg avoided (Player gets damaged 50% of the enemy's dmg)
						//   - atk x 0.75 = 25% dmg avoided (Player gets damaged 75% of the enemy's dmg)
						player.setHealth(player.getHealth() - (fMobAttack2 * agilityModifier));

						// Output the % of damage the player negated and how much damage the player took
						std::cout << "\n  You have negated " << ((1 - agilityModifier) * 100) << "% of Goblin 2's attack damage [" << fMobAttack2 << " DMG] " <<
							"by maneuvering with your agility! You only take " << (fMobAttack2 * agilityModifier) << " damage!" << std::endl;

						// Add the damage the player received to variable 'hpLost'
						//   (for output after the round ends)
						hpLost = (hpLost + (fMobAttack2 * agilityModifier));
					}
				}

				// Otherwise (If Goblin 2 is dead)...
				else {
					// Output that Goblin 2 has perished & how much experience the player gets
					std::cout << "\n  [Goblin 2 has perished.]\n  [EXP+" << goblin2.getEXP() << "]" << std::endl;
				}

				// If Goblin 3 is alive
				if (goblin3.getHealth() > 0) {
					// Set integer variable 'agilityModifier' to 0 (to reset upon loop repeat)
					agilityModifier = 0;

					// Set integer variable 'randomDodge' to a random number of 1-100
					//   (for matching usage to determine player's dodge percentage)
					randomDodge = (1 + (rand() % ((100 - 1) + 1)));

					// Set boolean 'fullDodge' to false (to reset upon loop repeat)
					//   (this is used to break out of the loop
					//    if the first dodge check is a success)
					fullDodge = false;

					// 'numIncrease' & 'numIncrease2' are used as the two values
					// for the range of the dodge rate checker, used with 'randomDodge'

					// Set integer 'numIncrease' to 1
					numIncrease = 1;
					// Set integer 'numIncrease2' to the player's dodge rate times 100
					//   (decimal of 0.1-1 to a whole # of 1-100)
					numIncrease2 = (int)(dodgeRate * 100);

					// FIRST DODGE CHECK:
					// If the dodge check is a success
					//   (randomized num of 1-100 is within the
					//    starting range of the dodge rate checker)
					if (randomDodge > numIncrease && randomDodge <= numIncrease2) {
						// Set boolean 'fullDodge' to true
						fullDodge = true;
					}
					// Otherwise...
					else {
						// Increase the range of the
						// dodge rate checker up one notch
						numIncrease = numIncrease2;
						numIncrease2 = numIncrease2 + 20;
					}

					// Loop five times (after 5 times, dodge rate is guaranteed 0%)
					for (unsigned i = 0;i < 5;++i) {
						// If 'fullDodge' is true (if first check above succeeded)
						if (fullDodge == true) {
							// Break out of the loop
							break;
						}

						// If the modifier is between 0 and 1 (but not actually 1)
						if (agilityModifier < 1 && agilityModifier >= 0) {
							// Increase the modifier by 0.25 (25% less damage avoided)
							agilityModifier = agilityModifier + 0.25;  // Dodges: 100% - 75% - 50% - 25% - 0%
						}
						// If the modifier is equal to 1 (0% damage avoided)
						if (agilityModifier == 1.0) {
							// Break out of the loop
							break;
						}

						// If 'numIncrease' or 'numIncrease2' reaches 100
						//   (the loop ran through all checks to 100%)
						if (numIncrease > 100 || numIncrease2 > 100) {
							// Break out of the loop
							break;
						}
						// NEXT DODGE CHECK:
						// If the dodge check is a success
						//   (randomized num of 1-100 is within the
						//    increased range of the dodge rate checker)
						if (randomDodge > numIncrease && randomDodge <= numIncrease2) {
							// Break out of the loop
							break;
						}

						// Increase the two values of the range of the dodge rate checker
						numIncrease = numIncrease + 20;
						numIncrease2 = numIncrease2 + 20;
					}

					// If the modifier is equal to 0 -- 100% damage avoided (0 x dmg = no dmg taken)
					if (agilityModifier == 0.0) {
						// Output that the player avoided 100% of Goblin 3's damage
						std::cout << "\n  You avoided Goblin 3's attack [" << fMobAttack3 << " DMG] with your agility!" << std::endl;
					}  // OR
					// If the modifier is equal to 1 -- 0% damage avoided (1 x dmg = full dmg taken)
					else if (agilityModifier == 1.0) {
						// Subtract 100% of Goblin 3's attack from the player's health
						player.setHealth(player.getHealth() - fMobAttack3);

						// Output that the player took 100% of Goblin 3's attack
						std::cout << "\n  Goblin 3 attacks you for " << fMobAttack3 << " damage!" << std::endl;

						// Add the damage the player received to variable 'hpLost'
						//   (for output after the round ends)
						hpLost = (hpLost + fMobAttack3);
					}
					// Otherwise (If the modifier is more than 0 and less than 1 -- 0.25, 0.5, 0.75)...
					else {
						// Subtract Goblin 3's attack (minus the avoided damage) from the player's health
						//   - atk x 0.25 = 75% dmg avoided (Player gets damaged 25% of the enemy's dmg)
						//   - atk x 0.5  = 50% dmg avoided (Player gets damaged 50% of the enemy's dmg)
						//   - atk x 0.75 = 25% dmg avoided (Player gets damaged 75% of the enemy's dmg)
						player.setHealth(player.getHealth() - (fMobAttack3 * agilityModifier));

						// Output the % of damage the player negated and how much damage the player took
						std::cout << "\n  You have negated " << ((1 - agilityModifier) * 100) << "% of Goblin 3's attack damage [" << fMobAttack3 << " DMG] " <<
							"by maneuvering with your agility! You only take " << (fMobAttack3 * agilityModifier) << " damage!" << std::endl;

						// Add the damage the player received to variable 'hpLost'
						//   (for output after the round ends)
						hpLost = (hpLost + (fMobAttack3 * agilityModifier));
					}
				}

				// Otherwise (If Goblin 3 is dead)...
				else {
					// Output that Goblin 3 has perished & how much experience the player gets
					std::cout << "\n  [Goblin 3 has perished.]\n  [EXP+" << goblin3.getEXP() << "]" << std::endl;
				}

				// Output the amount of health lost after the round
				std::cout << "\n\n  [-" << hpLost << " HP]" << std::endl;

				std::this_thread::sleep_for(std::chrono::milliseconds(350));  // Pause 0.35 sec
			}
		} while (goblin1.getHealth() > 0 && player.getHealth() > 0);
		// Keep repeating the block of code until Goblin 1 or the player dies

		// If any of the Enemys' health has dropped below zero,
		// set their health to 0 (you can't have negative health)
		if (goblin1.getHealth() < 0) {
			goblin1.setHealth(0);
		}
		if (goblin2.getHealth() < 0) {
			goblin2.setHealth(0);
		}
		if (goblin3.getHealth() < 0) {
			goblin3.setHealth(0);
		}

		// If the player has died
		if (player.getHealth() <= 0) {
			// Run the Death() method
			Death();
			// Terminate the program
			exit(0);
		}

		// Output the health status of player & all enemies
		std::cout << "\n\n  ###############################\n  HP:       (" << player.getHealth() << "/" << player.getMaxHealth() << ")\n  " <<
			"Goblin 1: (" << goblin1.getHealth() << "/" << goblin1.getMaxHealth() << ")\n  " <<
			"Goblin 2: (" << goblin2.getHealth() << "/" << goblin2.getMaxHealth() << ")\n  " <<
			"Goblin 3: (" << goblin3.getHealth() << "/" << goblin3.getMaxHealth() << ")\n  " <<
			"###############################" << std::endl;

		// Update the Character object 'player' by calculating
		// the updated experience from Goblin 1's death
		player = CalculateEXP(player, goblin1);

		// Ask the player which Goblin to target next
		std::cout << "\n\n  Don't celebrate too soon! The battle still goes on!!\n  Which enemy will you target next?" << std::endl;
		std::cout << "\tA) Goblin 2 (" << goblin2.getHealth() << "/" << goblin2.getMaxHealth() << ")" << std::endl;
		std::cout << "\tB) Goblin 3 (" << goblin3.getHealth() << "/" << goblin3.getMaxHealth() << ")" << std::endl;
		// Get user input
		optionChar = choiceABC("AB");

		// If user chose Goblin 2 ('A'/'a')
		// ATTACK GOBLIN 2 -- GOBLIN 3 STILL ALIVE
		if (optionChar == 'A')
		{
			// Block of code to loop while Goblin 2 is still alive
			do {
				// Output health status of player & all enemies
				std::cout << "\n\n  ###############################\n  HP:       (" << player.getHealth() << "/" << player.getMaxHealth() << ")\n  " <<
					"Goblin 1: (" << goblin1.getHealth() << "/" << goblin1.getMaxHealth() << ")\n  " <<
					"Goblin 2: (" << goblin2.getHealth() << "/" << goblin2.getMaxHealth() << ")\n  " <<
					"Goblin 3: (" << goblin3.getHealth() << "/" << goblin3.getMaxHealth() << ")\n  " <<
					"###############################" << std::endl;

				std::this_thread::sleep_for(std::chrono::milliseconds(200));  // Pause 0.2 sec

				// Ask the player to either Attack or Retreat
				std::cout << "\n  Attack or Retreat? ";
				// Get user input
				option = choiceYesNo("Attack", "Retreat");

				clear();  // Clear console window

				// If option is false -- user chose "Retreat" ('R'/'r')
				if (option == false) {
					// If a random number of 1-3 is 1 (33% chance)
					if ((rand() % 3) == 1) {
						// Output successful escape notification
						std::cout << "\n  You have successfully escaped." << std::endl;

						// Set the health of all remaining enemies to 0
						goblin2.setHealth(0);
						goblin3.setHealth(0);

						// Go to the location of 'END:' and play from there
						//   (exits the loop & ends the battle)
						goto END;
					}
					// Otherwise (If the random number is not 1 -- the 66% chance of failed retreat passes)...
					else {
						std::this_thread::sleep_for(std::chrono::milliseconds(200));  // Pause 0.2 sec

						// Output failed escape notification
						std::cout << "\n  Retreat failed." << std::endl;

						// If Goblin 2 is still alive
						if (goblin2.getHealth() > 0) {
							// Output free attack
							std::cout << "\n  Goblin 2 got in a free attack. [-10 HP]" << std::endl;

							// Subtract 10 health from the player
							player.setHealth(player.getHealth() - 10);
						}
						// If Goblin 3 is still alive
						if (goblin3.getHealth() > 0) {
							// Output free attack
							std::cout << "  Goblin 3 got in a free attack. [-10 HP]" << std::endl;

							// Subtract 10 health from the player
							player.setHealth(player.getHealth() - 10);
						}
						// Set option to true
						//   (so that the player attack occurs next)
						option = true;
					}
				}
				// If option is true -- user chose "Attack" ('A'/'a') or failed to retreat
				if (option == true) {
					std::this_thread::sleep_for(std::chrono::milliseconds(350));  // Pause 0.35 sec

					// Set the player's lost hp to 0 (to reset upon loop repeat)
					hpLost = 0;

					// Random Player Damage between: 1/2 Base Atk Damage - Full Base Atk Damage
					attack = ((player.getDamage() / 2) + (rand() % (player.getDamage() - (player.getDamage() / 2) + 1)));
					// Random Enemy Damage between: 1/2 Base Atk Damage - Full Base Atk Damage
					mobAttack2 = ((goblin2.getDamage() / 2) + (rand() % (goblin2.getDamage() - (goblin2.getDamage() / 2) + 1)));
					mobAttack3 = ((goblin3.getDamage() / 2) + (rand() % (goblin3.getDamage() - (goblin3.getDamage() / 2) + 1)));

					// Modify Player attack to subtract 1/2 DEF Stat Value Multiplied by Level (Higher Defense & Higher Level = Less Damage Taken)
					fAttack = attack - ((goblin2.getLevel() * goblin2.getDEF()) / 2);
					// Modify Enemy attack to subtract 1/2 True DEF Stat Value Multiplied by Level (Higher Defense & Higher Level = Less Damage Taken)
					fMobAttack2 = mobAttack2 - ((player.getLevel() * (player.getDEF() + player.getDEFBoost())) / 2);
					fMobAttack3 = mobAttack3 - ((player.getLevel() * (player.getDEF() + player.getDEFBoost())) / 2);

					// If any attack damages are less than zero
					// Set them to zero (there can't be negative damage)
					if (fAttack < 0) {
						fAttack = 0;
					}
					if (fMobAttack2 < 0) {
						fMobAttack2 = 0;
					}
					if (fMobAttack3 < 0) {
						fMobAttack3 = 0;
					}

					// Set the player's dodge rate to double variable 'dodgeRate'
					//   (for dodge rate percentage calculations)
					dodgeRate = player.getDodgeRate();

					// Subtract Goblin 2's health by the player's attack damage
					goblin2.setHealth(goblin2.getHealth() - fAttack);

					// Output attack notification
					std::cout << "\n  You attack Goblin 2 for " << fAttack << " damage!" << std::endl;

					std::this_thread::sleep_for(std::chrono::milliseconds(200));  // Pause 0.2 sec

					// If Goblin 2 is alive
					if (goblin2.getHealth() > 0) {
						// Output that Goblin 2 is beginning a counter attack
						std::cout << "\n  [Goblin 2 begins their counter attack.]" << std::endl;

						// Set integer variable 'agilityModifier' to 0 (to reset upon loop repeat)
						agilityModifier = 0;

						// Set integer variable 'randomDodge' to a random number of 1-100
						//   (for matching usage to determine player's dodge percentage)
						randomDodge = (1 + (rand() % ((100 - 1) + 1)));

						// Set boolean 'fullDodge' to false (to reset upon loop repeat)
						//   (this is used to break out of the loop
						//    if the first dodge check is a success)
						fullDodge = false;

						// 'numIncrease' & 'numIncrease2' are used as the two values
						// for the range of the dodge rate checker, used with 'randomDodge'

						// Set integer 'numIncrease' to 1
						numIncrease = 1;
						// Set integer 'numIncrease2' to the player's dodge rate times 100
						//   (decimal of 0.01-1 to a whole # of 1-100)
						numIncrease2 = (int)(dodgeRate * 100);

						// FIRST DODGE CHECK:
						// If the random dodge check is a success
						//   (randomized num of 1-100 is within the
						//    starting range of the dodge rate checker)
						if (randomDodge > numIncrease && randomDodge <= numIncrease2) {
							// Set boolean 'fullDodge' to true
							fullDodge = true;
						}
						// Otherwise...
						else {
							// Increase the range of the
							// dodge rate checker up one notch
							numIncrease = numIncrease2;
							numIncrease2 = numIncrease2 + 20;
						}

						// Loop five times (after 5 times, dodge rate is guaranteed 0%)
						for (unsigned i = 0;i < 5;++i) {
							// If 'fullDodge' is true (if first check above succeeded)
							if (fullDodge == true) {
								// Break out of the loop
								break;
							}

							// If the modifier is between 0 and 1 (but not actually 1)
							if (agilityModifier < 1 && agilityModifier >= 0) {
								// Increase the modifier by 0.25 (25% less damage avoided)
								agilityModifier = agilityModifier + 0.25;  // Dodges: 100% - 75% - 50% - 25% - 0%
							}
							// If the modifier is equal to 1 (0% damage avoided)
							if (agilityModifier == 1.0) {
								// Break out of the loop
								break;
							}

							// If 'numIncrease' or 'numIncrease2' reaches 100
							//   (the loop ran through all checks to 100%)
							if (numIncrease > 100 || numIncrease2 > 100) {
								// Break out of the loop
								break;
							}
							// NEXT DODGE CHECK:
							// If the dodge check is a success
							//   (randomized num of 1-100 is within the
							//    increased range of the dodge rate checker)
							if (randomDodge > numIncrease && randomDodge <= numIncrease2) {
								// Break out of the loop
								break;
							}

							// Increase the two values of the range of the dodge rate checker
							numIncrease = numIncrease + 20;
							numIncrease2 = numIncrease2 + 20;
						}

						// If the modifier is equal to 0 -- 100% damage avoided (0 x dmg = no dmg taken)
						if (agilityModifier == 0.0) {
							// Output that the player avoided 100% of Goblin 2's damage
							std::cout << "\n  You avoided Goblin 2's attack [" << fMobAttack2 << " DMG] with your agility!" << std::endl;
						}  // OR
						// If the modifier is equal to 1 -- 0% damage avoided (1 x dmg = full dmg taken)
						else if (agilityModifier == 1.0) {
							// Subtract 100% of Goblin 2's attack from the player's health
							player.setHealth(player.getHealth() - fMobAttack2);

							// Output that the player took 100% of Goblin 2's attack
							std::cout << "\n  Goblin 2 counter attacks for " << fMobAttack2 << " damage!" << std::endl;

							// Add the damage the player received to variable 'hpLost'
							//   (for output after the round ends)
							hpLost = (hpLost + fMobAttack2);
						}
						// Otherwise (If the modifier is more than 0 and less than 1 -- 0.25, 0.5, 0.75)...
						else {
							// Subtract Goblin 2's attack (minus the avoided damage) from the player's health
							//   - atk x 0.25 = 75% dmg avoided (Player gets damaged 25% of the enemy's dmg)
							//   - atk x 0.5  = 50% dmg avoided (Player gets damaged 50% of the enemy's dmg)
							//   - atk x 0.75 = 25% dmg avoided (Player gets damaged 75% of the enemy's dmg)
							player.setHealth(player.getHealth() - (fMobAttack2 * agilityModifier));

							// Output the % of damage the player negated and how much damage the player took
							std::cout << "\n  You have negated " << ((1 - agilityModifier) * 100) << "% of Goblin 2's attack damage [" << fMobAttack2 << " DMG] " <<
								"by maneuvering with your agility! You only take " << (fMobAttack2 * agilityModifier) << " damage!" << std::endl;

							// Add the damage the player received to variable 'hpLost'
							//   (for output after the round ends)
							hpLost = (hpLost + (fMobAttack2 * agilityModifier));
						}
					}

					// Otherwise (If Goblin 2 is dead)...
					else {
						// Output that Goblin 2 has perished & how much experience the player gets
						std::cout << "\n  [Goblin 2 has perished.]\n  [EXP+" << goblin2.getEXP() << "]" << std::endl;
					}

					// If Goblin 3 is alive
					if (goblin3.getHealth() > 0) {
						// Output that the other goblin is beginning their attack
						std::cout << "\n\n  [The other goblin begins their attack.]" << std::endl;

						// Set integer variable 'agilityModifier' to 0 (to reset upon loop repeat)
						agilityModifier = 0;

						// Set integer variable 'randomDodge' to a random number of 1-100
						//   (for matching usage to determine player's dodge percentage)
						randomDodge = (1 + (rand() % ((100 - 1) + 1)));

						// Set boolean 'fullDodge' to false (to reset upon loop repeat)
						//   (this is used to break out of the loop
						//    if the first dodge check is a success)
						fullDodge = false;

						// 'numIncrease' & 'numIncrease2' are used as the two values
						// for the range of the dodge rate checker, used with 'randomDodge'

						// Set integer 'numIncrease' to 1
						numIncrease = 1;
						// Set integer 'numIncrease2' to the player's dodge rate times 100
						//   (decimal of 0.01-1 to a whole # of 1-100)
						numIncrease2 = (int)(dodgeRate * 100);

						// FIRST DODGE CHECK:
						// If the dodge check is a success
						//   (randomized num of 1-100 is within the
						//    starting range of the dodge rate checker)
						if (randomDodge > numIncrease && randomDodge <= numIncrease2) {
							// Set boolean 'fullDodge' to true
							fullDodge = true;
						}
						// Otherwise...
						else {
							// Increase the range of the
							// dodge rate checker up one notch
							numIncrease = numIncrease2;
							numIncrease2 = numIncrease2 + 20;
						}

						// Loop five times (after 5 times, dodge rate is guaranteed 0%)
						for (unsigned i = 0;i < 5;++i) {
							// If 'fullDodge' is true (if first check above succeeded)
							if (fullDodge == true) {
								// Break out of the loop
								break;
							}

							// If the modifier is between 0 and 1 (but not actually 1)
							if (agilityModifier < 1 && agilityModifier >= 0) {
								// Increase the modifier by 0.25 (25% less damage avoided)
								agilityModifier = agilityModifier + 0.25;  // Dodges: 100% - 75% - 50% - 25% - 0%
							}
							// If the modifier is equal to 1 (0% damage avoided)
							if (agilityModifier == 1.0) {
								// Break out of the loop
								break;
							}

							// If 'numIncrease' or 'numIncrease2' reaches 100
							//   (the loop ran through all checks to 100%)
							if (numIncrease > 100 || numIncrease2 > 100) {
								// Break out of the loop
								break;
							}
							// NEXT DODGE CHECK:
							// If the dodge check is a success
							//   (randomized num of 1-100 is within the
							//    increased range of the dodge rate checker)
							if (randomDodge > numIncrease && randomDodge <= numIncrease2) {
								// Break out of the loop
								break;
							}

							// Increase the two values of the range of the dodge rate checker
							numIncrease = numIncrease + 20;
							numIncrease2 = numIncrease2 + 20;
						}

						// If the modifier is equal to 0 -- 100% damage avoided (0 x dmg = no dmg taken)
						if (agilityModifier == 0.0) {
							// Output that the player avoided 100% of Goblin 3's damage
							std::cout << "\n  You avoided Goblin 3's attack [" << fMobAttack3 << " DMG] with your agility!" << std::endl;
						}  // OR
						// If the modifier is equal to 1 -- 0% damage avoided (1 x dmg = full dmg taken)
						else if (agilityModifier == 1.0) {
							// Subtract 100% of Goblin 3's attack from the player's health
							player.setHealth(player.getHealth() - fMobAttack3);

							// Output that the player took 100% of Goblin 3's attack
							std::cout << "\n  Goblin 3 attacks you for " << fMobAttack3 << " damage!" << std::endl;

							// Add the damage the player received to variable 'hpLost'
							//   (for output after the round ends)
							hpLost = (hpLost + fMobAttack3);
						}
						// Otherwise (If the modifier is more than 0 and less than 1 -- 0.25, 0.5, 0.75)...
						else {
							// Subtract Goblin 3's attack (minus the avoided damage) from the player's health
							//   - atk x 0.25 = 75% dmg avoided (Player gets damaged 25% of the enemy's dmg)
							//   - atk x 0.5  = 50% dmg avoided (Player gets damaged 50% of the enemy's dmg)
							//   - atk x 0.75 = 25% dmg avoided (Player gets damaged 75% of the enemy's dmg)
							player.setHealth(player.getHealth() - (fMobAttack3 * agilityModifier));

							// Output the % of damage the player negated and how much damage the player took
							std::cout << "\n  You have negated " << ((1 - agilityModifier) * 100) << "% of Goblin 3's attack damage [" << fMobAttack3 << " DMG] " <<
								"by maneuvering with your agility! You only take " << (fMobAttack3 * agilityModifier) << " damage!" << std::endl;

							// Add the damage the player received to variable 'hpLost'
							//   (for output after the round ends)
							hpLost = (hpLost + (fMobAttack3 * agilityModifier));
						}
					}

					// Otherwise (If Goblin 3 is dead)...
					else {
						// Output that Goblin 3 has perished & how much experience the player gets
						std::cout << "\n  [Goblin 3 has perished.]\n  [EXP+" << goblin3.getEXP() << "]" << std::endl;
					}

					// Output the amount of health lost after the round
					std::cout << "\n\n  [-" << hpLost << " HP]" << std::endl;

					std::this_thread::sleep_for(std::chrono::milliseconds(350));  // Pause 0.35 sec
				}
			} while (goblin2.getHealth() > 0 && player.getHealth() > 0);
			// Keep repeating the block of code until Goblin 2 or the player dies

			// If any of the Enemys' health has dropped below zero,
			// set their health to 0 (you can't have negative health)
			if (goblin2.getHealth() < 0) {
				goblin2.setHealth(0);
			}
			if (goblin3.getHealth() < 0) {
				goblin3.setHealth(0);
			}

			// If the player has died
			if (player.getHealth() <= 0) {
				// Run the Death() method
				Death();
				// Terminate the program
				exit(0);
			}

			// Output the health status of player & all enemies
			std::cout << "\n\n  ###############################\n  HP:       (" << player.getHealth() << "/" << player.getMaxHealth() << ")\n  " <<
				"Goblin 1: (" << goblin1.getHealth() << "/" << goblin1.getMaxHealth() << ")\n  " <<
				"Goblin 2: (" << goblin2.getHealth() << "/" << goblin2.getMaxHealth() << ")\n  " <<
				"Goblin 3: (" << goblin3.getHealth() << "/" << goblin3.getMaxHealth() << ")\n  " <<
				"###############################" << std::endl;

			// Update the Character object 'player' by calculating
			// the updated experience from Goblin 2's death
			player = CalculateEXP(player, goblin2);

			// Output to the player that there is only one enemy remaining
			std::cout << "\n\n  There is only one goblin remaining. You're almost there!" << std::endl;

			/*  ===================================================================================  */
			/*  ================================                   ================================  */
			/*  ================================    LAST BATTLE    ================================  */
			/*  ================================                   ================================  */
			/*  ===================================================================================  */

			// ATTACK GOBLIN 3

			// Block of code to loop while Goblin 3 is alive
			do {
				// Output health status of player & all enemies
				std::cout << "\n\n  ###############################\n  HP:       (" << player.getHealth() << "/" << player.getMaxHealth() << ")\n  " <<
					"Goblin 1: (" << goblin1.getHealth() << "/" << goblin1.getMaxHealth() << ")\n  " <<
					"Goblin 2: (" << goblin2.getHealth() << "/" << goblin2.getMaxHealth() << ")\n  " <<
					"Goblin 3: (" << goblin3.getHealth() << "/" << goblin3.getMaxHealth() << ")\n  " <<
					"###############################" << std::endl;

				std::this_thread::sleep_for(std::chrono::milliseconds(200));  // Pause 0.2 sec

				// Ask the player to either Attack or Retreat
				std::cout << "\n  Attack or Retreat? ";
				// Get user input
				option = choiceYesNo("Attack", "Retreat");

				clear();  // Clear console window

				// If option is false -- user chose "Retreat" ('R'/'r')
				if (option == false) {
					// If a random number of 1-3 is 1 (33% chance)
					if ((rand() % 3) == 1) {
						// Output successful escape notification
						std::cout << "\n  You have successfully escaped." << std::endl;

						// Set the health of the enemy to 0
						goblin3.setHealth(0);

						// Go to the location of 'END:' and play from there
						//   (exits the loop & ends the battle)
						goto END;
					}
					// Otherwise (If the random number is not 1 -- the 66% chance of failed retreat passes)...
					else {
						std::this_thread::sleep_for(std::chrono::milliseconds(200));  // Pause 0.2 sec

						// Output failed escape notification
						std::cout << "\n  Retreat failed." << std::endl;

						// If Goblin 3 is still alive
						if (goblin3.getHealth() > 0) {
							// Output free attack
							std::cout << "\n  Goblin 3 got in a free attack. [-10 HP]" << std::endl;

							// Subtract 10 health from the player
							player.setHealth(player.getHealth() - 10);
						}
						// Set option to true
						//   (so that the player attack occurs next)
						option = true;
					}
				}
				// If option is true -- user chose "Attack" ('A'/'a') or failed to retreat
				if (option == true) {
					std::this_thread::sleep_for(std::chrono::milliseconds(350));  // Pause 0.35 sec

					// Set the player's lost hp to 0 (to reset upon loop repeat)
					hpLost = 0;

					// Random Player Damage between: 1/2 Base Atk Damage - Full Base Atk Damage
					attack = ((player.getDamage() / 2) + (rand() % (player.getDamage() - (player.getDamage() / 2) + 1)));
					// Random Enemy Damage between: 1/2 Base Atk Damage - Full Base Atk Damage
					mobAttack3 = ((goblin3.getDamage() / 2) + (rand() % (goblin3.getDamage() - (goblin3.getDamage() / 2) + 1)));

					// Modify Player attack to subtract 1/2 DEF Stat Value Multiplied by Level (Higher Defense & Higher Level = Less Damage Taken)
					fAttack = attack - ((goblin3.getLevel() * goblin3.getDEF()) / 2);
					// Modify Enemy attack to subtract 1/2 True DEF Stat Value Multiplied by Level (Higher Defense & Higher Level = Less Damage Taken)
					fMobAttack3 = mobAttack3 - ((player.getLevel() * (player.getDEF() + player.getDEFBoost())) / 2);

					// If any attack damages are less than zero
					// Set them to zero (there can't be negative damage)
					if (fAttack < 0) {
						fAttack = 0;
					}
					if (fMobAttack3 < 0) {
						fMobAttack3 = 0;
					}

					// Set the player's dodge rate to double variable 'dodgeRate'
					//   (for dodge rate percentage calculations)
					dodgeRate = player.getDodgeRate();

					// Subtract Goblin 3's health by the player's attack damage
					goblin3.setHealth(goblin3.getHealth() - fAttack);

					// Output attack notification
					std::cout << "\n  You attack Goblin 3 for " << fAttack << " damage!" << std::endl;

					std::this_thread::sleep_for(std::chrono::milliseconds(200));  // Pause 0.2 sec

					// If Goblin 3 is alive
					if (goblin3.getHealth() > 0) {
						// Output that Goblin 3 is beginning a counter attack
						std::cout << "\n  [Goblin 3 begins their counter attack.]" << std::endl;

						// Set integer variable 'agilityModifier' to 0 (to reset upon loop repeat)
						agilityModifier = 0;

						// Set integer variable 'randomDodge' to a random number of 1-100
						//   (for matching usage to determine player's dodge percentage)
						randomDodge = (1 + (rand() % ((100 - 1) + 1)));

						// Set boolean 'fullDodge' to false (to reset upon loop repeat)
						//   (this is used to break out of the loop
						//    if the first dodge check is a success)
						fullDodge = false;

						// 'numIncrease' & 'numIncrease2' are used as the two values
						// for the range of the dodge rate checker, used with 'randomDodge'

						// Set integer 'numIncrease' to 1
						numIncrease = 1;
						// Set integer 'numIncrease2' to the player's dodge rate times 100
						//   (decimal of 0.1-1 to a whole # of 1-100)
						numIncrease2 = (int)(dodgeRate * 100);

						// FIRST DODGE CHECK:
						// If the dodge check is a success
						//   (randomized num of 1-100 is within the
						//    starting range of the dodge rate checker)
						if (randomDodge > numIncrease && randomDodge <= numIncrease2) {
							// Set boolean 'fullDodge' to true
							fullDodge = true;
						}
						// Otherwise...
						else {
							// Increase the range of the
							// dodge rate checker up one notch
							numIncrease = numIncrease2;
							numIncrease2 = numIncrease2 + 20;
						}

						// Loop five times (after 5 times, dodge rate is guaranteed 0%)
						for (unsigned i = 0;i < 5;++i) {
							// If 'fullDodge' is true (if first check above succeeded)
							if (fullDodge == true) {
								// Break out of the loop
								break;
							}

							// If the modifier is between 0 and 1 (but not actually 1)
							if (agilityModifier < 1 && agilityModifier >= 0) {
								// Increase the modifier by 0.25 (25% less damage avoided)
								agilityModifier = agilityModifier + 0.25;  // Dodges: 100% - 75% - 50% - 25% - 0%
							}
							// If the modifier is equal to 1 (0% damage avoided)
							if (agilityModifier == 1.0) {
								// Break out of the loop
								break;
							}

							// If 'numIncrease' or 'numIncrease2' reaches 100
							//   (the loop ran through all checks to 100%)
							if (numIncrease > 100 || numIncrease2 > 100) {
								// Break out of the loop
								break;
							}
							// NEXT DODGE CHECK:
							// If the dodge check is a success
							//   (randomized num of 1-100 is within the
							//    increased range of the dodge rate checker)
							if (randomDodge > numIncrease && randomDodge <= numIncrease2) {
								// Break out of the loop
								break;
							}

							// Increase the two values of the range of the dodge rate checker
							numIncrease = numIncrease + 20;
							numIncrease2 = numIncrease2 + 20;
						}

						// If the modifier is equal to 0 -- 100% damage avoided (0 x dmg = no dmg taken)
						if (agilityModifier == 0.0) {
							// Output that the player avoided 100% of Goblin 3's damage
							std::cout << "\n  You avoided Goblin 3's attack [" << fMobAttack3 << " DMG] with your agility!" << std::endl;
						}  // OR
						// If the modifier is equal to 1 -- 0% damage avoided (1 x dmg = full dmg taken)
						else if (agilityModifier == 1.0) {
							// Subtract 100% of Goblin 3's attack from the player's health
							player.setHealth(player.getHealth() - fMobAttack3);

							// Output that the player took 100% of Goblin 3's attack
							std::cout << "\n  Goblin 3 counter attacks for " << fMobAttack3 << " damage!" << std::endl;

							// Add the damage the player received to variable 'hpLost'
							//   (for output after the round ends)
							hpLost = (hpLost + fMobAttack3);
						}
						// Otherwise (If the modifier is more than 0 and less than 1 -- 0.25, 0.5, 0.75)...
						else {
							// Subtract Goblin 3's attack (minus the avoided damage) from the player's health
							//   - atk x 0.25 = 75% dmg avoided (Player gets damaged 25% of the enemy's dmg)
							//   - atk x 0.5  = 50% dmg avoided (Player gets damaged 50% of the enemy's dmg)
							//   - atk x 0.75 = 25% dmg avoided (Player gets damaged 75% of the enemy's dmg)
							player.setHealth(player.getHealth() - (fMobAttack3 * agilityModifier));

							// Output the % of damage the player negated and how much damage the player took
							std::cout << "\n  You have negated " << ((1 - agilityModifier) * 100) << "% of Goblin 3's attack damage [" << fMobAttack3 << " DMG] " <<
								"by maneuvering with your agility! You only take " << (fMobAttack3 * agilityModifier) << " damage!" << std::endl;

							// Add the damage the player received to variable 'hpLost'
							//   (for output after the round ends)
							hpLost = (hpLost + (fMobAttack3 * agilityModifier));
						}
					}

					// Otherwise (If Goblin 3 is dead)...
					else {
						// Output that Goblin 3 has perished & how much experience the player gets
						std::cout << "\n  [Goblin 3 has perished.]\n  [EXP+" << goblin3.getEXP() << "]" << std::endl;
					}

					// If Goblin 3 is alive
					if (goblin3.getHealth() > 0) {
						// Output the amount of health lost after the round
						std::cout << "\n\n  [-" << hpLost << " HP]" << std::endl;
					}

					std::this_thread::sleep_for(std::chrono::milliseconds(350));  // Pause 0.35 sec
				}
			} while (goblin3.getHealth() > 0 && player.getHealth() > 0);
			// Keep repeating the block of code until Goblin 3 or the player dies

			// If the Enemy's health has dropped below zero, set
			// their health to 0 (you can't have negative health)
			if (goblin3.getHealth() < 0) {
				goblin3.setHealth(0);
			}

			// If the player has died
			if (player.getHealth() <= 0) {
				// Run the Death() method
				Death();
				// Terminate the program
				exit(0);
			}

			// Output the health status of player & all enemies
			std::cout << "\n\n  ###############################\n  HP:       (" << player.getHealth() << "/" << player.getMaxHealth() << ")\n  " <<
				"Goblin 1: (" << goblin1.getHealth() << "/" << goblin1.getMaxHealth() << ")\n  " <<
				"Goblin 2: (" << goblin2.getHealth() << "/" << goblin2.getMaxHealth() << ")\n  " <<
				"Goblin 3: (" << goblin3.getHealth() << "/" << goblin3.getMaxHealth() << ")\n  " <<
				"###############################" << std::endl;

			// Update the Character object 'player' by calculating
			// the updated experience from Goblin 3's death
			player = CalculateEXP(player, goblin3);

			// Output completion notification
			std::cout << "\n\n  Congratulations, you have killed the goblins!!\n  What now?" << std::endl;
		}

		// If user chose Goblin 3 ('B'/'b')
		// ATTACK GOBLIN 3 -- GOBLIN 2 STILL ALIVE
		else if (optionChar == 'B')
		{
			// Block of code to loop while Goblin 3 is still alive
			do {
				// Output health status of player & all enemies
				std::cout << "\n\n  ###############################\n  HP:       (" << player.getHealth() << "/" << player.getMaxHealth() << ")\n  " <<
					"Goblin 1: (" << goblin1.getHealth() << "/" << goblin1.getMaxHealth() << ")\n  " <<
					"Goblin 2: (" << goblin2.getHealth() << "/" << goblin2.getMaxHealth() << ")\n  " <<
					"Goblin 3: (" << goblin3.getHealth() << "/" << goblin3.getMaxHealth() << ")\n  " <<
					"###############################" << std::endl;

				std::this_thread::sleep_for(std::chrono::milliseconds(200));  // Pause 0.2 sec

				// Ask the player to either Attack or Retreat
				std::cout << "\n  Attack or Retreat? ";
				// Get user input
				option = choiceYesNo("Attack", "Retreat");

				clear();  // Clear console window

				// If option is false -- user chose "Retreat" ('R'/'r')
				if (option == false) {
					// If a random number of 1-3 is 1 (33% chance)
					if ((rand() % 3) == 1) {
						// Output successful escape notification
						std::cout << "\n  You have successfully escaped." << std::endl;

						// Set the health of all remaining enemies to 0
						goblin2.setHealth(0);
						goblin3.setHealth(0);

						// Go to the location of 'END:' and play from there
						//   (exits the loop & ends the battle)
						goto END;
					}
					// Otherwise (If the random number is not 1 -- the 66% chance of failed retreat passes)...
					else {
						std::this_thread::sleep_for(std::chrono::milliseconds(200));  // Pause 0.2 sec

						// Output failed escape notification
						std::cout << "\n  Retreat failed." << std::endl;

						// If Goblin 2 is still alive
						if (goblin2.getHealth() > 0) {
							// Output free attack
							std::cout << "\n  Goblin 2 got in a free attack. [-10 HP]" << std::endl;

							// Subtract 10 health from the player
							player.setHealth(player.getHealth() - 10);
						}
						// If Goblin 3 is still alive
						if (goblin3.getHealth() > 0) {
							// Output free attack
							std::cout << "  Goblin 3 got in a free attack. [-10 HP]" << std::endl;

							// Subtract 10 health from the player
							player.setHealth(player.getHealth() - 10);
						}
						// Set option to true
						//   (so that the player attack occurs next)
						option = true;
					}
				}
				// If option is true -- user chose "Attack" ('A'/'a') or failed to retreat
				if (option == true) {
					std::this_thread::sleep_for(std::chrono::milliseconds(350));  // Pause 0.35 sec

					// Set the player's lost hp to 0 (to reset upon loop repeat)
					hpLost = 0;

					// Random Player Damage between: 1/2 Base Atk Damage - Full Base Atk Damage
					attack = ((player.getDamage() / 2) + (rand() % (player.getDamage() - (player.getDamage() / 2) + 1)));
					// Random Enemy Damage between: 1/2 Base Atk Damage - Full Base Atk Damage
					mobAttack2 = ((goblin2.getDamage() / 2) + (rand() % (goblin2.getDamage() - (goblin2.getDamage() / 2) + 1)));
					mobAttack3 = ((goblin3.getDamage() / 2) + (rand() % (goblin3.getDamage() - (goblin3.getDamage() / 2) + 1)));

					// Modify Player attack to subtract 1/2 DEF Stat Value Multiplied by Level (Higher Defense & Higher Level = Less Damage Taken)
					fAttack = attack - ((goblin3.getLevel() * goblin3.getDEF()) / 2);
					// Modify Enemy attack to subtract 1/2 True DEF Stat Value Multiplied by Level (Higher Defense & Higher Level = Less Damage Taken)
					fMobAttack2 = mobAttack2 - ((player.getLevel() * (player.getDEF() + player.getDEFBoost())) / 2);
					fMobAttack3 = mobAttack3 - ((player.getLevel() * (player.getDEF() + player.getDEFBoost())) / 2);

					// If any attack damages are less than zero
					// Set them to zero (there can't be negative damage)
					if (fAttack < 0) {
						fAttack = 0;
					}
					if (fMobAttack2 < 0) {
						fMobAttack2 = 0;
					}
					if (fMobAttack3 < 0) {
						fMobAttack3 = 0;
					}

					// Set the player's dodge rate to double variable 'dodgeRate'
					//   (for dodge rate percentage calculations)
					dodgeRate = player.getDodgeRate();

					// Subtract Goblin 3's health by the player's attack damage
					goblin3.setHealth(goblin3.getHealth() - fAttack);

					// Output attack notification
					std::cout << "\n  You attack Goblin 3 for " << fAttack << " damage!" << std::endl;

					std::this_thread::sleep_for(std::chrono::milliseconds(200));  // Pause 0.2 sec

					// If Goblin 3 is alive
					if (goblin3.getHealth() > 0) {
						// Output that Goblin 3 is beginning a counter attack
						std::cout << "\n  [Goblin 3 begins their counter attack.]" << std::endl;

						// Set integer variable 'agilityModifier' to 0 (to reset upon loop repeat)
						agilityModifier = 0;

						// Set integer variable 'randomDodge' to a random number of 1-100
						//   (for matching usage to determine player's dodge percentage)
						randomDodge = (1 + (rand() % ((100 - 1) + 1)));

						// Set boolean 'fullDodge' to false (to reset upon loop repeat)
						//   (this is used to break out of the loop
						//    if the first dodge check is a success)
						fullDodge = false;

						// 'numIncrease' & 'numIncrease2' are used as the two values
						// for the range of the dodge rate checker, used with 'randomDodge'

						// Set integer 'numIncrease' to 1
						numIncrease = 1;
						// Set integer 'numIncrease2' to the player's dodge rate times 100
						//   (decimal of 0.01-1 to a whole # of 1-100)
						numIncrease2 = (int)(dodgeRate * 100);

						// FIRST DODGE CHECK:
						// If the dodge check is a success
						//   (randomized num of 1-100 is within the
						//    starting range of the dodge rate checker)
						if (randomDodge > numIncrease && randomDodge <= numIncrease2) {
							// Set boolean 'fullDodge' to true
							fullDodge = true;
						}
						// Otherwise...
						else {
							// Increase the range of the
							// dodge rate checker up one notch
							numIncrease = numIncrease2;
							numIncrease2 = numIncrease2 + 20;
						}

						// Loop five times (after 5 times, dodge rate is guaranteed 0%)
						for (unsigned i = 0;i < 5;++i) {
							// If 'fullDodge' is true (if first check above succeeded)
							if (fullDodge == true) {
								// Break out of the loop
								break;
							}

							// If the modifier is between 0 and 1 (but not actually 1)
							if (agilityModifier < 1 && agilityModifier >= 0) {
								// Increase the modifier by 0.25 (25% less damage avoided)
								agilityModifier = agilityModifier + 0.25;  // Dodges: 100% - 75% - 50% - 25% - 0%
							}
							// If the modifier is equal to 1 (0% damage avoided)
							if (agilityModifier == 1.0) {
								// Break out of the loop
								break;
							}

							// If 'numIncrease' or 'numIncrease2' reaches 100
							//   (the loop ran through all checks to 100%)
							if (numIncrease > 100 || numIncrease2 > 100) {
								// Break out of the loop
								break;
							}
							// NEXT DODGE CHECK:
							// If the dodge check is a success
							//   (randomized num of 1-100 is within the
							//    increased range of the dodge rate checker)
							if (randomDodge > numIncrease && randomDodge <= numIncrease2) {
								// Break out of the loop
								break;
							}

							// Increase the two values of the range of the dodge rate checker
							numIncrease = numIncrease + 20;
							numIncrease2 = numIncrease2 + 20;
						}

						// If the modifier is equal to 0 -- 100% damage avoided (0 x dmg = no dmg taken)
						if (agilityModifier == 0.0) {
							// Output that the player avoided 100% of Goblin 3's attack
							std::cout << "\n  You avoided Goblin 3's attack [" << fMobAttack3 << " DMG] with your agility!" << std::endl;
						}  // OR
						// If the modifier is equal to 1 -- 0% damage avoided (1 x dmg = full dmg taken)
						else if (agilityModifier == 1.0) {
							// Subtract 100% of Goblin 3's attack from the player's health
							player.setHealth(player.getHealth() - fMobAttack3);

							// Output that the player took 100% of Goblin 3's attacks
							std::cout << "\n  Goblin 3 counter attacks for " << fMobAttack3 << " damage!" << std::endl;

							// Add the damage the player received to variable 'hpLost'
							//   (for output after the round ends)
							hpLost = (hpLost + fMobAttack3);
						}
						// Otherwise (If the modifier is more than 0 and less than 1 -- 0.25, 0.5, 0.75)...
						else {
							// Subtract Goblin 3's attack (minus the avoided damage) from the player's health
							//   - atk x 0.25 = 75% dmg avoided (Player gets damaged 25% of the enemy's dmg)
							//   - atk x 0.5  = 50% dmg avoided (Player gets damaged 50% of the enemy's dmg)
							//   - atk x 0.75 = 25% dmg avoided (Player gets damaged 75% of the enemy's dmg)
							player.setHealth(player.getHealth() - (fMobAttack3 * agilityModifier));

							// Output the % of damage the player negated and how much damage the player took
							std::cout << "\n  You have negated " << ((1 - agilityModifier) * 100) << "% of Goblin 3's attack damage [" << fMobAttack3 << " DMG] " <<
								"by maneuvering with your agility! You only take " << (fMobAttack3 * agilityModifier) << " damage!" << std::endl;

							// Add the damage the player received to variable 'hpLost'
							//   (for output after the round ends)
							hpLost = (hpLost + (fMobAttack3 * agilityModifier));
						}
					}

					// Otherwise (if Goblin 3 is dead)...
					else {
						// Output that Goblin 3 has perished & how much experience the player gets
						std::cout << "\n  [Goblin 3 has perished.]\n  [EXP+" << goblin3.getEXP() << "]" << std::endl;
					}

					// If Goblin 2 is alive
					if (goblin2.getHealth() > 0) {
						// Output that the other goblin is beginning their attack
						std::cout << "\n\n  [The other goblin begins their attack.]" << std::endl;

						// Set integer variable 'agilityModifier' to 0 (to reset upon loop repeat)
						agilityModifier = 0;

						// Set integer variable 'randomDodge' to a random number of 1-100
						//   (for matching usage to determine player's dodge percentage)
						randomDodge = (1 + (rand() % ((100 - 1) + 1)));

						// Set boolean 'fullDodge' to false (to reset upon loop repeat)
						//   (this is used to break out of the loop
						//    if the first dodge check is a success)
						fullDodge = false;

						// 'numIncrease' & 'numIncrease2' are used as the two values
						// for the range of the dodge rate checker, used with 'randomDodge'

						// Set integer 'numIncrease' to 1
						numIncrease = 1;
						// Set integer 'numIncrease2' to the player's dodge rate times 100
						//   (decimal of 0.01-1 to a whole # 1-100)
						numIncrease2 = (int)(dodgeRate * 100);

						// FIRST DODGE CHECK:
						// If the dodge check is a success
						//   (randomized num of 1-100 is within the
						//    starting range of the dodge rate checker)
						if (randomDodge > numIncrease && randomDodge <= numIncrease2) {
							// Set boolean 'fullDodge' to true
							fullDodge = true;
						}
						// Otherwise...
						else {
							// Increase the range of the
							// dodge rate checker up one notch
							numIncrease = numIncrease2;
							numIncrease2 = numIncrease2 + 20;
						}

						// Loop five times (after 5 times, dodge rate is guaranteed 0%)
						for (unsigned i = 0;i < 5;++i) {
							// If 'fullDodge' is true (if first check above succeeded)
							if (fullDodge == true) {
								// Break out of the loop
								break;
							}

							// If the modifier is between 0 and 1 (but not actually 1)
							if (agilityModifier < 1 && agilityModifier >= 0) {
								// Increase the modifier by 0.25 (25% less damage avoided)
								agilityModifier = agilityModifier + 0.25;  // Dodges: 100% - 75% - 50% - 25% - 0%
							}
							// If the modifier is equal to 1 (0% damage avoided)
							if (agilityModifier == 1.0) {
								// Break out of the loop
								break;
							}

							// If 'numIncrease' or 'numIncrease2' reaches 100
							//   (the loop ran through all checks to 100%)
							if (numIncrease > 100 || numIncrease2 > 100) {
								// Break out of the loop
								break;
							}
							// NEXT DODGE CHECK:
							// If the dodge check is a success
							//   (randomized num of 1-100 is within the
							//    increased range of the dodge rate checker)
							if (randomDodge > numIncrease && randomDodge <= numIncrease2) {
								// Break out of the loop
								break;
							}

							// Increase the two values of the range of the dodge rate checker
							numIncrease = numIncrease + 20;
							numIncrease2 = numIncrease2 + 20;
						}

						// If the modifier is equal to 0 -- 100% damage avoided (0 x dmg = no dmg taken)
						if (agilityModifier == 0.0) {
							// Output that the player avoided 100% of Goblin 2's damage
							std::cout << "\n  You avoided Goblin 2's attack [" << fMobAttack2 << " DMG] with your agility!" << std::endl;
						}  // OR
						// If the modifier is equal to 1 -- 0% damage avoided (1 x dmg = full dmg taken)
						else if (agilityModifier == 1.0) {
							// Subtract 100% of Goblin 2's attack from the player's health
							player.setHealth(player.getHealth() - fMobAttack2);

							// Output that the player took 100% of Goblin 2's attack
							std::cout << "\n  Goblin 2 attacks you for " << fMobAttack2 << " damage!" << std::endl;

							// Add the damage the player received to variable 'hpLost'
							//   (for output after the round ends)
							hpLost = (hpLost + fMobAttack2);
						}
						// Otherwise (If the modifier is more than 0 and less than 1 -- 0.25, 0.5, 0.75)...
						else {
							// Subtract Goblin 2's attack (minus the avoided damage) from the player's health
							//   - atk x 0.25 = 75% dmg avoided (Player gets damaged 25% of the enemy's dmg)
							//   - atk x 0.50 = 50% dmg avoided (Player gets damaged 50% of the enemy's dmg)
							//   - atk x 0.75 = 25% dmg avoided (Player gets damaged 75% of the enemy's dmg)
							player.setHealth(player.getHealth() - (fMobAttack2 * agilityModifier));

							// Output the % of the damage the player negated and how much damage the player took
							std::cout << "\n  You have negated " << ((1 - agilityModifier) * 100) << "% of Goblin 2's attack damage [" << fMobAttack2 << " DMG] " <<
								"by maneuvering with your agility! You only take " << (fMobAttack2 * agilityModifier) << " damage!" << std::endl;

							// Add the damage the player received to variable 'hpLost'
							//   (for output after the round ends)
							hpLost = (hpLost + (fMobAttack2 * agilityModifier));
						}
					}

					// Otherwise (If Goblin 2 is dead)...
					else {
						// Output that Goblin 2 has perished & how much experience the player gets
						std::cout << "\n  [Goblin 2 has perished.]\n  [EXP+" << goblin2.getEXP() << "]" << std::endl;
					}

					// Output the amount of health lost after the round
					std::cout << "\n\n  [-" << hpLost << " HP]" << std::endl;

					std::this_thread::sleep_for(std::chrono::milliseconds(350));  // Pause 0.35 sec
				}
			} while (goblin3.getHealth() > 0 && player.getHealth() > 0);
			// Keep repeating the block of code until Goblin 3 or the player dies

			// If any of the Enemys' health has dropped below zero,
			// set their health to 0 (you can't have negative health)
			if (goblin2.getHealth() < 0) {
				goblin2.setHealth(0);
			}
			if (goblin3.getHealth() < 0) {
				goblin3.setHealth(0);
			}

			// If the player has died
			if (player.getHealth() <= 0) {
				// Run the Death() method
				Death();
				// Terminate the program
				exit(0);
			}

			// Output the health status of player & all enemies
			std::cout << "\n\n  ###############################\n  HP:       (" << player.getHealth() << "/" << player.getMaxHealth() << ")\n  " <<
				"Goblin 1: (" << goblin1.getHealth() << "/" << goblin1.getMaxHealth() << ")\n  " <<
				"Goblin 2: (" << goblin2.getHealth() << "/" << goblin2.getMaxHealth() << ")\n  " <<
				"Goblin 3: (" << goblin3.getHealth() << "/" << goblin3.getMaxHealth() << ")\n  " <<
				"###############################" << std::endl;

			// Update the Character object 'player' by calculating
			// the updated experience from Goblin 3's death
			player = CalculateEXP(player, goblin3);

			// Output to the player that there is only one enemy remaining
			std::cout << "\n\n  There is only one goblin remaining. You're almost there!" << std::endl;

			/*  ===================================================================================  */
			/*  ================================                   ================================  */
			/*  ================================    LAST BATTLE    ================================  */
			/*  ================================                   ================================  */
			/*  ===================================================================================  */

			// ATTACK GOBLIN 2

			// Block of code to loop while Goblin 3 is alive
			do {
				// Output health status of player & all enemies
				std::cout << "\n\n  ###############################\n  HP:       (" << player.getHealth() << "/" << player.getMaxHealth() << ")\n  " <<
					"Goblin 1: (" << goblin1.getHealth() << "/" << goblin1.getMaxHealth() << ")\n  " <<
					"Goblin 2: (" << goblin2.getHealth() << "/" << goblin2.getMaxHealth() << ")\n  " <<
					"Goblin 3: (" << goblin3.getHealth() << "/" << goblin3.getMaxHealth() << ")\n  " <<
					"###############################" << std::endl;

				std::this_thread::sleep_for(std::chrono::milliseconds(200));  // Pause 0.2 sec

				// Ask the player to either Attack or Retreat
				std::cout << "\n  Attack or Retreat? ";
				// Get user input
				option = choiceYesNo("Attack", "Retreat");

				clear();  // Clear console window

				// If option is false -- user chose "Retreat" ('R'/'r')
				if (option == false) {
					// If a random number of 1-3 is 1 (33% chance)
					if ((rand() % 3) == 1) {
						// Output successful escape notification
						std::cout << "\n  You have successfully escaped." << std::endl;

						// Set the health of the enemy to 0
						goblin2.setHealth(0);

						// Go to the location of 'END:' and play from there
						//   (exits the loop & ends the battle)
						goto END;
					}
					// Otherwise (If the random number is not 1 -- the 66% of failed retreat passes)...
					else {
						std::this_thread::sleep_for(std::chrono::milliseconds(200));  // Pause 0.2 sec

						// Output failed escape notification
						std::cout << "\n  Retreat failed." << std::endl;

						// If Goblin 2 is still alive
						if (goblin2.getHealth() > 0) {
							// Output free attack
							std::cout << "\n  Goblin 2 got in a free attack. [-10 HP]" << std::endl;

							// Subtract 10 health from the player
							player.setHealth(player.getHealth() - 10);
						}
						// Set option to true
						//   (so that the player attack occurs next)
						option = true;
					}
				}
				// If option is true -- user chose "Attack" ('A'/'a') or failed to retreat
				if (option == true) {
					std::this_thread::sleep_for(std::chrono::milliseconds(350));  // Pause 0.35 sec

					// Set the player's lost hp to 0 (to reset upon loop repeat)
					hpLost = 0;

					// Random Player Damage between: 1/2 Base Atk Damage - Full Base Atk Damage
					attack = ((player.getDamage() / 2) + (rand() % (player.getDamage() - (player.getDamage() / 2) + 1)));
					// Random Enemy Damage between: 1/2 Base Atk Damage - Full Base Atk Damage
					mobAttack2 = ((goblin2.getDamage() / 2) + (rand() % (goblin2.getDamage() - (goblin2.getDamage() / 2) + 1)));

					// Modify Player attack to subtract 1/2 DEF Stat Value Multiplied by Level (Higher Defense & Higher Level = Less Damage Taken)
					fAttack = attack - ((goblin2.getLevel() * goblin2.getDEF()) / 2);
					// Modify Enemy attack to subtract 1/2 True DEF Stat Value Multiplied by Level (Higher Defense & Higher Level = Less Damage Taken)
					fMobAttack2 = mobAttack2 - ((player.getLevel() * (player.getDEF() + player.getDEFBoost())) / 2);

					// If any attack damages are less than zero
					// Set them to zero (there can't be negative damage)
					if (fAttack < 0) {
						fAttack = 0;
					}
					if (fMobAttack2 < 0) {
						fMobAttack2 = 0;
					}

					// Set the player's dodge rate to double variable 'dodgeRate'
					//   (for dodge rate percentage calculations)
					dodgeRate = player.getDodgeRate();

					// Subtract Goblin 2's health by the player's attack damage
					goblin2.setHealth(goblin2.getHealth() - fAttack);

					// Output attack notification
					std::cout << "\n  You attack Goblin 2 for " << fAttack << " damage!" << std::endl;

					std::this_thread::sleep_for(std::chrono::milliseconds(200));  // Pause 0.2 sec

					// If Goblin 2 is alive
					if (goblin2.getHealth() > 0) {
						// Output that Goblin 2 is beginning a counter attack
						std::cout << "\n  [Goblin 2 begins their counter attack.]" << std::endl;

						// Set integer variable 'agilityModifier' to 0 (to reset upon loop repeat)
						agilityModifier = 0;

						// Set integer variable 'randomDodge' to a random number of 1-100
						//   (for matching usage to determine player's dodge percentage)
						randomDodge = (1 + (rand() % ((100 - 1) + 1)));

						// Set boolean 'fullDodge' to false (to reset upon loop repeat)
						//   (this is used to break out of the loop
						//    if the first dodge check is a success)
						fullDodge = false;

						// Set integer 'numIncrease' to 1
						numIncrease = 1;
						// Set integer 'numIncrease2' to the player's dodge rate times 100
						//   (decimal of 0.1-1 to a whole # of 1-100)
						numIncrease2 = (int)(dodgeRate * 100);

						// FIRST DODGE CHECK:
						// If the dodge check is a success
						//   (randomized num of 1-100 is within the
						//    starting range of the dodge rate checker)
						if (randomDodge > numIncrease && randomDodge <= numIncrease2) {
							// Set boolean 'fullDodge' to true
							fullDodge = true;
						}
						// Otherwise...
						else {
							// Increase the range of the
							// dodge rate checker up one notch
							numIncrease = numIncrease2;
							numIncrease2 = numIncrease2 + 20;
						}

						// Loop five times (after 5 times, dodge rate is guaranteed 0%)
						for (unsigned i = 0;i < 5;++i) {
							// If 'fullDodge' is true (if first check above succeeded)
							if (fullDodge == true) {
								// Break out of the loop
								break;
							}

							// If the modifier is between 0 and 1 (but not actually 1)
							if (agilityModifier < 1 && agilityModifier >= 0) {
								// Increase the modifier by 0.25 (25% less damage avoided)
								agilityModifier = agilityModifier + 0.25;  // Dodges: 100% - 75% - 50% - 25% - 0%
							}
							// If the modifier is equal to 1 (0% damage avoided)
							if (agilityModifier == 1.0) {
								// Break out of the loop
								break;
							}

							// If 'numIncrease' or 'numIncrease2' reaches 100
							//   (the loop ran through all checks to 100%)
							if (numIncrease > 100 || numIncrease2 > 100) {
								// Break out of the loop
								break;
							}
							// NEXT DODGE CHECK:
							// If the dodge check is a success
							//   (randomized num of 1-100 is within the
							//    increased range of the dodge rate checker)
							if (randomDodge > numIncrease && randomDodge <= numIncrease2) {
								// Break out of the loop
								break;
							}

							// Increase the two values of the range of the dodge rate checker
							numIncrease = numIncrease + 20;
							numIncrease2 = numIncrease2 + 20;
						}

						// If the modifier is equal to 0 -- 100% damage avoided (0 x dmg = no dmg taken)
						if (agilityModifier == 0.0) {
							// Output that the player avoided 100% of Goblin 2's damage
							std::cout << "\n  You avoided Goblin 2's attack [" << fMobAttack2 << " DMG] with your agility!" << std::endl;
						}  // OR
						// If the modifier is equal to 1 -- 0% damage avoided (1 x dmg = full dmg taken)
						else if (agilityModifier == 1.0) {
							// Subtract 100% of Goblin 2's attack from the player's health
							player.setHealth(player.getHealth() - fMobAttack2);

							// Output that the player took 100% of Goblin 2's attack
							std::cout << "\n  Goblin 2 counter attacks for " << fMobAttack2 << " damage!" << std::endl;

							// Add the damage the player received to variable 'hpLost'
							//   (for output after the round ends)
							hpLost = (hpLost + fMobAttack2);
						}
						// Otherwise (If the modifier is more than 0 and less than 1 -- 0.25, 0.5, 0.75)...
						else {
							// Subtract Goblin 2's attack (minus the avoided damage) from the player's health
							//   - atk x 0.25 = 75% dmg avoided (Player gets damaged 25% of the enemy's dmg)
							//   - atk x 0.50 = 50% dmg avoided (Player gets damaged 50% of the enemy's dmg)
							//   - atk x 0.75 = 25% dmg avoided (Player gets damaged 75% of the enemy's dmg)
							player.setHealth(player.getHealth() - (fMobAttack2 * agilityModifier));

							// Output the % of damage the player negated and how much damage the player took
							std::cout << "\n  You have negated " << ((1 - agilityModifier) * 100) << "% of Goblin 2's attack damage [" << fMobAttack2 << " DMG] " <<
								"by maneuvering with your agility! You only take " << (fMobAttack2 * agilityModifier) << " damage!" << std::endl;

							// Add the damage the player received to variable 'hpLost'
							//   (for output after the round ends)
							hpLost = (hpLost + (fMobAttack2 * agilityModifier));
						}
					}

					// Otherwise (If Goblin 2 is dead)...
					else {
						// Output that Goblin 2 has perished & how much experience the player gets
						std::cout << "\n  [Goblin 2 has perished.]\n  [EXP+" << goblin2.getEXP() << "]" << std::endl;
					}

					// If Goblin 2 is alive
					if (goblin2.getHealth() > 0) {
						// Output the amount of health lost after the round
						std::cout << "\n\n  [-" << hpLost << " HP]" << std::endl;
					}

					std::this_thread::sleep_for(std::chrono::milliseconds(350));  // Pause 0.35 sec
				}
			} while (goblin2.getHealth() > 0 && player.getHealth() > 0);
			// Keep repeating the block of code until Goblin 2 or the player dies

			// If the Enemy's health has dropped below zero, set
			// their health to 0 (you can't have negative health)
			if (goblin2.getHealth() < 0) {
				goblin2.setHealth(0);
			}

			// If the player has died
			if (player.getHealth() <= 0) {
				// Run the Death() method
				Death();
				// Terminate the program
				exit(0);
			}

			// Output the health status of player & all enemies
			std::cout << "\n\n  ###############################\n  HP:       (" << player.getHealth() << "/" << player.getMaxHealth() << ")\n  " <<
				"Goblin 1: (" << goblin1.getHealth() << "/" << goblin1.getMaxHealth() << ")\n  " <<
				"Goblin 2: (" << goblin2.getHealth() << "/" << goblin2.getMaxHealth() << ")\n  " <<
				"Goblin 3: (" << goblin3.getHealth() << "/" << goblin3.getMaxHealth() << ")\n  " <<
				"###############################" << std::endl;

			// Update the Character object 'player' by calculating
			// the updated experience from Goblin 2's death
			player = CalculateEXP(player, goblin2);

			// Output completion notification
			std::cout << "\n\n  Congratulations, you have killed the goblins!!\n  What now?" << std::endl;
		}
	}

	// If user chose Goblin 2 ('B'/'b')
	// ATTACK GOBLIN 2 -- GOBLIN 1/3 STILL ALIVE
	else if (optionChar == 'B')
	{
		// Block of code to loop while Goblin 2 is still alive
		do {
			// Output health status of player & all enemies
			std::cout << "\n\n  ###############################\n  HP:       (" << player.getHealth() << "/" << player.getMaxHealth() << ")\n  " <<
				"Goblin 1: (" << goblin1.getHealth() << "/" << goblin1.getMaxHealth() << ")\n  " <<
				"Goblin 2: (" << goblin2.getHealth() << "/" << goblin2.getMaxHealth() << ")\n  " <<
				"Goblin 3: (" << goblin3.getHealth() << "/" << goblin3.getMaxHealth() << ")\n  " <<
				"###############################" << std::endl;

			std::this_thread::sleep_for(std::chrono::milliseconds(200));  // Pause 0.2 sec

			// Ask the player to either Attack or Retreat
			std::cout << "\n  Attack or Retreat? ";
			// Get user input
			option = choiceYesNo("Attack", "Retreat");

			clear();  // Clear console window

			// If option is false -- user chose "Retreat" ('R'/'r')
			if (option == false) {
				// If a random number of 1-3 is 1 (33% chance)
				if ((rand() % 3) == 1) {
					// Output successful escape notification
					std::cout << "\n  You have successfully escaped." << std::endl;

					// Set the health of all enemies to 0
					goblin1.setHealth(0);
					goblin2.setHealth(0);
					goblin3.setHealth(0);

					// Go to the location of 'END:' and play from there
					//   (exits the loop & ends the battle)
					goto END;
				}
				// Otherwise (If the random number is not 1 -- the 66% chance of failed retreat passes)...
				else {
					std::this_thread::sleep_for(std::chrono::milliseconds(200));  // Pause 0.2 sec

					// Output failed escape notification
					std::cout << "\n  Retreat failed." << std::endl;

					// If Goblin 1 is still alive
					if (goblin1.getHealth() > 0) {
						// Output free attack
						std::cout << "\n  Goblin 1 got in a free attack. [-10 HP]" << std::endl;

						// Subtract 10 health from the player
						player.setHealth(player.getHealth() - 10);
					}
					// If Goblin 2 is still alive
					if (goblin2.getHealth() > 0) {
						// Output free attack
						std::cout << "  Goblin 2 got in a free attack. [-10 HP]" << std::endl;

						// Subtract 10 health from the player
						player.setHealth(player.getHealth() - 10);
					}
					// If Goblin 3 is still alive
					if (goblin3.getHealth() > 0) {
						// Output free attack
						std::cout << "  Goblin 3 got in a free attack. [-10 HP]" << std::endl;

						// Subtract 10 health from the player
						player.setHealth(player.getHealth() - 10);
					}
					// Set option to true
					//   (so that the player attack occurs next)
					option = true;
				}
			}
			// If option is true -- user chose "Attack" ('A'/'a') or failed to retreat
			if (option == true) {
				std::this_thread::sleep_for(std::chrono::milliseconds(350));  // Pause 0.35 sec

				// Set the player's lost hp to 0 (to reset upon loop repeat)
				hpLost = 0;

				// Random Player Damage between: 1/2 Base Atk Damage - Full Base Atk Damage
				attack = ((player.getDamage() / 2) + (rand() % (player.getDamage() - (player.getDamage() / 2) + 1)));
				// Random Enemy Damage between: 1/2 Base Atk Damage - Full Base Atk Damage
				mobAttack1 = ((goblin1.getDamage() / 2) + (rand() % (goblin1.getDamage() - (goblin1.getDamage() / 2) + 1)));
				mobAttack2 = ((goblin2.getDamage() / 2) + (rand() % (goblin2.getDamage() - (goblin2.getDamage() / 2) + 1)));
				mobAttack3 = ((goblin3.getDamage() / 2) + (rand() % (goblin3.getDamage() - (goblin3.getDamage() / 2) + 1)));

				// Modify Player attack to subtract 1/2 DEF Stat Value Multiplied by Level (Higher Defense & Higher Level = Less Damage Taken)
				fAttack = attack - ((goblin2.getLevel() * goblin2.getDEF()) / 2);
				// Modify Enemy attack to subtract 1/2 True DEF Stat Value Multiplied by Level (Higher Defense & Higher Level = Less Damage Taken)
				fMobAttack1 = mobAttack1 - ((player.getLevel() * (player.getDEF() + player.getDEFBoost())) / 2);
				fMobAttack2 = mobAttack2 - ((player.getLevel() * (player.getDEF() + player.getDEFBoost())) / 2);
				fMobAttack3 = mobAttack3 - ((player.getLevel() * (player.getDEF() + player.getDEFBoost())) / 2);

				// If any attack damages are less than zero
				// Set them to zero (there can't be negative damage)
				if (fAttack < 0) {
					fAttack = 0;
				}
				if (fMobAttack1 < 0) {
					fMobAttack1 = 0;
				}
				if (fMobAttack2 < 0) {
					fMobAttack2 = 0;
				}
				if (fMobAttack3 < 0) {
					fMobAttack3 = 0;
				}

				// Set the player's dodge rate to double variable 'dodgeRate'
				//   (for dodge rate percentage calculations)
				dodgeRate = player.getDodgeRate();

				// Subtract Goblin 2's health by the player's attack damage
				goblin2.setHealth(goblin2.getHealth() - fAttack);

				// Output attack notification
				std::cout << "\n  You attack Goblin 2 for " << fAttack << " damage!" << std::endl;

				std::this_thread::sleep_for(std::chrono::milliseconds(200));  // Pause 0.2 sec

				// If Goblin 2 is alive
				if (goblin2.getHealth() > 0) {
					// Output that Goblin 2 is beginning a counter attack
					std::cout << "\n  [Goblin 2 begins their counter attack.]" << std::endl;

					// Set integer variable 'agilityModifier' to 0 (to reset upon loop repeat)
					agilityModifier = 0;

					// Set integer variable 'randomDodge' to a random number of 1-100
					//   (for matching usage to determine player's dodge percentage)
					randomDodge = (1 + (rand() % ((100 - 1) + 1)));

					// Set boolean 'fullDodge' to false (to reset upon loop repeat)
					//   (this is used to break out of the loop
					//    if the first dodge check is a success)
					fullDodge = false;

					// 'numIncrease' & 'numIncrease2' are used as the two values
					// for the range of the dodge rate checker, used with 'randomDodge'

					// Set integer 'numIncrease' to 1
					numIncrease = 1;
					// Set integer 'numIncrease2' to the player's dodge rate times 100
					//   (decimal of 0.01-1 to a whole # of 1-100)
					numIncrease2 = (int)(dodgeRate * 100);

					// FIRST DODGE CHECK:
					// If the dodge check is a success
					//   (randomized num of 1-100 is within the
					//    starting range of the dodge rate checker)
					if (randomDodge > numIncrease && randomDodge <= numIncrease2) {
						// Set boolean 'fullDodge' to true
						fullDodge = true;
					}
					// Otherwise...
					else {
						// Increase the range of the
						// dodge rate checker up one notch
						numIncrease = numIncrease2;
						numIncrease2 = numIncrease2 + 20;
					}

					// Loop five times (after 5 times, dodge rate is guaranteed 0%)
					for (unsigned i = 0;i < 5;++i) {
						// If 'fullDodge' is true (if first check above succeeded)
						if (fullDodge == true) {
							// Break out of the loop
							break;
						}

						// If the modifier is between 0 and 1 (but not actually 1)
						if (agilityModifier < 1 && agilityModifier >= 0) {
							// Increase the modifier by 0.25 (25% less damage avoided)
							agilityModifier = agilityModifier + 0.25;  // Dodges: 100% - 75% - 50% - 25% - 0%
						}
						// If the modifier is equal to 1 (0% damage avoided)
						if (agilityModifier == 1.0) {
							// Break out of the loop
							break;
						}

						// If 'numIncrease' or 'numIncrease2' reaches 100
						//   (the loop ran through all checks to 100%)
						if (numIncrease > 100 || numIncrease2 > 100) {
							// Break out of the loop
							break;
						}
						// NEXT DODGE CHECK:
						// If the dodge check is a success
						//   (randomized num of 1-100 is within the
						//    increased range of the dodge rate checker)
						if (randomDodge > numIncrease && randomDodge <= numIncrease2) {
							// Break out of the loop
							break;
						}

						// Increase the two values of the range of the dodge rate checker
						numIncrease = numIncrease + 20;
						numIncrease2 = numIncrease2 + 20;
					}

					// If the modifier is equal to 0 -- 100% damage avoided (0 x dmg = no dmg taken)
					if (agilityModifier == 0.0) {
						// Output that the player avoided 100% of Goblin 2's damage
						std::cout << "\n  You avoided Goblin 2's attack [" << fMobAttack2 << " DMG] with your agility!" << std::endl;
					}  // OR
					// If the modifier is equal to 1 -- 0% damage avoided (1 x dmg = full dmg taken)
					else if (agilityModifier == 1.0) {
						// Subtract 100% of Goblin 2's attack from the player's health
						player.setHealth(player.getHealth() - fMobAttack2);

						// Output that the player took 100% of Goblin 2's attack
						std::cout << "\n  Goblin 2 counter attacks for " << fMobAttack2 << " damage!" << std::endl;

						// Add the damage the player received to variable 'hpLost'
						//   (for output after the round ends)
						hpLost = (hpLost + fMobAttack2);
					}
					// Otherwise (If the modifier is more than 0 and less than 1 -- 0.25, 0.5, 0.75)...
					else {
						// Subtract Goblin 2's attack (minus the avoided damage) from the player's health
						//   - atk x 0.25 = 75% dmg avoided (Player gets damaged 25% of the enemy's dmg)
						//   - atk x 0.50 = 50% dmg avoided (Player gets damaged 50% of the enemy's dmg)
						//   - atk x 0.75 = 25% dmg avoided (Player gets damaged 75% of the enemy's dmg)
						player.setHealth(player.getHealth() - (fMobAttack2 * agilityModifier));

						// Output the % of damage the player negated and how much damage the player took
						std::cout << "\n  You have negated " << ((1 - agilityModifier) * 100) << "% of Goblin 2's attack damage [" << fMobAttack2 << " DMG] " <<
							"by maneuvering with your agility! You only take " << (fMobAttack2 * agilityModifier) << " damage!" << std::endl;

						// Add the damage the player received to variable 'hpLost'
						//   (for output after the round ends)
						hpLost = (hpLost + (fMobAttack2 * agilityModifier));
					}
				}

				// Otherwise (If Goblin 2 is dead)...
				else {
					// Output that Goblin 2 has perished & how much experience the player gets
					std::cout << "\n  [Goblin 2 has perished.]\n  [EXP+" << goblin2.getEXP() << "]" << std::endl;
				}

				// If Goblin 1 is alive
				if (goblin1.getHealth() > 0) {
					// Output that the other goblins are beginning their attacks
					std::cout << "\n\n  [The other goblins begin their attacks.]" << std::endl;

					// Set integer variable 'agilityModifier' to 0 (to reset upon loop repeat)
					agilityModifier = 0;

					// Set integer variable 'randomDodge' to a random number of 1-100
					//   (for matching usage to determine player's dodge percentage)
					randomDodge = (1 + (rand() % ((100 - 1) + 1)));

					// Set boolean 'fullDodge' to false (to reset upon loop repeat)
					//   (this is used to break out of the loop
					//    if the first dodge check is a success)
					fullDodge = false;

					// 'numIncrease' & 'numIncrease2' are used as the two values
					// for the range of the dodge rate checker, used with 'randomDodge'

					// Set integer 'numIncrease' to 1
					numIncrease = 1;
					// Set integer 'numIncrease2' to the player's dodge rate times 100
					//   (decimal of 0.01-1 to a whole # of 1-100)
					numIncrease2 = (int)(dodgeRate * 100);

					// FIRST DODGE CHECK:
					// If the dodge check is a success
					//   (randomized num of 1-100 is within the
					//    starting range of the dodge rate checker)
					if (randomDodge > numIncrease && randomDodge <= numIncrease2) {
						// Set boolean 'fullDodge' to true
						fullDodge = true;
					}
					// Otherwise...
					else {
						// Increase the range of the
						// dodge rate checker up one notch
						numIncrease = numIncrease2;
						numIncrease2 = numIncrease2 + 20;
					}

					// Loop five times (after 5 times, dodge rate is guaranteed 0%)
					for (unsigned i = 0;i < 5;++i) {
						// If 'fullDodge' is true (if first check above succeeded)
						if (fullDodge == true) {
							// Break out of the loop
							break;
						}

						// If the modifier is between 0 and 1 (but not actually 1)
						if (agilityModifier < 1 && agilityModifier >= 0) {
							// Increase the modifier by 0.25 (25% less damage avoided)
							agilityModifier = agilityModifier + 0.25;  // Dodges: 100% - 75% - 50% - 25% - 0%
						}
						// If the modifier is equal to 1 (0% damage avoided)
						if (agilityModifier == 1.0) {
							// Break out of the loop
							break;
						}

						// If 'numIncrease' or 'numIncrease2' reaches 100
						//   (the loop ran through all checks to 100%)
						if (numIncrease > 100 || numIncrease2 > 100) {
							// Break out of the loop
							break;
						}
						// NEXT DODGE CHECK:
						// If the dodge check is a success
						//   (randomized num of 1-100 is within the
						//    increased range of the dodge ratte checker)
						if (randomDodge > numIncrease && randomDodge <= numIncrease2) {
							// Break out of the loop
							break;
						}

						// Increase the two values of the range of the dodge rate checker
						numIncrease = numIncrease + 20;
						numIncrease2 = numIncrease2 + 20;
					}

					// If the modifier is equal to 0 -- 100% damage avoided (0 x dmg = no dmg taken)
					if (agilityModifier == 0.0) {
						// Output that the player avoided 100% of Goblin 1's damage
						std::cout << "\n  You avoided Goblin 1's attack [" << fMobAttack1 << " DMG] with your agility!" << std::endl;
					}  // OR
					// If the modifier is equal to 1 -- 0% damage avoided (1 x dmg = full dmg taken)
					else if (agilityModifier == 1.0) {
						// Subtract 100% of Goblin 1's attack the player's health
						player.setHealth(player.getHealth() - fMobAttack1);

						// Output that the player took 100% of Goblin 1's attack
						std::cout << "\n  Goblin 1 attacks you for " << fMobAttack1 << " damage!" << std::endl;

						// Add the damage the player received to variable 'hpLost'
						//   (for output after the round ends)
						hpLost = (hpLost + fMobAttack1);
					}
					// Otherwise (If the modifier is more than 0 and less than 1 -- 0.25, 0.5, 0.75)...
					else {
						// Subtract Goblin 1's attack (minus the avoided damage) from the player's health
						//   - atk x 0.25 = 75% dmg avoided (Player gets damaged 25% of the enemy's dmg)
						//   - atk x 0.50 = 50% dmg avoided (Player gets damaged 50% of the enemy's dmg)
						//   - atk x 0.75 = 25% dmg avoided (Player gets damaged 75% of the enemy's dmg)
						player.setHealth(player.getHealth() - (fMobAttack1 * agilityModifier));

						// Output the % of damage the player negated and how much damage the player took
						std::cout << "\n  You have negated " << ((1 - agilityModifier) * 100) << "% of Goblin 1's attack damage [" << fMobAttack1 << " DMG] " <<
							"by maneuvering with your agility! You only take " << (fMobAttack1 * agilityModifier) << " damage!" << std::endl;

						// Add the damage the player received to variable 'hpLost'
						//   (for output after the round ends)
						hpLost = (hpLost + (fMobAttack1 * agilityModifier));
					}
				}

				// Otherwise (If Goblin 1 is dead)...
				else {
					// Output that Goblin 1 has perished & how much experience the player gets
					std::cout << "\n  [Goblin 1 has perished.]\n  [EXP+" << goblin1.getEXP() << "]" << std::endl;
				}

				// If Goblin 3 is alive
				if (goblin3.getHealth() > 0) {
					// Set integer variable 'agilityModifer' to 0 (to reset upon loop repeat)
					agilityModifier = 0;

					// Set integer variable 'randomDodge' to a random number of 1-100
					//   (for matching usage to determine player's dodge percentage)
					randomDodge = (1 + (rand() % ((100 - 1) + 1)));

					// Set boolean 'fullDodge' to false (to reset upon loop repeat)
					//   (this is used to break out of the loop
					//    if the first dodge check is a success)
					fullDodge = false;

					// 'numIncrease' & 'numIncrease2' are used as the two values
					// for the range of the dodge rate checker, used with 'randomDodge'

					// Set integer 'numIncrease' to 1
					numIncrease = 1;
					// Set integer 'numIncrease2' to the player's dodge rate times 100
					//   (decimal of 0.1-1 to a whole # of 1-100)
					numIncrease2 = (int)(dodgeRate * 100);

					// FIRST DODGE CHECK:
					// If the dodge check is a success
					//   (randomized num of 1-100 is within the
					//    starting range of the dodge rate checker)
					if (randomDodge > numIncrease && randomDodge <= numIncrease2) {
						// Set boolean 'fullDodge' to true
						fullDodge = true;
					}
					// Otherwise...
					else {
						// Increase the range of the
						// dodge rate checker up one notch
						numIncrease = numIncrease2;
						numIncrease2 = numIncrease2 + 20;
					}

					// Loop five times (after 5 times, dodge rate is guaranteed 0%)
					for (unsigned i = 0;i < 5;++i) {
						// If 'fullDodge' is true (if first check above succeeded)
						if (fullDodge == true) {
							// Break out of the loop
							break;
						}

						// If the modifier is between 0 and 1 (but not actually 1)
						if (agilityModifier < 1 && agilityModifier >= 0) {
							// Increase the modifier by 0.25 (25% less damage avoided)
							agilityModifier = agilityModifier + 0.25;  // Dodges: 100% - 75% - 50% - 25% - 0%
						}
						// If the modifier is equal to 1 (0% damage avoided)
						if (agilityModifier == 1.0) {
							// Break out of the loop
							break;
						}

						// If 'numIncrease' or 'numIncrease2' reaches 100
						//   (the loop ran through all checks to 100%)
						if (numIncrease > 100 || numIncrease2 > 100) {
							// Break out of the loop
							break;
						}
						// NEXT DODGE CHECK:
						// If the dodge check is a success
						//   (randomized num of 1-100 is within the
						//    increased range of the dodge rate checker)
						if (randomDodge > numIncrease && randomDodge <= numIncrease2) {
							// Break out of the loop
							break;
						}

						// Increase the two values of the range of the dodge rate checker
						numIncrease = numIncrease + 20;
						numIncrease2 = numIncrease2 + 20;
					}

					// If the modifier is equal to 0 -- 100% damage avoided (0 x dmg = no dmg taken)
					if (agilityModifier == 0.0) {
						// Output that the player avoided 100% of Goblin 3's damage
						std::cout << "\n  You avoided Goblin 3's attack [" << fMobAttack3 << " DMG] with your agility!" << std::endl;
					}  // OR
					// If the modifier is equal to 1 -- 0% damage avoided (1 x dmg = full dmg taken)
					else if (agilityModifier == 1.0) {
						// Subtract 100% of Goblin 3's attack from the player's health
						player.setHealth(player.getHealth() - fMobAttack3);

						// Output that the player took 100% of Goblin 3's attack
						std::cout << "\n  Goblin 3 attacks you for " << fMobAttack3 << " damage!" << std::endl;

						// Add the damage the player received to variable 'hpLost'
						//   (for output after the round ends)
						hpLost = (hpLost + fMobAttack3);
					}
					// Otherwise (If the modifier is more than 0 and less than 1 -- 0.25, 0.5, 0.75)...
					else {
						// Subtract Goblin 3's attack (minus the avoided damage) from the player's health
						//   - atk x 0.25 = 75% dmg avoided (Player gets damaged 25% of the enemy's dmg)
						//   - atk x 0.50 = 50% dmg avoided (Player gets damaged 50% of the enemy's dmg)
						//   - atk x 0.75 = 25% dmg avoided (Player gets damaged 75% of the enemy's dmg)
						player.setHealth(player.getHealth() - (fMobAttack3 * agilityModifier));

						// Output the % of damage the player negated and how much damage the player took
						std::cout << "\n  You have negated " << ((1 - agilityModifier) * 100) << "% of Goblin 3's attack damage [" << fMobAttack3 << " DMG] " <<
							"by maneuvering with your agility! You only take " << (fMobAttack3 * agilityModifier) << " damage!" << std::endl;

						// Add the damage the player received to variable 'hpLost'
						//   (for output after the round ends)
						hpLost = (hpLost + (fMobAttack3 * agilityModifier));
					}
				}

				// Otherwise (for output after the round ends)...
				else {
					// Output that Goblin 3 has perished & how much experience the player gets
					std::cout << "\n  [Goblin 3 has perished.]\n  [EXP+" << goblin3.getEXP() << "]" << std::endl;
				}

				// Output the amount of health lost after the round
				std::cout << "\n\n  [-" << hpLost << " HP]" << std::endl;

				std::this_thread::sleep_for(std::chrono::milliseconds(350));  // Pause 0.35 sec
			}
		} while (goblin2.getHealth() > 0 && player.getHealth() > 0);
		// Keep repeating the block of code until Goblin 2 or the player dies

		// If any of the Enemys' health has dropped below zero,
		// set their health to 0 (you can't have negative health)
		if (goblin1.getHealth() < 0) {
			goblin1.setHealth(0);
		}
		if (goblin2.getHealth() < 0) {
			goblin2.setHealth(0);
		}
		if (goblin3.getHealth() < 0) {
			goblin3.setHealth(0);
		}

		// If the player has died
		if (player.getHealth() <= 0) {
			// Run the Death() method
			Death();
			// Terminate the program
			exit(0);
		}

		// Output the health status of player & all enemies
		std::cout << "\n\n  ###############################\n  HP:       (" << player.getHealth() << "/" << player.getMaxHealth() << ")\n  " <<
			"Goblin 1: (" << goblin1.getHealth() << "/" << goblin1.getMaxHealth() << ")\n  " <<
			"Goblin 2: (" << goblin2.getHealth() << "/" << goblin2.getMaxHealth() << ")\n  " <<
			"Goblin 3: (" << goblin3.getHealth() << "/" << goblin3.getMaxHealth() << ")\n  " <<
			"###############################" << std::endl;

		// Update the Character object 'player' by calculating
		// the updated experience from Goblin 2's death
		player = CalculateEXP(player, goblin2);

		// Ask the player which Goblin to target next
		std::cout << "\n\n  Don't celebrate too soon! The battle still goes on!!\n  Which enemy will you target next?" << std::endl;
		std::cout << "\tA) Goblin 1 (" << goblin1.getHealth() << "/" << goblin1.getMaxHealth() << ")" << std::endl;
		std::cout << "\tB) Goblin 3 (" << goblin3.getHealth() << "/" << goblin3.getMaxHealth() << ")" << std::endl;
		// Get user input
		optionChar = choiceABC("AB");

		// If user chose Goblin 1 ('A'/'a')
		// ATTACK GOBLIN 1 -- GOBLIN 3 STILL ALIVE
		if (optionChar == 'A') {
			// Block of code to loop while Goblin 1 is still alive
			do {
				// Output health status of player & all enemies
				std::cout << "\n\n  ###############################\n  HP:       (" << player.getHealth() << "/" << player.getMaxHealth() << ")\n  " <<
					"Goblin 1: (" << goblin1.getHealth() << "/" << goblin1.getMaxHealth() << ")\n  " <<
					"Goblin 2: (" << goblin2.getHealth() << "/" << goblin2.getMaxHealth() << ")\n  " <<
					"Goblin 3: (" << goblin3.getHealth() << "/" << goblin3.getMaxHealth() << ")\n  " <<
					"###############################" << std::endl;

				std::this_thread::sleep_for(std::chrono::milliseconds(200));  // Pause 0.2 sec

				// Ask the player to either Attack or Retreat
				std::cout << "\n  Attack or Retreat? ";
				// Get user input
				option = choiceYesNo("Attack", "Retreat");

				clear();  // Clear console window

				// If option is false -- user chose "Retreat" ('R'/'r')
				if (option == false) {
					// If a random number of 1-3 is 1 (33% chance)
					if ((rand() % 3) == 1) {
						// Output successful escape notification
						std::cout << "\n  You have successfully escaped." << std::endl;

						// Set the health of all remaining enemies to 0
						goblin1.setHealth(0);
						goblin3.setHealth(0);

						// Go to the location of 'END:' and player from there
						//   (exits the loop & ends the battle)
						goto END;
					}
					// Otherwise (If the random number is not 1 -- the 66% chance of failed retreat passes)...
					else {
						std::this_thread::sleep_for(std::chrono::milliseconds(200));  // Pause 0.2 sec

						// Output failed escape notification
						std::cout << "\n  Retreat failed." << std::endl;

						// If Goblin 1 is still alive
						if (goblin1.getHealth() > 0) {
							// Output free attack
							std::cout << "\n  Goblin 1 got in a free attack. [-10 HP]" << std::endl;

							// Subtract 10 health from the player
							player.setHealth(player.getHealth() - 10);
						}
						// If Goblin 3 is still alive
						if (goblin3.getHealth() > 0) {
							// Output free attack
							std::cout << "  Goblin 3 got in a free attack. [-10 HP]" << std::endl;

							// Subtract 10 health from the player
							player.setHealth(player.getHealth() - 10);
						}
						// Set option to true
						//   (so that the player attack occurs next)
						option = true;
					}
				}
				// If option is true -- user chose "Attack" ('A'/'a') or failed to retreat
				if (option == true) {
					std::this_thread::sleep_for(std::chrono::milliseconds(350));  // Pause 0.35 sec

					// Set the player's lost hp to 0 (to reset upon loop repeat)
					hpLost = 0;

					// Random Player Damage between: 1/2 Base Atk Damage - Full Base Atk Damage
					attack = ((player.getDamage() / 2) + (rand() % (player.getDamage() - (player.getDamage() / 2) + 1)));
					// Random Enemy Damage between: 1/2 Base Atk Damage - Full Base Atk Damage
					mobAttack1 = ((goblin1.getDamage() / 2) + (rand() % (goblin1.getDamage() - (goblin1.getDamage() / 2) + 1)));
					mobAttack3 = ((goblin3.getDamage() / 2) + (rand() % (goblin3.getDamage() - (goblin3.getDamage() / 2) + 1)));

					// Modify Player attack to subtract 1/2 DEF Stat Value Multiplied by Level (Higher Defense & Higher Level = Less Damage Taken)
					fAttack = attack - ((goblin1.getLevel() * goblin1.getDEF()) / 2);
					// Modify Enemy attack to subtract 1/2 True DEF Stat Value Multiplied by Level (Higher Defense & Higher Level = Less Damage Taken)
					fMobAttack1 = mobAttack1 - ((player.getLevel() * (player.getDEF() + player.getDEFBoost())) / 2);
					fMobAttack3 = mobAttack3 - ((player.getLevel() * (player.getDEF() + player.getDEFBoost())) / 2);

					// If any attack damages are less than zero
					// Set them to zero (there can't be negative damage)
					if (fAttack < 0) {
						fAttack = 0;
					}
					if (fMobAttack1 < 0) {
						fMobAttack1 = 0;
					}
					if (fMobAttack3 < 0) {
						fMobAttack3 = 0;
					}

					// Set the player's dodge rate to double variable 'dodgeRate'
					//   (for dodge rate percentage calculations)
					dodgeRate = player.getDodgeRate();

					// Subtract Goblin 1's health by the player's attack damage
					goblin1.setHealth(goblin1.getHealth() - fAttack);

					std::cout << "\n  You attack Goblin 1 for " << fAttack << " damage!" << std::endl;

					std::this_thread::sleep_for(std::chrono::milliseconds(200));  // Pause 0.2 sec

					// If Goblin 1 is alive
					if (goblin1.getHealth() > 0) {
						// Output that Goblin 1 is beginning a counter attack
						std::cout << "\n  [Goblin 1 begins their counter attack.]" << std::endl;

						// Set integer variable 'agilityModifier' to 0 (to reset upon loop repeat)
						agilityModifier = 0;

						// Set integer variable 'randomDodge' to a random number of 1-100
						//   (for matching usage to determine player's dodge percentage)
						randomDodge = (1 + (rand() % ((100 - 1) + 1)));

						// Set boolean 'fullDodge' to false (to reset upon loop repeat)
						//   (this is used to break out of the loop
						//    if the first dodge check is a success)
						fullDodge = false;

						// 'numIncrease' & 'numIncrease2' are used as the two values
						// for the range of the dodge rate checker, used with 'randomDodge'

						// Set integer 'numIncrease' to 1
						numIncrease = 1;
						// Set integer 'numIncrease2' to the player's dodge rate times 100
						//   (decimal of 0.01-1 to a whole # of 1-100)
						numIncrease2 = (int)(dodgeRate * 100);

						// FIRST DODGE CHECK:
						// If the random dodge check is a success
						//   (randomized num of 1-100 is within the
						//    starting range of the dodge rate checker)
						if (randomDodge > numIncrease && randomDodge <= numIncrease2) {
							// Set boolean 'fullDodge' to true
							fullDodge = true;
						}
						// Otherwise...
						else {
							// Increase the range of the
							// dodge rate checker up one notch
							numIncrease = numIncrease2;
							numIncrease2 = numIncrease2 + 20;
						}

						// Loop five times (after 5 times, dodge rate is guaranteed 0%)
						for (unsigned i = 0;i < 5;++i) {
							// If 'fullDodge' is true (if first check above succeeded)
							if (fullDodge == true) {
								// Break out of the loop
								break;
							}

							// If the modifier is between 0 and 1 (but not actually 1)
							if (agilityModifier < 1 && agilityModifier >= 0) {
								// Increase the modifier by 0.25 (25% less damage avoided)
								agilityModifier = agilityModifier + 0.25;  // Dodges: 100% - 75% - 50% - 25% - 0%
							}
							// If the modifier is equal to 1 (0% damage avoided)
							if (agilityModifier == 1.0) {
								// Break out of the loop
								break;
							}

							// If 'numIncrease' or 'numIncrease2' reaches 100
							//   (the loop ran through all checks to 100%)
							if (numIncrease > 100 || numIncrease2 > 100) {
								// Break out of the loop
								break;
							}
							// NEXT DODGE CHECK:
							// If the dodge check is a success
							//   (randomized num of 1-100 is within the
							//    increased range of the dodge rate checker)
							if (randomDodge > numIncrease && randomDodge <= numIncrease2) {
								// Break out of the loop
								break;
							}

							// Increase the two values of the range of the dodge rate checker
							numIncrease = numIncrease + 20;
							numIncrease2 = numIncrease2 + 20;
						}

						// If the modifier is equal to 0 -- 100% damage avoided (0 x dmg = no dmg taken)
						if (agilityModifier == 0.0) {
							// Output that the player avoided 100% of Goblin 1's damage
							std::cout << "\n  You avoided Goblin 1's attack [" << fMobAttack1 << " DMG] with your agility!" << std::endl;
						}  // OR
						// If the modifier is equal to 1 -- 0% damage avoided (1 x dmg = full dmg taken)
						else if (agilityModifier == 1.0) {
							// Subtract 100% of Goblin 1's attack from the player's health
							player.setHealth(player.getHealth() - fMobAttack1);

							// Output that the player took 100% of Goblin 1's attack
							std::cout << "\n  Goblin 1 counter attacks for " << fMobAttack1 << " damage!" << std::endl;

							// Add the damage the player received to variable 'hpLost'
							//   (for output after the round ends)
							hpLost = (hpLost + fMobAttack1);
						}
						// Otherwise (If the modifier is more than 0 and less than 1 -- 0.25, 0.5, 0.75)...
						else {
							// Subtract Goblin 1's attack (minus the avoided damage) from the player's health
							//   - atk x 0.25 = 75% dmg avoided (Player gets damaged 25% of the enemy's dmg)
							//   - atk x 0.50 = 50% dmg avoided (Player gets damaged 50% of the enemy's dmg)
							//   - atk x 0.75 = 25% dmg avoided (Player gets damaged 75% of the enemy's dmg)
							player.setHealth(player.getHealth() - (fMobAttack1 * agilityModifier));

							// Output the % of damage the player negated and how much damage the player took
							std::cout << "\n  You have negated " << ((1 - agilityModifier) * 100) << "% of Goblin 1's attack damage [" << fMobAttack1 << " DMG] " <<
								"by maneuvering with your agility! You only take " << (fMobAttack1 * agilityModifier) << " damage!" << std::endl;

							// Add the damage the player received to variable 'hpLost'
							//   (for output after the round ends)
							hpLost = (hpLost + (fMobAttack1 * agilityModifier));
						}
					}

					// Otherwise (If Goblin 1 is dead)...
					else {
						// Output that Goblin 1 has perished & how much experience the player gets
						std::cout << "\n  [Goblin 1 has perished.]\n  [EXP+" << goblin1.getEXP() << "]" << std::endl;
					}

					// If Goblin 3 is alive
					if (goblin3.getHealth() > 0) {
						// Output that the other goblin is beginning their attack
						std::cout << "\n\n  [The other goblin begins their attack.]" << std::endl;

						// Set integer variable 'agilityModifier' to 0 (to reset upon loop repeat)
						agilityModifier = 0;

						// Set integer variable 'randomDodge' to a random number of 1-100
						//   (for matching usage to determine player's dodge percentage)
						randomDodge = (1 + (rand() % ((100 - 1) + 1)));

						// Set boolean 'fullDodge' to false (to reset upon loop repeat)
						//   (this is used to break out of the loop
						//    if the first dodge check is a success)
						fullDodge = false;

						// 'numIncrease' & 'numIncrease2' are used as the two values
						// for the range of the dodge rate checker, used with 'randomDodge'

						// Set integer 'numIncrease' to 1
						numIncrease = 1;
						// Set integer 'numIncrease2' to the player's dodge rate times 100
						//   (decimal of 0.01-1 to a whole # of 1-100)
						numIncrease2 = (int)(dodgeRate * 100);

						// FIRST DODGE CHECK:
						// If the dodge check is a success
						//   (randomized num of 1-100 is within the
						//    starting range of the dodge rate checker)
						if (randomDodge > numIncrease && randomDodge <= numIncrease2) {
							// Set boolean 'fullDodge' to true
							fullDodge = true;
						}
						// Otherwise...
						else {
							// Increase the range of the
							// dodge rate checker up one notch
							numIncrease = numIncrease2;
							numIncrease2 = numIncrease2 + 20;
						}

						// Loop five times (after 5 times, dodge rate is guaranteed 0%)
						for (unsigned i = 0;i < 5;++i) {
							// If 'fullDodge' is true (if first check above succeeded)
							if (fullDodge == true) {
								// Break out of the loop
								break;
							}

							// If the modifier is between 0 and 1 (but not actually 1)
							if (agilityModifier < 1 && agilityModifier >= 0) {
								// Increase the modifier by 0.25 (25% less damage avoided)
								agilityModifier = agilityModifier + 0.25;  // Dodges: 100% - 75% - 50% - 25% - 0%
							}
							// If the modifier is equal to 1 (0% damage avoided)
							if (agilityModifier == 1.0) {
								// Break out of the loop
								break;
							}

							// If 'numIncrease' or 'numIncrease2' reaches 100
							//   (the loop ran through all checks to 100%)
							if (numIncrease > 100 || numIncrease2 > 100) {
								// Break out of the loop
								break;
							}
							// NEXT DODGE CHECK:
							// If the dodge check is a success
							//   (randomized num of 1-100 is within the
							//    increased range of the dodge rate checker)
							if (randomDodge > numIncrease && randomDodge <= numIncrease2) {
								// Break out of the loop
								break;
							}

							// Increase the two values of the range of the dodge rate checker
							numIncrease = numIncrease + 20;
							numIncrease2 = numIncrease2 + 20;
						}

						// If the modifier is equal to 0 -- 100% damage avoided (0 x dmg = no dmg taken)
						if (agilityModifier == 0.0) {
							// Output that the player avoided 100% of Goblin 3's damage
							std::cout << "\n  You avoided Goblin 3's attack [" << fMobAttack3 << " DMG] with your agility!" << std::endl;
						}  // OR
						// If the modifier is equal to 1 -- 0% damage avoided (1 x dmg = full dmg taken)
						else if (agilityModifier == 1.0) {
							// Subtract 100% of Goblin 3's attack from the player's health
							player.setHealth(player.getHealth() - fMobAttack3);

							// Output that the player took 100% of Goblin 3's attack
							std::cout << "\n  Goblin 3 attacks you for " << fMobAttack3 << " damage!" << std::endl;

							// Add the damage the player received to variable 'hpLost'
							//   (for output after the round ends)
							hpLost = (hpLost + fMobAttack3);
						}
						// Otherwise (If the modifier is more than 0 and less than 1 -- 0.25, 0.5, 0.75)...
						else {
							// Subtract Goblin 3's attack (minus the avoided damage) from the player's health
							//   - atk x 0.25 = 75% dmg avoided (Player gets damaged 25% of the enemy's dmg)
							//   - atk x 0.5  = 50% dmg avoided (Player gets damaged 50% of the enemy's dmg)
							//   - atk x 0.75 = 25% dmg avoided (Player gets damaged 75% of the enemy's dmg)
							player.setHealth(player.getHealth() - (fMobAttack3 * agilityModifier));

							// Output the % of damage the player negated and how much damage the player took
							std::cout << "\n  You have negated " << ((1 - agilityModifier) * 100) << "% of Goblin 3's attack damage [" << fMobAttack3 << " DMG] " <<
								"by maneuvering with your agility! You only take " << (fMobAttack3 * agilityModifier) << " damage!" << std::endl;

							// Add the damage the player received to variable 'hpLost'
							//   (for output after the round ends)
							hpLost = (hpLost + (fMobAttack3 * agilityModifier));
						}
					}

					// Otherwise (If Goblin 3 is dead)...
					else {
						// Output that Goblin 3 has perished & how much experience the player gets
						std::cout << "\n  [Goblin 3 has perished.]\n  [EXP+" << goblin3.getEXP() << "]" << std::endl;
					}

					// Output the amount of health lost after the round
					std::cout << "\n\n  [-" << hpLost << " HP]" << std::endl;

					std::this_thread::sleep_for(std::chrono::milliseconds(350));  // Pause 0.35 sec
				}
			} while (goblin1.getHealth() > 0 && player.getHealth() > 0);
			// Keep repeating the block of code until Goblin 1 or the player dies

			// If any of the Enemys' health has dropped below zero,
			// set their health to 0 (you can't have negative health)
			if (goblin1.getHealth() < 0) {
				goblin1.setHealth(0);
			}
			if (goblin3.getHealth() < 0) {
				goblin3.setHealth(0);
			}

			// If the player has died
			if (player.getHealth() <= 0) {
				// Run the Death() method
				Death();
				// Terminate the program
				exit(0);
			}

			// Output the health status of player & all enemies
			std::cout << "\n\n  ###############################\n  HP:       (" << player.getHealth() << "/" << player.getMaxHealth() << ")\n  " <<
				"Goblin 1: (" << goblin1.getHealth() << "/" << goblin1.getMaxHealth() << ")\n  " <<
				"Goblin 2: (" << goblin2.getHealth() << "/" << goblin2.getMaxHealth() << ")\n  " <<
				"Goblin 3: (" << goblin3.getHealth() << "/" << goblin3.getMaxHealth() << ")\n  " <<
				"###############################" << std::endl;

			// Update the Character object 'player' by calculating
			// the updated experience from Goblin 1's death
			player = CalculateEXP(player, goblin1);

			// Output to the player that there is only one enemy remaining
			std::cout << "\n\n  There is only one goblin remaining. You're almost there!" << std::endl;

			/*  ===================================================================================  */
			/*  ================================                   ================================  */
			/*  ================================    LAST BATTLE    ================================  */
			/*  ================================                   ================================  */
			/*  ===================================================================================  */

			// ATTACK GOBLIN 3

			// Block of code to loop while Goblin 3 alive
			do {
				// Output health status of player & all enemies
				std::cout << "\n\n  ###############################\n  HP:       (" << player.getHealth() << "/" << player.getMaxHealth() << ")\n  " <<
					"Goblin 1: (" << goblin1.getHealth() << "/" << goblin1.getMaxHealth() << ")\n  " <<
					"Goblin 2: (" << goblin2.getHealth() << "/" << goblin2.getMaxHealth() << ")\n  " <<
					"Goblin 3: (" << goblin3.getHealth() << "/" << goblin3.getMaxHealth() << ")\n  " <<
					"###############################" << std::endl;

				std::this_thread::sleep_for(std::chrono::milliseconds(200));  // Pause 0.2 sec

				// Ask the player to either Attack or Retreat
				std::cout << "\n  Attack or Retreat? ";
				// Get user input
				option = choiceYesNo("Attack", "Retreat");

				clear();  // Clear console window

				// If option is false -- user chose "Retreat" ('R'/'r')
				if (option == false) {
					// If a random number of 1-3 is 1 (33% chance)
					if ((rand() % 3) == 1) {
						// Output successful escape notification
						std::cout << "\n  You have successfully escaped." << std::endl;

						// Set the health of the enemy to 0
						goblin3.setHealth(0);

						// Go to the location of 'END:' and play from there
						//   (exits the loop & ends the battle)
						goto END;
					}
					// Otherwise (If the random number is not 1 -- the 66% chance of failed retreat passes)...
					else {
						std::this_thread::sleep_for(std::chrono::milliseconds(200));  // Pause 0.2 sec

						// Output failed escape notification
						std::cout << "\n  Retreat failed." << std::endl;

						// If Goblin 3 is still alive
						if (goblin3.getHealth() > 0) {
							// Output free attack
							std::cout << "\n  Goblin 3 got in a free attack. [-10 HP]" << std::endl;

							// Subtract 10 health from the player
							player.setHealth(player.getHealth() - 10);
						}
						// Set option to true
						//   (so that the player attack occurs next)
						option = true;
					}
				}
				// If option is true -- user chose "Attack" ('A'/'a') or failed to retreat
				if (option == true) {
					std::this_thread::sleep_for(std::chrono::milliseconds(350));  // Pause 0.35 sec

					// Set the player's lost hp to 0 (to reset upon loop repeat)
					hpLost = 0;

					// Random Player Damage between: 1/2 Base Atk Damage - Full Base Atk Damage
					attack = ((player.getDamage() / 2) + (rand() % (player.getDamage() - (player.getDamage() / 2) + 1)));
					// Random Enemy Damage between: 1/2 Base Atk Damage - Full Base Atk Damage
					mobAttack3 = ((goblin3.getDamage() / 2) + (rand() % (goblin3.getDamage() - (goblin3.getDamage() / 2) + 1)));

					// Modify Player attack to subtract 1/2 DEF Stat Value Multiplied by Level (Higher Defense & Higher Level = Less Damage Taken)
					fAttack = attack - ((goblin3.getLevel() * goblin3.getDEF()) / 2);
					// Modify Player attack to subtract 1/2 True DEF Stat Value Multiplied by Level (Higher Defense & Higher Level = Less Damage Taken)
					fMobAttack3 = mobAttack3 - ((player.getLevel() * (player.getDEF() + player.getDEFBoost())) / 2);

					// If any attack damages are less than zero
					// Set them to zero (there can't be negative damage)
					if (fAttack < 0) {
						fAttack = 0;
					}
					if (fMobAttack3 < 0) {
						fMobAttack3 = 0;
					}

					// Set the player's dodge rate to double variable 'dodgeRate'
					//   (for dodge rate percentage calculations)
					dodgeRate = player.getDodgeRate();

					// Subtract Goblin 3's health by the player's attack damage
					goblin3.setHealth(goblin3.getHealth() - fAttack);

					// Output attack notification
					std::cout << "\n  You attack Goblin 3 for " << fAttack << " damage!" << std::endl;

					std::this_thread::sleep_for(std::chrono::milliseconds(200));  // Pause 0.2 sec

					// If Goblin 3 is alive
					if (goblin3.getHealth() > 0) {
						// Output that Goblin 3 is beginning a counter attack
						std::cout << "\n  [Goblin 3 begins their counter attack.]" << std::endl;

						// Set integer variable 'agilityModifier' to 0 (to reset upon loop repeat)
						agilityModifier = 0;

						// Set integer variable 'randomDodge' to a random number of 1-100
						//   (for matching usage to determine player's dodge percentage)
						randomDodge = (1 + (rand() % ((100 - 1) + 1)));

						// Set boolean 'fullDodge' to false (to reset upon loop repeat)
						//   (this is used to break out of the loop
						//    if the first dodge check is a success)
						fullDodge = false;

						// 'numIncrease' & 'numIncrease2' are used as the two values
						// for the range of the dodge rate checker, used with 'randomDodge'

						// Set integer 'numIncrease' to 1
						numIncrease = 1;
						// Set integer 'numIncrease2' to the player's dodge rate times 100
						//   (decimal of 0.1-1 to a whole # of 1-100)
						numIncrease2 = (int)(dodgeRate * 100);

						// FIRST DODGE CHECK:
						// If the dodge check is a success
						//   (randomized num of 1-100 is within the
						//    starting range of the dodge rate checker)
						if (randomDodge > numIncrease && randomDodge <= numIncrease2) {
							// Set boolean 'fullDodge' to true
							fullDodge = true;
						}
						// Otherwise...
						else {
							// Increase the range of the
							// dodge rate checker up one notch
							numIncrease = numIncrease2;
							numIncrease2 = numIncrease2 + 20;
						}

						// Loop five times (after 5 times, dodge rate is guaranteed 0%)
						for (unsigned i = 0;i < 5;++i) {
							// If 'fullDodge' is true (if first check above succeeded)
							if (fullDodge == true) {
								// Break out of the loop
								break;
							}

							// If the modifier is between 0 and 1 (but not actually 1)
							if (agilityModifier < 1 && agilityModifier >= 0) {
								// Increase the modifier by 0.25 (25% less damage avoided)
								agilityModifier = agilityModifier + 0.25;  // Dodges: 100% - 75% - 50% - 25% - 0%
							}
							// If the modifier is equal to 1 (0% damage avoided)
							if (agilityModifier == 1.0) {
								// Break out of the loop
								break;
							}

							// If 'numIncrease' or 'numIncrease2' reaches 100
							//   (the loop ran through all checks to 100%)
							if (numIncrease > 100 || numIncrease2 > 100) {
								// Break out of the loop
								break;
							}
							// NEXT DODGE CHECK:
							// If the dodge check is a success
							//   (randomized num of 1-100 is within the
							//    increased range of the dodge rate checker)
							if (randomDodge > numIncrease && randomDodge <= numIncrease2) {
								// Break out of the loop
								break;
							}

							// Increase the two values of the range of the dodge rate checker
							numIncrease = numIncrease + 20;
							numIncrease2 = numIncrease2 + 20;
						}

						// If the modifier is equal to 0 -- 100% damage avoided (0 x dmg = no dmg taken)
						if (agilityModifier == 0.0) {
							// Output that the player avoided 100% of Goblin 3's damage
							std::cout << "\n  You avoided Goblin 3's attack [" << fMobAttack3 << " DMG] with your agility!" << std::endl;
						}  // OR
						// If the modifier is equal to 1 -- 0% damage avoided (1 x dmg = full dmg taken)
						else if (agilityModifier == 1.0) {
							// Subtract 100% of Goblin 3's attack from the player's health
							player.setHealth(player.getHealth() - fMobAttack3);

							// Output that the player took 100% of Goblin 3's attack
							std::cout << "\n  Goblin 3 counter attacks for " << fMobAttack3 << " damage!" << std::endl;

							// Add the damage the player received to variable 'hpLost'
							//   (for output after the round endss)
							hpLost = (hpLost + fMobAttack3);
						}
						// Otherwise (If the modifier is more than 0 and less than 1 -- 0.25, 0.5, 0.75)...
						else {
							// Subtract Goblin 3's attack (minus the avoided damage) from the player's health
							//   - atk x 0.25 = 75% dmg avoided (Player gets damaged 25% of the enemy's dmg)
							//   - atk x 0.5  = 50% dmg avoided (Player gets damaged 50% of the enemy's dmg)
							//   - atk x 0.75 = 25% dmg avoided (Player gets damaged 75% of the enemy's dmg)
							player.setHealth(player.getHealth() - (fMobAttack3 * agilityModifier));

							// Output the % of damage the player negated and how much damage the player took
							std::cout << "\n  You have negated " << ((1 - agilityModifier) * 100) << "% of Goblin 3's attack damage [" << fMobAttack3 << " DMG] " <<
								"by maneuvering with your agility! You only take " << (fMobAttack3 * agilityModifier) << " damage!" << std::endl;

							// Add the damage the player received to variable 'hpLost'
							//   (for output after the round ends)
							hpLost = (hpLost + (fMobAttack3 * agilityModifier));
						}
					}

					// Otherwise (If Goblin 3 is dead)...
					else {
						// Output that Goblin 3 has perished & how much experience the player gets
						std::cout << "\n  [Goblin 3 has perished.]\n  [EXP+" << goblin3.getEXP() << "]" << std::endl;
					}

					// If Goblin 3 is alive
					if (goblin3.getHealth() > 0) {
						// Output the amount of health lost after the round
						std::cout << "\n\n  [-" << hpLost << " HP]" << std::endl;
					}

					std::this_thread::sleep_for(std::chrono::milliseconds(350));  // Pause 0.35 sec
				}
			} while (goblin3.getHealth() > 0 && player.getHealth() > 0);
			// Keep repeating the block of code until Goblin 3 or the player dies

			// If the Enemy's health has dropped below zero, set
			// their health to 0 (you can't have negative health)
			if (goblin3.getHealth() < 0) {
				goblin3.setHealth(0);
			}

			// If the player has died
			if (player.getHealth() <= 0) {
				// Run the Death() method
				Death();
				// Terminate the program
				exit(0);
			}

			// Output the health status of player & all enemies
			std::cout << "\n\n  ###############################\n  HP:       (" << player.getHealth() << "/" << player.getMaxHealth() << ")\n  " <<
				"Goblin 1: (" << goblin1.getHealth() << "/" << goblin1.getMaxHealth() << ")\n  " <<
				"Goblin 2: (" << goblin2.getHealth() << "/" << goblin2.getMaxHealth() << ")\n  " <<
				"Goblin 3: (" << goblin3.getHealth() << "/" << goblin3.getMaxHealth() << ")\n  " <<
				"###############################" << std::endl;

			// Update the Character object 'player' by calculating
			// the updated experience from Goblin 3's death
			player = CalculateEXP(player, goblin3);

			// Output completion notification
			std::cout << "\n\n  Congratulations, you have killed the goblins!!\n  What now?" << std::endl;

		}

		// If user chose Goblin 3 ('B'/'b')
		// ATTACK GOBLIN 3 -- GOBLIN 1 STILL ALIVE
		else if (optionChar == 'B') {
			// Block of code to loop while Goblin 3 is still alive
			do {
				// Output health status of player & all enemies
				std::cout << "\n\n  ###############################\n  HP:       (" << player.getHealth() << "/" << player.getMaxHealth() << ")\n  " <<
					"Goblin 1: (" << goblin1.getHealth() << "/" << goblin1.getMaxHealth() << ")\n  " <<
					"Goblin 2: (" << goblin2.getHealth() << "/" << goblin2.getMaxHealth() << ")\n  " <<
					"Goblin 3: (" << goblin3.getHealth() << "/" << goblin3.getMaxHealth() << ")\n  " <<
					"###############################" << std::endl;

				std::this_thread::sleep_for(std::chrono::milliseconds(200));  // Pause 0.2 sec

				// Ask the player to either Attack or retreat
				std::cout << "\n  Attack or Retreat? ";
				// get user input
				option = choiceYesNo("Attack", "Retreat");

				clear();  // Clear console window

				// If option is false -- user chose "Retreat" ('R'/'r')
				if (option == false) {
					// If a random number of 1-3 is 1 (33% chance)
					if ((rand() % 3) == 1) {
						// Output successful escape notification
						std::cout << "\n  You have successfully escaped." << std::endl;

						// Set the health of all remaining enemies to 0
						goblin1.setHealth(0);
						goblin3.setHealth(0);

						// Go to the location of 'END:' and play from there
						//   (exits the loop & ends the battle)
						goto END;
					}
					// Otherwise (If the random number is not 1 -- the 66% chance of failed retreat passes)...
					else {
						std::this_thread::sleep_for(std::chrono::milliseconds(200));  // Pause 0.2 sec

						// Output failed escape notification
						std::cout << "\n  Retreat failed." << std::endl;

						// If Goblin 1 is still alive
						if (goblin1.getHealth() > 0) {
							// Output free attack
							std::cout << "\n  Goblin 1 got in a free attack. [-10 HP]" << std::endl;

							// Subtract 10 health from the player
							player.setHealth(player.getHealth() - 10);
						}
						// If Goblin 3 is still alive
						if (goblin3.getHealth() > 0) {
							// Output free attack
							std::cout << "  Goblin 3 got in a free attack. [-10 HP]" << std::endl;

							// Subtract 10 health from the player
							player.setHealth(player.getHealth() - 10);
						}
						// Set option to true
						//   (so that the player attack occurs next)
						option = true;
					}
				}
				// If option is true -- user chose "Attack" ('A'/'a') or failed to retreat
				if (option == true) {
					std::this_thread::sleep_for(std::chrono::milliseconds(350));  // Pause 0.35 sec

					// Set the player's lost hp to 0 (to reset upon loop repeat)
					hpLost = 0;

					// Random Player Damage between: 1/2 Base Atk Damage - Full Base Atk Damage
					attack = ((player.getDamage() / 2) + (rand() % (player.getDamage() - (player.getDamage() / 2) + 1)));
					// Random Enemy Damage between: 1/2 Base Atk Damage - Full Base Atk Damage
					mobAttack1 = ((goblin1.getDamage() / 2) + (rand() % (goblin1.getDamage() - (goblin1.getDamage() / 2) + 1)));
					mobAttack3 = ((goblin3.getDamage() / 2) + (rand() % (goblin3.getDamage() - (goblin3.getDamage() / 2) + 1)));

					// Modify Player attack to subtract 1/2 DEF Stat Value Multiplied by Level (Higher Defense & Higher Level = Less Damage Taken)
					fAttack = attack - ((goblin3.getLevel() * goblin3.getDEF()) / 2);
					// Modify Enemy attack to subtract 1/2 True DEF Stat Value Multiplied by Level (Higher Defense & Higher Level = Less Damage Taken)
					fMobAttack1 = mobAttack1 - ((player.getLevel() * (player.getDEF() + player.getDEFBoost())) / 2);
					fMobAttack3 = mobAttack3 - ((player.getLevel() * (player.getDEF() + player.getDEFBoost())) / 2);

					// If any attack damages are less than zero
					// Set them to zero (there can't be negative damage)
					if (fAttack < 0) {
						fAttack = 0;
					}
					if (fMobAttack1 < 0) {
						fMobAttack1 = 0;
					}
					if (fMobAttack3 < 0) {
						fMobAttack3 = 0;
					}

					// Set the player's dodge rate to double variable 'dodgeRate'
					//   (for dodge rate percentage calculations)
					dodgeRate = player.getDodgeRate();

					// Subtract Goblin 3's health by the player's attack damage
					goblin3.setHealth(goblin3.getHealth() - fAttack);

					// Output attack notifications
					std::cout << "\n  You attack Goblin 3 for " << fAttack << " damage!" << std::endl;

					std::this_thread::sleep_for(std::chrono::milliseconds(200));  // Pause 0.2 sec

					// If Goblin 3 is alive
					if (goblin3.getHealth() > 0) {
						// Output that Goblin 3 is beginning a counter attack
						std::cout << "\n  [Goblin 3 begins their counter attack.]" << std::endl;

						// Set integer variable 'agilityModifier' to 0 (to reset upon loop repeat)
						agilityModifier = 0;

						// Set integer variable 'randomDodge' to a random number of 1-100
						//   (for matching usage to determine player's dodge percentage)
						randomDodge = (1 + (rand() % ((100 - 1) + 1)));

						// Set boolean 'fullDodge' to false (to reset upon loop repeat)
						//   (this is used to break out of the loop
						//    if the first dodge check is a success)
						fullDodge = false;

						// 'numIncrease' & 'numIncrease2' are used as the two values
						// for the range of the dodge rate checker, used with 'randomDodge'

						// Set integer 'numIncrease' to 1
						numIncrease = 1;
						// Set integer 'numIncrease2' to the player's dodge rate times 100
						//   (decimal of 0.01-1 to a whole # of 1-100)
						numIncrease2 = (int)(dodgeRate * 100);

						// FIRST DODGE CHECK:
						// If the dodge check is a success
						//   (randomized num of 1-100 is within the
						//    starting range of the dodge rate checker)
						if (randomDodge > numIncrease && randomDodge <= numIncrease2) {
							// Set boolean 'fullDodge' to true
							fullDodge = true;
						}
						// Otherwise...
						else {
							// Increase the range of the
							// dodge rate checker up one notch
							numIncrease = numIncrease2;
							numIncrease2 = numIncrease2 + 20;
						}

						// Loop five times (after 5 times, dodge rate is guaranteed 0%)
						for (unsigned i = 0;i < 5;++i) {
							// If 'fullDodge' is true (if first check above succeeded)
							if (fullDodge == true) {
								// Break out of the loop
								break;
							}

							// If the modifier is between 0 and 1 (but not actually 1)
							if (agilityModifier < 1 && agilityModifier >= 0) {
								// Increase the modifier by 0.25 (25% less damage avoided)
								agilityModifier = agilityModifier + 0.25;  // Dodges: 100% - 75% - 50% - 25% - 0%
							}
							// If the modifier is equal to 1 (0% damage avoided)
							if (agilityModifier == 1.0) {
								// Break out of the loop
								break;
							}

							// If 'numIncrease' or 'numIncrease2' reaches 100
							if (numIncrease > 100 || numIncrease2 > 100) {
								// Break out of the loop
								break;
							}
							// NEXT DODGE CHECK:
							// If the dodge check is a success
							//   (randomized num of 1-100 is within the
							//    increased range of the dodge rate checker)
							if (randomDodge > numIncrease && randomDodge <= numIncrease2) {
								// Break out of the loop
								break;
							}

							// Increase the two values of the range of the dodge rate checker
							numIncrease = numIncrease + 20;
							numIncrease2 = numIncrease2 + 20;
						}

						// If the modifier is equal to 0 -- 100% damage avoided (0 x dmg = no dmg taken)
						if (agilityModifier == 0.0) {
							// Output that the player avoided 100% of Goblin 3's attack
							std::cout << "\n  You avoided Goblin 3's attack [" << fMobAttack3 << " DMG] with your agility!" << std::endl;
						}  // OR
						// If the modifier is equal to 1 -- 0% damage avoided (1 x dmg = full dmg taken)
						else if (agilityModifier == 1.0) {
							// Subtract 100% of Goblin 3's attack from the player's health
							player.setHealth(player.getHealth() - fMobAttack3);

							// Output that the player took 100% of Goblin 3's attacks
							std::cout << "\n  Goblin 3 counter attacks for " << fMobAttack3 << " damage!" << std::endl;

							// Add the damage the player received to variable 'hpLost'
							//   (for output after the round ends)
							hpLost = (hpLost + fMobAttack3);
						}
						// Otherwise (If the modifier is more than 0 and less than 1 -- 0.25, 0.5, 0.75)...
						else {
							// Subtract Goblin 3's attack (minus the avoided damage) from the player's health
							//   - atk x 0.25 = 75% dmg avoided (Player gets damaged 25% of the enemy's dmg)
							//   - atk x 0.5  = 50% dmg avoided (Player gets damaged 50% of the enemy's dmg)
							//   - atk x 0.75 = 25% dmg avoided (Player gets damaged 75% of the enemy's dmg)
							player.setHealth(player.getHealth() - (fMobAttack3 * agilityModifier));

							// Output the % of damage the player negated and how much damage the player took
							std::cout << "\n  You have negated " << ((1 - agilityModifier) * 100) << "% of Goblin 3's attack damage [" << fMobAttack3 << " DMG] " <<
								"by maneuvering with your agility! You only take " << (fMobAttack3 * agilityModifier) << " damage!" << std::endl;

							// Add the damage the player received to variable 'hpLost'
							//   (for output after the round ends)
							hpLost = (hpLost + (fMobAttack3 * agilityModifier));
						}
					}

					// Otherwise (if Goblin 3 is dead)...
					else {
						// Output that Goblin 3 has perished & how much experience the player gets
						std::cout << "\n  [Goblin 3 has perished.]\n  [EXP+" << goblin3.getEXP() << "]" << std::endl;
					}

					// If Goblin 1 is alive
					if (goblin1.getHealth() > 0) {
						// Output that the other goblin is beginning their attack
						std::cout << "\n\n  [The other goblin begins their attack.]" << std::endl;

						// Set integer variable 'agilityModifier' to 0 (to reset upon loop repeat)
						agilityModifier = 0;

						// Set integer variable 'randomDodge' to a random number of 1-100
						//   (for matching usage to determine player's dodge percentage)
						randomDodge = (1 + (rand() % ((100 - 1) + 1)));

						// Set boolean 'fullDodge' to false (to reset upon loop repeat)
						//   (this is used to break out of the loop
						//    if the first dodge check is a success)
						fullDodge = false;

						// 'numIncrease' & 'numIncrease2' are used as the two values
						// for the range of the dodge rate checker, used with 'randomDodge'

						// Set integer 'numIncrease' to 1
						numIncrease = 1;
						// Set integer 'numIncrease2' to the player's dodge rate times 100
						//   (decimal of 0.01-1 to a whole # of 1-100)
						numIncrease2 = (int)(dodgeRate * 100);

						// FIRST DODGE CHECK:
						// If the dodge check is a success
						//   (randomized num of 1-100 is within the
						//    starting range of the dodge rate checker)
						if (randomDodge > numIncrease && randomDodge <= numIncrease2) {
							// Set boolea 'fullDodge' to true
							fullDodge = true;
						}
						// Otherwise...
						else {
							// Increase the range of the
							// dodge rate checker up one notch
							numIncrease = numIncrease2;
							numIncrease2 = numIncrease2 + 20;
						}

						// Loop five times (after 5 times, dodge rate is guaranteed 0%)
						for (unsigned i = 0;i < 5;++i) {
							// If 'fullDodge' is true (if first check above succeeded)
							if (fullDodge == true) {
								// Break out of the loop
								break;
							}

							// If the modifier is between 0 and 1 (but not actually 1)
							if (agilityModifier < 1 && agilityModifier >= 0) {
								// Increase the modifier by 0.25 (25% less damage avoided)
								agilityModifier = agilityModifier + 0.25;  // Dodges: 100% - 75% - 50% - 25% - 0%
							}
							// If the modifier is equal to 1 (0% damage avoided)
							if (agilityModifier == 1.0) {
								// Break out of the loop
								break;
							}

							// If 'numIncrease' or 'numIncrease2' reaches 100
							//   (the loop ran through all checks to 100%)
							if (numIncrease > 100 || numIncrease2 > 100) {
								//Break out of the loop
								break;
							}
							// NEXT DODGE CHECK:
							// If the dodge check is a success
							//   (randomized num of 1-100 is within the
							//    increased range of the dodge rate checker)
							if (randomDodge > numIncrease && randomDodge <= numIncrease2) {
								// Break out of the loop
								break;
							}

							// Increase the two values of the range of the dodge rate checker
							numIncrease = numIncrease + 20;
							numIncrease2 = numIncrease2 + 20;
						}

						// If the modifier is equal to 0 -- 100% damage avoided (0 x dmg = no dmg taken)
						if (agilityModifier == 0.0) {
							// Output that the player avoided 100% of Goblin 1's damage
							std::cout << "\n  You avoided Goblin 1's attack [" << fMobAttack1 << " DMG] with your agility!" << std::endl;
						}  // OR
						// If the modifier is equal to 1 -- 0% damage avoided (1 x dmg = full dmg taken)
						else if (agilityModifier == 1.0) {
							// Subtract 100% of Goblin 1's attack from the player's health
							player.setHealth(player.getHealth() - fMobAttack1);

							// Output that the player took 100% of Goblin 1's health
							std::cout << "\n  Goblin 1 attacks you for " << fMobAttack1 << " damage!" << std::endl;

							// Add the damage the player received to variable 'hpLost'
							//   (for output after the round ends)
							hpLost = (hpLost + fMobAttack1);
						}
						// Otherwise (If the modifier is more than 0 and less than 1 -- 0.25, 0.5, 0.75)...
						else {
							// Subtract Goblin 1's attack (minus the avoided damage) from the player's health
							//   - atk x 0.25 = 75% dmg avoided (Player gets damaged 25% of the enemy's dmg)
							//   - atk x 0.5  = 50% dmg avoided (Player gets damaged 50% of the enemy's dmg)
							//   - atk x 0.75 = 25% dmg avoided (Player gets damaged 75% of the enemy's dmg)
							player.setHealth(player.getHealth() - (fMobAttack1 * agilityModifier));

							// Output the % of the damage the player negated and how much damage the player took
							std::cout << "\n  You have negated " << ((1 - agilityModifier) * 100) << "% of Goblin 1's attack damage [" << fMobAttack1 << " DMG] " <<
								"by maneuvering with your agility! You only take " << (fMobAttack1 * agilityModifier) << " damage!" << std::endl;

							// Add the damage the player received to variable 'hpLost'
							//   (for output after the round ends)
							hpLost = (hpLost + (fMobAttack1 * agilityModifier));
						}
					}

					// Otherwise (If Goblin 1 is dead)...
					else {
						// Output that Goblin 1 has perished & how much experience the player gets
						std::cout << "\n  [Goblin 1 has perished.]\n  [EXP+" << goblin1.getEXP() << "]" << std::endl;
					}

					// Output the amount of health lost after the round
					std::cout << "\n\n  [-" << hpLost << " HP]" << std::endl;

					std::this_thread::sleep_for(std::chrono::milliseconds(350));  // Pause 0.35 sec
				}
			} while (goblin3.getHealth() > 0 && player.getHealth() > 0);
			// Keep repeating the block of code until Goblin 3 or the player dies

			// If any of the Enemys' health has dropped below zero,
			// set their health to 0 (you can't have negative health)
			if (goblin1.getHealth() < 0) {
				goblin1.setHealth(0);
			}
			if (goblin3.getHealth() < 0) {
				goblin3.setHealth(0);
			}

			// If the player has died
			if (player.getHealth() <= 0) {
				// Run the Death() method
				Death();
				// Terminate the program
				exit(0);
			}

			// Output the health status of player & all enemies
			std::cout << "\n\n  ###############################\n  HP:       (" << player.getHealth() << "/" << player.getMaxHealth() << ")\n  " <<
				"Goblin 1: (" << goblin1.getHealth() << "/" << goblin1.getMaxHealth() << ")\n  " <<
				"Goblin 2: (" << goblin2.getHealth() << "/" << goblin2.getMaxHealth() << ")\n  " <<
				"Goblin 3: (" << goblin3.getHealth() << "/" << goblin3.getMaxHealth() << ")\n  " <<
				"###############################" << std::endl;

			// Update the Character object 'player' by calculating
			// the updated experience from Goblin 3's death
			player = CalculateEXP(player, goblin3);

			// Output to the player that there is only one enemy remaining
			std::cout << "\n\n  There is only one goblin remaining. You're almost there!" << std::endl;

			/*  ===================================================================================  */
			/*  ================================                   ================================  */
			/*  ================================    LAST BATTLE    ================================  */
			/*  ================================                   ================================  */
			/*  ===================================================================================  */

			// ATTACK GOBLIN 1

			// Block of code to loop while Goblin 1 is alive
			do {
				// Output health status of player & all enemies
				std::cout << "\n\n  ###############################\n  HP:       (" << player.getHealth() << "/" << player.getMaxHealth() << ")\n  " <<
					"Goblin 1: (" << goblin1.getHealth() << "/" << goblin1.getMaxHealth() << ")\n  " <<
					"Goblin 2: (" << goblin2.getHealth() << "/" << goblin2.getMaxHealth() << ")\n  " <<
					"Goblin 3: (" << goblin3.getHealth() << "/" << goblin3.getMaxHealth() << ")\n  " <<
					"###############################" << std::endl;

				std::this_thread::sleep_for(std::chrono::milliseconds(200));  // Pause 0.2 sec

				// Ask the player to either Attack or Retreat
				std::cout << "\n  Attack or Retreat? ";
				// Get user input
				option = choiceYesNo("Attack", "Retreat");

				clear();  // Clear console window

				// If option is false -- user chose "Retreat" ('R'/'r')
				if (option == false) {
					// If a random number of 1-3 is 1 (33% chance)
					if ((rand() % 3) == 1) {
						// Output successful escape notification
						std::cout << "\n  You have successfully escaped." << std::endl;

						// Set the health of the enemy to 0
						goblin1.setHealth(0);

						// Go to the location of 'END:' and play from there
						//   (exits the loop & ends the battle)
						goto END;
					}
					// Otherwise (If the random number is not 1 -- the 66% chance of failed retreat passes)...
					else {
						std::this_thread::sleep_for(std::chrono::milliseconds(200));  // Pause 0.2 sec

						// Output failed escape notification
						std::cout << "\n  Retreat failed." << std::endl;

						// If Goblin 1 is still alive
						if (goblin1.getHealth() > 0) {
							// Output free attack
							std::cout << "\n  Goblin 1 got in a free attack. [-10 HP]" << std::endl;

							// Subtract 10 health from the player
							player.setHealth(player.getHealth() - 10);
						}
						// Set option to true
						//   (so that the player attack occurs)
						option = true;
					}
				}
				// If option is true -- user chose "Attack" ('A'/'a') or failed to retreat
				if (option == true) {
					std::this_thread::sleep_for(std::chrono::milliseconds(350));  // Pause 0.35 saec

					// Set the player's lost hp to 0 (to reset upon loop repeat)
					hpLost = 0;

					// Random Player Damage between: 1/2 Base Atk Damage - Full Base Atk Damage
					attack = ((player.getDamage() / 2) + (rand() % (player.getDamage() - (player.getDamage() / 2) + 1)));
					// Random Enemy Damage between: 1/2 Base Atk Damage - Full Base Atk Damage
					mobAttack1 = ((goblin1.getDamage() / 2) + (rand() % (goblin1.getDamage() - (goblin1.getDamage() / 2) + 1)));

					// Modify Player attack to subtract 1/2 DEF Stat Value Multiplied by Level (Higher Defense & Higher Level = Less Damage Taken)
					fAttack = attack - ((goblin1.getLevel() * goblin1.getDEF()) / 2);
					// Modify Enemy attack to subtract 1/2 True DEF Stat Value Multiplied by Level (Higher Defense & Higher Level = Less Damage Taken)
					fMobAttack1 = mobAttack1 - ((player.getLevel() * (player.getDEF() + player.getDEFBoost())) / 2);

					// If any attack damages are less than zero
					// Set them to zero (there can't be negative damage)
					if (fAttack < 0) {
						fAttack = 0;
					}
					if (fMobAttack1 < 0) {
						fMobAttack1 = 0;
					}

					// Set the player's dodge rate to double variable 'dodgeRate'
					//   (for dodge rate percentage calculations)
					dodgeRate = player.getDodgeRate();

					// Subtract Goblin 1's health by the player's attack damage
					goblin1.setHealth(goblin1.getHealth() - fAttack);

					// Output attack notification
					std::cout << "\n  You attack Goblin 1 for " << fAttack << " damage!" << std::endl;

					std::this_thread::sleep_for(std::chrono::milliseconds(200));  // Pause 0.2 sec

					// If Goblin 1 is still alive
					if (goblin1.getHealth() > 0) {
						// Output that Goblin 1 is beginning a counter attack
						std::cout << "\n  [Goblin 1 begins their counter attack.]" << std::endl;

						// Set integer variable 'agilityModifier' to 0 (to reset upon loop repeat)
						agilityModifier = 0;

						// Set integer variable 'randomDodge' to a random number of 1-100
						//   (for matching usage to determine player's dodge percentage)
						randomDodge = (1 + (rand() % ((100 - 1) + 1)));

						// Set boolean 'fullDodge' to false (to reset upon loop repeat)
						//   (this is used to break out of the loop
						//    if the first dodge check is a success)
						fullDodge = false;

						// Set integer 'numIncrease' to 1
						numIncrease = 1;
						// Set integer 'numIncrease2' to the player's dodge rate times 100
						//   (decimal of 0.01-1 to a whole # of 1-100)
						numIncrease2 = (int)(dodgeRate * 100);

						// FIRST DODGE CHECK:
						// If the dodge check is a success
						//   (randomized num of 1-100 is within the
						//    starting range of the dodge rate checker)
						if (randomDodge > numIncrease && randomDodge <= numIncrease2) {
							// Set boolean 'fullDodge' to true
							fullDodge = true;
						}
						// Otherwise...
						else {
							// Increase the range of the
							// dodge rate checker up one notch
							numIncrease = numIncrease2;
							numIncrease2 = numIncrease2 + 20;
						}

						// Loop five times (after 5 times, dodge rate is guaranteed 0%)
						for (unsigned i = 0;i < 5;++i) {
							// If 'fullDodge' is true (if first check above succeeded)
							if (fullDodge == true) {
								// Break out of the loop
								break;
							}

							// If the modifier is between 0 and 1 (but not actually 1)
							if (agilityModifier < 1 && agilityModifier >= 0) {
								// Increase the modifier by 0.25 (25% less damage avoided)
								agilityModifier = agilityModifier + 0.25;  // Dodges: 100% - 75% - 50% - 25% - 0%
							}
							// If the modifier is equal to 1 (0% damage avoided)
							if (agilityModifier == 1.0) {
								// Break out of the loop
								break;
							}

							// If 'numIncrease' or 'numIncrease2' reaches 100
							//   (the loop ran through all checks to 100%)
							if (numIncrease > 100 || numIncrease2 > 100) {
								// Break out of the loop
								break;
							}
							// NEXT DODGE CHECK:
							// If the dodge check is a success
							//   (randomized num of 1-100 is within the
							//    increased range of the dodge rate checker)
							if (randomDodge > numIncrease && randomDodge <= numIncrease2) {
								// Break out of the loop
								break;
							}

							// Increase the two values of the range of the dodge rate checker
							numIncrease = numIncrease + 20;
							numIncrease2 = numIncrease2 + 20;
						}

						// If the modifier is equal to 0 -- 100% damage avoided (0 x dmg = no dmg taken)
						if (agilityModifier == 0.0) {
							// Output that the player avoided 100% of Goblin 1's damage
							std::cout << "\n  You avoided Goblin 1's attack [" << fMobAttack1 << " DMG] with your agility!" << std::endl;
						}  // OR
						// If the modifier is equal to 1 -- 0% damage avoided (1 x dmg = full dmg taken)
						else if (agilityModifier == 1.0) {
							// Subtract 100% of Goblin 1's attack from the player's health
							player.setHealth(player.getHealth() - fMobAttack1);

							// Output that the player took 100% of Goblin 1's attack
							std::cout << "\n  Goblin 1 counter attacks for " << fMobAttack1 << " damage!" << std::endl;

							// Add the damage the player received to variable 'hpLost'
							//   (for output after the round ends)
							hpLost = (hpLost + fMobAttack1);
						}
						// Otherwise (If the modifier is more than 0 and less than 1 -- 0.25, 0.5, 0.75)...
						else {
							// Subtract Goblin 1's attack (minus the avoided damage) from the player's health
							//   - atk x 0.25 = 75% dmg avoided (Player gets damaged 25% of the enemy's dmg)
							//   - atk x 0.5  = 50% dmg avoided (Player gets damaged 50% of the enemy's dmg)
							//   - atk x 0.75 = 25% dmg avoided (Player gets damaged 75% of the enemy's dmg)
							player.setHealth(player.getHealth() - (fMobAttack1 * agilityModifier));

							// Output the % of damage the player negated and how much damage the player took
							std::cout << "\n  You have negated " << ((1 - agilityModifier) * 100) << "% of Goblin 1's attack damage [" << fMobAttack1 << " DMG] " <<
								"by maneuvering with your agility! You only take " << (fMobAttack1 * agilityModifier) << " damage!" << std::endl;

							// Add the damage the player received to variable 'hpLost'
							//   (for output after the round ends)
							hpLost = (hpLost + (fMobAttack1 * agilityModifier));
						}
					}

					// Otherwise (If Goblin 1 died)...
					else {
						// Output that Goblin 1 has perished & how much experience the player gets
						std::cout << "\n  [Goblin 1 has perished.]\n  [EXP+" << goblin1.getEXP() << "]" << std::endl;
					}

					// If Goblin 1 is alive
					if (goblin1.getHealth() > 0) {
						// Output the amount of health lost after the round
						std::cout << "\n\n  [-" << hpLost << " HP]" << std::endl;
					}

					std::this_thread::sleep_for(std::chrono::milliseconds(350));  // Pause 0.35 sec
				}
			} while (goblin1.getHealth() > 0 && player.getHealth() > 0);
			// Keep repeating the block of code until Goblin 1 or the player dies

			// If the Enemy's health has dropped below zero, set
			// their health to 0 (you can't have negative health)
			if (goblin1.getHealth() < 0) {
				goblin1.setHealth(0);
			}

			// If the player has died
			if (player.getHealth() <= 0) {
				// Run the Death() method
				Death();
				// Terminate the program
				exit(0);
			}

			// Output the health status of player & all enemies
			std::cout << "\n\n  ###############################\n  HP:       (" << player.getHealth() << "/" << player.getMaxHealth() << ")\n  " <<
				"Goblin 1: (" << goblin1.getHealth() << "/" << goblin1.getMaxHealth() << ")\n  " <<
				"Goblin 2: (" << goblin2.getHealth() << "/" << goblin2.getMaxHealth() << ")\n  " <<
				"Goblin 3: (" << goblin3.getHealth() << "/" << goblin3.getMaxHealth() << ")\n  " <<
				"###############################" << std::endl;

			// Update the Character object 'player' by calculating
			// the updated experience from Goblin 1's death
			player = CalculateEXP(player, goblin1);

			// Output completion notification
			std::cout << "\n\n  Congratulations, you have killed the goblins!!\n  What now?" << std::endl;
		}
	}

	// If user chose Goblin 3 ('C'/'c')
	// ATTACK GOBLIN 3 -- GOBLIN 1/2 STILL ALIVE
	else if (optionChar == 'C')
	{
		// Block of code to loop while Goblin 3 is still alive
		do {
			// Output health status of player & all enemies
			std::cout << "\n\n  ###############################\n  HP:       (" << player.getHealth() << "/" << player.getMaxHealth() << ")\n  " <<
				"Goblin 1: (" << goblin1.getHealth() << "/" << goblin1.getMaxHealth() << ")\n  " <<
				"Goblin 2: (" << goblin2.getHealth() << "/" << goblin2.getMaxHealth() << ")\n  " <<
				"Goblin 3: (" << goblin3.getHealth() << "/" << goblin3.getMaxHealth() << ")\n  " <<
				"###############################" << std::endl;

			std::this_thread::sleep_for(std::chrono::milliseconds(200));  // Pause 0.2 sec

			// Ask the player to either Attack or Retreat
			std::cout << "\n  Attack or Retreat? ";
			// Get user input
			option = choiceYesNo("Attack", "Retreat");

			// If 'option' is false -- player chose "Retreat" ('R'/'r')
			if (option == false) {
				// If a random number of 1-3 results as 1 (33% chance)
				if ((rand() % 3) == 1) {
					// Output successful escape notification
					std::cout << "\n  You have successfully escaped." << std::endl;

					// Set the health of all enemies to 0
					goblin1.setHealth(0);
					goblin2.setHealth(0);
					goblin3.setHealth(0);

					// Go to the location of 'END:' and play from there
					//   (exits the loop & ends the battle)
					goto END;
				}
				// Otherwise (If the random number result is not 1 -- the 66% chance of failed retreat passes)...
				else {
					std::this_thread::sleep_for(std::chrono::milliseconds(200));  // Pause 0.2 sec

					// Output failed escape notification
					std::cout << "\n  Retreat failed." << std::endl;

					// If Goblin 1 is still alive
					if (goblin1.getHealth() > 0) {
						// Output free attack notification
						std::cout << "\n  Goblin 1 got in a free attack. [-10 HP]" << std::endl;

						// Subtract 10 health from the player
						player.setHealth(player.getHealth() - 10);
					}
					// If Goblin 2 is still alive
					if (goblin2.getHealth() > 0) {
						// Output free attack notification
						std::cout << "  Goblin 2 got in a free attack. [-10 HP]" << std::endl;

						// Subtract 10 health from the player
						player.setHealth(player.getHealth() - 10);
					}
					// If Goblin 3 is still alive
					if (goblin3.getHealth() > 0) {
						// Output free attack notification
						std::cout << "  Goblin 3 got in a free attack. [-10 HP]" << std::endl;

						// Subtract 10 health from the player
						player.setHealth(player.getHealth() - 10);
					}
					// Set option to true
					//   (so that the player attack occurs next)
					option = true;
				}
			}
			// If 'option' is true -- player chose "Attack" ('A'/'a') or failed to retreat
			if (option == true) {
				std::this_thread::sleep_for(std::chrono::milliseconds(350));  // Pause 0.35 sec

				// Set the player's lost health variable, 'hpLost', to 0 (to reset upon loop repeat)
				hpLost = 0;

				// Randomize player attack damage between: 1/2 to full base atk damage
				attack = ((player.getDamage() / 2) + (rand() % (player.getDamage() - (player.getDamage() / 2) + 1)));
				// Randomize enemy attack damage between: 1/2 to full base atk damage
				mobAttack1 = ((goblin1.getDamage() / 2) + (rand() % (goblin1.getDamage() - (goblin1.getDamage() / 2) + 1)));
				mobAttack2 = ((goblin2.getDamage() / 2) + (rand() % (goblin2.getDamage() - (goblin2.getDamage() / 2) + 1)));
				mobAttack3 = ((goblin3.getDamage() / 2) + (rand() % (goblin3.getDamage() - (goblin3.getDamage() / 2) + 1)));

				// Modify player attack damage to subtract 1/2 DEF stat value multiplied by level
				//   (higher defense & higher level = less damage taken)
				fAttack = attack - ((goblin3.getLevel() * goblin3.getDEF()) / 2);
				// Modify enemy attack damage to subtract 1/2 DEF stat value multiplied by level
				//   (higher defense & higher level = less damage taken)
				fMobAttack1 = mobAttack1 - ((player.getLevel() * (player.getDEF() + player.getDEFBoost())) / 2);
				fMobAttack2 = mobAttack2 - ((player.getLevel() * (player.getDEF() + player.getDEFBoost())) / 2);
				fMobAttack3 = mobAttack3 - ((player.getLevel() * (player.getDEF() + player.getDEFBoost())) / 2);

				// If any attack damages are less than zero...
				// Set them to zero (there can't be negative damage)
				if (fAttack < 0) {
					fAttack = 0;
				}
				if (fMobAttack1 < 0) {
					fMobAttack1 = 0;
				}
				if (fMobAttack2 < 0) {
					fMobAttack2 = 0;
				}
				if (fMobAttack3 < 0) {
					fMobAttack3 = 0;
				}

				// Set the player's dodge rate to double variable 'dodgeRate'
				//   (for dodge rate percentage calculations)
				dodgeRate = player.getDodgeRate();

				// Subtract Goblin 3's health by the player's attack damage
				goblin3.setHealth(goblin3.getHealth() - fAttack);

				// Output attack notification
				std::cout << "\n  You attack Goblin 3 for " << fAttack << " damage!" << std::endl;

				std::this_thread::sleep_for(std::chrono::milliseconds(200));  // Pause 0.2 sec

				// If Goblin 3 is alive
				if (goblin3.getHealth() > 0) {
					// Output that Goblin 3 is beginning a counter attack
					std::cout << "\n  [Goblin 3 begins their counter attack.]" << std::endl;

					// Set integer variable 'agilityModifier' to 0 (to reset upon loop repeat)
					agilityModifier = 0;

					// Set integer variable 'randomDodge' to a random number of 1-100
					//   (for matching usage to determine player's dodge percentage)
					randomDodge = (1 + (rand() % ((100 - 1) + 1)));

					// Set boolean 'fullDodge' to false (to reset upon loop repeat)
					//   (this is used to break out of the loop
					//    if the first dodge check is a success)
					fullDodge = false;

					// 'numIncrease' & 'numIncrease2' are used as the two values
					// for the range of the dodge rate checker, used with 'randomDodge'

					// Set integer 'numIncrease' to 1 and
					// integer 'numIncrease2' to the player's dodge rate times 100
					numIncrease = 1;
					numIncrease2 = (int)(dodgeRate * 100);  // 0.01-1 (decimal) to 1-100 (whole #)

					// FIRST DODGE CHECK:
					// If the dodge check is a success
					//   (randomized num of 1-100 is within the
					//    starting range of the dodge rate checker)
					if (randomDodge > numIncrease && randomDodge <= numIncrease2) {
						// Set boolean 'fullDodge' to true
						fullDodge = true;
					}
					// Otherwise (If the dodge check failed)...
					else {
						// Increase the range of the
						// dodge rate checker up one notch
						numIncrease = numIncrease2;
						numIncrease2 = numIncrease2 + 20;
					}

					// Loop five times (after 5 times, dodge rate is guaranteed 0%)
					for (unsigned i = 0;i < 5;++i) {
						// If boolean 'fullDodge' is true (if first check above succeeded)
						if (fullDodge == true) {
							// Break out of the loop
							break;
						}

						// If the modifier is between 0 and 1 (but not actually 1)
						if (agilityModifier < 1 && agilityModifier >= 0) {
							// Increase the modifier by 0.25 (-25% damage avoided)
							agilityModifier = agilityModifier + 0.25;  // Dodges: 100% - 75% - 50% - 25% - 0%
						}
						// If the modifier is equal to 1 (0% damage avoided)
						if (agilityModifier == 1.0) {
							// Break out of the loop
							break;
						}

						// If 'numIncrease' or 'numIncrease2' reaches 100
						//   (the loop ran through all checks to 100%)
						if (numIncrease > 100 || numIncrease2 > 100) {
							// Break out of the loop
							break;
						}

						// NEXT DODGE CHECK:
						// If the dodge check is a success
						//   (randomized num of 1-100 is within the
						//    increased range of the dodge rate checker)
						if (randomDodge > numIncrease && randomDodge <= numIncrease2) {
							// Break out of the loop
							break;
						}

						// Increase the two values of the range of the dodge rate checker
						numIncrease = numIncrease + 20;
						numIncrease2 = numIncrease2 + 20;
					}

					// If the modifier is equal to 0 -- 100% damage avoided (0 x dmg = no dmg taken)
					if (agilityModifier == 0.0) {
						// Output that the player avoided 100% of Goblin 3's attack damage
						std::cout << "\n  You avoided Goblin 3's attack [" << fMobAttack3 << " DMG] with your agility!" << std::endl;
					}  // OR
					// If the modifier is equal to 1 -- 0% damage avoided (1 x dmg = full dmg taken)
					else if (agilityModifier == 1.0) {
						// Subtract 100% of Goblin 3's attack damage from the player's health
						player.setHealth(player.getHealth() - fMobAttack3);

						// Output that the player took 100% of Goblin 3's attack damage
						std::cout << "\n  Goblin 3 counter attacks for " << fMobAttack3 << " damage!" << std::endl;

						// Add the damage the player received to variable 'hpLost'
						//   (for output after the round ends)
						hpLost = (hpLost + fMobAttack3);
					}
					// Otherwise (If the modifier is more than 0 and less than 1 -- 0.25, 0.5, 0.75)...
					else {
						// Subtract Goblin 3's attack (minus the avoided damage) from the player's health
						//   - atk x 0.25 = 75% dmg avoided (Player gets damaged 25% of the enemy's dmg)
						//   - atk x 0.50 = 50% dmg avoided (Player gets damaged 50% of the enemy's dmg)
						//   - atk x 0.75 = 25% dmg avoided (Player gets damaged 75% of the enemy's dmg)
						player.setHealth(player.getHealth() - (fMobAttack3 * agilityModifier));

						// Output the % of damage the player negated and how much damage the player took
						std::cout << "\n  You have negated " << ((1 - agilityModifier) * 100) << "% of Goblin 3's attack damage [" << fMobAttack3 << " DMG] " <<
							"by maneuvering with your agility! You only take " << (fMobAttack3 * agilityModifier) << " damage!" << std::endl;

						// Add the damage the player received to variable 'hpLost'
						//   (for output after the round ends)
						hpLost = (hpLost + (fMobAttack3 * agilityModifier));
					}
				}

				// Otherwise (If Goblin 3 is dead)...
				else {
					// Output that Goblin 3 has died & how much experience the player receives
					std::cout << "\n  [Goblin 3 has perished.]\n  [EXP+" << goblin3.getEXP() << "]" << std::endl;
				}

				// If Goblin 1 is alive
				if (goblin1.getHealth() > 0) {
					// Output that the other goblins are beginning their attacks
					std::cout << "\n\n  [The other goblins begin their attacks.]" << std::endl;

					// Set integer variable 'agilityModifier' to 0 (to reset upon loop repeat)
					agilityModifier = 0;

					// Set integer variable 'randomDodge' to a random number of 1-100
					//   (for matching usage to determine player's dodge percentage)
					randomDodge = (1 + (rand() % ((100 - 1) + 1)));

					// Set boolean 'fullDodge' to false (to reset upon loop repeat)
					//   (this is used to break out of the loop
					//    if the first dodge check is a success)
					fullDodge = false;

					// 'numIncrease' & 'numIncrease2' are used as the two values
					// for the range of the dodge rate checker, used with 'randomDodge'

					// Set integer 'numIncrease' to 1 and
					// integer 'numIncrease2' to the player's dodge rate times 100
					numIncrease = 1;
					numIncrease2 = (int)(dodgeRate * 100);  // 0.01-1 (decimal) to 1-100 (whole #)

					// FIRST DODGE CHECK:
					// If the dodge check is a success
					//   (randomized num of 1-100 is within the
					//    starting range of the dodge rate checker)
					if (randomDodge > numIncrease && randomDodge <= numIncrease2) {
						// Set boolean 'fullDodge' to true
						fullDodge = true;
					}
					// Otherwise (If the dodge check failed)...
					else {
						// Increase the range of the
						// dodge rate checker up one notch
						numIncrease = numIncrease2;
						numIncrease2 = numIncrease2 + 20;
					}

					// Loop five times (after 5 times, dodge rate is guaranteed 0%)
					for (unsigned i = 0;i < 5;++i) {
						// If boolean 'fullDodge' is true (if first check above succeeded)
						if (fullDodge == true) {
							// Break out of the loop
							break;
						}

						// If the modifier is between 0 and 1 (but not actually 1)
						if (agilityModifier < 1 && agilityModifier >= 0) {
							// Increase the modifier by 0.25 (-25% damage avoided)
							agilityModifier = agilityModifier + 0.25;  // Dodges: 100% - 75% - 50% - 25% - 0%
						}
						// If the modifier is equal to 1 (0% damage avoided)
						if (agilityModifier == 1.0) {
							// Break out of the loop
							break;
						}

						// If 'numIncrease' or 'numIncrease2' reaches 100
						//   (the loop ran through all checks to 100%)
						if (numIncrease > 100 || numIncrease2 > 100) {
							// Break out of the loop
							break;
						}

						// NEXT DODGE CHECK:
						// If the dodge check is a success
						//   (randomized num of 1-100 is within the
						//    increased range of the dodge rate checker)
						if (randomDodge > numIncrease && randomDodge <= numIncrease2) {
							// Break out of the loop
							break;
						}

						// Increase the two values of the range of the dodge rate checker
						numIncrease = numIncrease + 20;
						numIncrease2 = numIncrease2 + 20;
					}

					// If the modifier is equal to 0 -- 100% damage avoided (0 x dmg = no dmg taken)
					if (agilityModifier == 0.0) {
						// Output that the player avoided 100% of Goblin 1's attack damage
						std::cout << "\n  You avoided Goblin 1's attack [" << fMobAttack1 << " DMG] with your agility!" << std::endl;
					}  // OR
					// If the modifier is equal to 1 -- 0% damage avoided (1 x dmg = full dmg taken)
					else if (agilityModifier == 1.0) {
						// Subtract 100% of Goblin 1's attack damage from the player's health
						player.setHealth(player.getHealth() - fMobAttack1);

						// Output that the player took 100% of Goblin 1's attack damage
						std::cout << "\n  Goblin 1 attacks you for " << fMobAttack1 << " damage!" << std::endl;

						// Add the damage the player received to variable 'hpLost'
						//   (for output after the round ends)
						hpLost = (hpLost + fMobAttack1);
					}
					// Otherwise (If the modifier is more than 0 and less than 1 -- 0.25, 0.5, 0.75)...
					else {
						// Subtract Goblin 1's attack (minus the avoided damage) from the player's health
						//   - atk x 0.25 = 75% dmg avoided (Player gets damaged 25% of the enemy's dmg)
						//   - atk x 0.50 = 50% dmg avoided (Player gets damaged 50% of the enemy's dmg)
						//   - atk x 0.75 = 25% dmg avoided (Player gets damaged 75% of the enemy's dmg)
						player.setHealth(player.getHealth() - (fMobAttack1 * agilityModifier));

						// Output the % of damage the player negated and how much damage the player took
						std::cout << "\n  You have negated " << ((1 - agilityModifier) * 100) << "% of Goblin 1's attack damage [" << fMobAttack1 << " DMG] " <<
							"by maneuvering with your agility! You only take " << (fMobAttack1 * agilityModifier) << " damage!" << std::endl;

						// Add the damage the player received to variable 'hpLost'
						//   (for output after the round ends)
						hpLost = (hpLost + (fMobAttack1 * agilityModifier));
					}
				}

				// Otherwise (If Goblin 1 is dead)...
				else {
					// Output that Goblin 1 has died & how much experience the player receives
					std::cout << "\n  [Goblin 1 has perished.]\n  [EXP+" << goblin1.getEXP() << "]" << std::endl;
				}

				// If Goblin 2 is alive
				if (goblin2.getHealth() > 0) {
					// Set integer variable 'agilityModifier' to 0 (to reset upon loop repeat)
					agilityModifier = 0;

					// Set integer variable 'randomDodge' to a random number of 1-100
					//   (for matching usage to determine player's dodge percentage)
					randomDodge = (1 + (rand() % ((100 - 1) + 1)));

					// Set boolean 'fullDodge' to false (to reset upon loop repeat)
					//   (this is used to break out of the loop
					//    if the first dodge check is a success)
					fullDodge = false;

					// 'numIncrease' & 'numIncrease2' are used as the two values
					// for the range of the dodge rate checker, used with 'randomDodge'

					// Set integer 'numIncrease' to 1 and
					// integer 'numIncrease2' to the player's dodge rate times 100
					numIncrease = 1;
					numIncrease2 = (int)(dodgeRate * 100);  // 0.01-1 (decimal) to 1-100 (whole #)

					// FIRST DODGE CHECK:
					// If the dodge check is a success
					//   (randomized num of 1-100 is within the
					//    starting range of the dodge rate checker)
					if (randomDodge > numIncrease && randomDodge <= numIncrease2) {
						// Set boolean 'fullDodge' to true
						fullDodge = true;
					}
					// Otherwise (If the dodge check failed)...
					else {
						// Increase the range of the
						// dodge rate checker up one notch
						numIncrease = numIncrease2;
						numIncrease2 = numIncrease2 + 20;
					}

					// Loop five times (after 5 times, dodge rate is guaranteed 0%)
					for (unsigned i = 0;i < 5;++i) {
						// If boolean 'fullDodge' is true (if first check above succeeded)
						if (fullDodge == true) {
							// Break out of the loop
							break;
						}

						// If the modifier is between 0 and 1 (but not actually 1)
						if (agilityModifier < 1 && agilityModifier >= 0) {
							// Increase the modifier by 0.25 (-25% damage avoided)
							agilityModifier = agilityModifier + 0.25;  // Dodges: 100% - 75% - 50% - 25% - 0%
						}
						// If the modifier is equal to 1 (0% damage avoided)
						if (agilityModifier == 1.0) {
							// Break out of the loop
							break;
						}

						// If 'numIncrease' or 'numIncrease2' reaches 100
						//   (the loop ran through all checks to 100%)
						if (numIncrease > 100 || numIncrease2 > 100) {
							// Break out of the loop
							break;
						}

						// NEXT DODGE CHECK:
						// If the dodge check is a success
						//   (randomized num of 1-100 is within the
						//    increased range of the dodge rate checker)
						if (randomDodge > numIncrease && randomDodge <= numIncrease2) {
							// Break out of the loop
							break;
						}

						// Increase the two values of the range of the dodge rate checker
						numIncrease = numIncrease + 20;
						numIncrease2 = numIncrease2 + 20;
					}

					// If the modifier is equal to 0 -- 100% damage avoided (0 x dmg = no dmg taken)
					if (agilityModifier == 0.0) {
						// Output that the player avoided 100% of Goblin 2's attack damage
						std::cout << "\n  You avoided Goblin 2's attack [" << fMobAttack2 << " DMG] with your agility!" << std::endl;
					}  // OR
					// If the modifier is equal to 1 -- 0% damage avoided (1 x dmg = full dmg taken)
					else if (agilityModifier == 1.0) {
						// Subtract 100% of Goblin 2's attack damage from the player's health
						player.setHealth(player.getHealth() - fMobAttack2);

						// Output that the player took 100% of Goblin 2's attack damage
						std::cout << "\n  Goblin 2 attacks you for " << fMobAttack2 << " damage!" << std::endl;

						// Add the damage the player received to variable 'hpLost'
						//   (for output after the round ends)
						hpLost = (hpLost + fMobAttack2);
					}
					// Otherwise (If the modifier is more than 0 and less than 1 -- 0.25, 0.5, 0.75)...
					else {
						// Subtract Goblin 2's attack (minus the avoided damage) from the player's health
						//   - atk x 0.25 = 75% dmg avoided (Player gets damaged 25% of the enemy's dmg)
						//   - atk x 0.50 = 50% dmg avoided (Player gets damaged 50% of the enemy's dmg)
						//   - atk x 0.75 = 25% dmg avoided (Player gets damaged 75% of the enemy's dmg)
						player.setHealth(player.getHealth() - (fMobAttack2 * agilityModifier));

						// Output the % of damage the player negated and how much damage the player took
						std::cout << "\n  You have negated " << ((1 - agilityModifier) * 100) << "% of Goblin 2's attack damage [" << fMobAttack2 << " DMG] " <<
							"by maneuvering with your agility! You only take " << (fMobAttack2 * agilityModifier) << " damage!" << std::endl;

						// Add the damage the player received to variable 'hpLost'
						//   (for output after the round ends)
						hpLost = (hpLost + (fMobAttack2 * agilityModifier));
					}
				}

				// Otherwise (If Goblin 2 is dead)...
				else {
					// Output that Goblin 2 has died & how much experience the player receives
					std::cout << "\n  [Goblin 2 has perished.]\n  [EXP+" << goblin2.getEXP() << "]" << std::endl;
				}

				// Output the amount of health the player lost after the round
				std::cout << "\n\n  [-" << hpLost << " HP]" << std::endl;

				std::this_thread::sleep_for(std::chrono::milliseconds(350));  // Pause 0.35 sec
			}
		} while (goblin3.getHealth() > 0 && player.getHealth() > 0);
		// Keep repeating the block of code until Goblin 3 or the player dies

		// If any of the Enemys' health has dropped below zero,
		// set their health to 0 (you can't have negative health)
		if (goblin1.getHealth() < 0) {
			goblin1.setHealth(0);
		}
		if (goblin2.getHealth() < 0) {
			goblin2.setHealth(0);
		}
		if (goblin3.getHealth() < 0) {
			goblin3.setHealth(0);
		}

		// If the player has died
		if (player.getHealth() <= 0) {
			// Run the Death() method
			Death();
			// Terminate the program
			exit(0);
		}

		// Output the health status of player & all enemies
		std::cout << "\n\n  ###############################\n  HP:       (" << player.getHealth() << "/" << player.getMaxHealth() << ")\n  " <<
			"Goblin 1: (" << goblin1.getHealth() << "/" << goblin1.getMaxHealth() << ")\n  " <<
			"Goblin 2: (" << goblin2.getHealth() << "/" << goblin2.getMaxHealth() << ")\n  " <<
			"Goblin 3: (" << goblin3.getHealth() << "/" << goblin3.getMaxHealth() << ")\n  " <<
			"###############################" << std::endl;

		// Update the Character object 'player' by calculating
		// the updated experience from Goblin 3's death
		player = CalculateEXP(player, goblin3);

		// Ask the player which Goblin to target next
		std::cout << "\n\n  Don't celebrate too soon! The battle still goes on!!\n  Which enemy will you target next?" << std::endl;
		std::cout << "\tA) Goblin 1 (" << goblin1.getHealth() << "/" << goblin1.getMaxHealth() << ")" << std::endl;
		std::cout << "\tB) Goblin 2 (" << goblin2.getHealth() << "/" << goblin2.getMaxHealth() << ")" << std::endl;
		// Get user input
		optionChar = choiceABC("AB");

		// If user chose Goblin 1 ('A'/'a')
		// ATTACK GOBLIN 1 -- GOBLIN 2 STILL ALIVE
		if (optionChar == 'A') {
			// Block of code to loop while Goblin 1 is still alive
			do {
				// Output health status of player & all enemies
				std::cout << "\n\n  ###############################\n  HP:       (" << player.getHealth() << "/" << player.getMaxHealth() << ")\n  " <<
					"Goblin 1: (" << goblin1.getHealth() << "/" << goblin1.getMaxHealth() << ")\n  " <<
					"Goblin 2: (" << goblin2.getHealth() << "/" << goblin2.getMaxHealth() << ")\n  " <<
					"Goblin 3: (" << goblin3.getHealth() << "/" << goblin3.getMaxHealth() << ")\n  " <<
					"###############################" << std::endl;

				std::this_thread::sleep_for(std::chrono::milliseconds(200));  // Pause 0.2 sec

				// Ask the player to either Attack or Retreat
				std::cout << "\n  Attack or Retreat? ";
				// Get user input
				option = choiceYesNo("Attack", "Retreat");

				clear();  // Clear console window

				// If 'option' is false -- player chose "Retreat" ('R'/'r')
				if (option == false) {
					// If a random number of 1-3 results as 1 (33% chance)
					if ((rand() % 3) == 1) {
						// Output successful escape notification
						std::cout << "\n  You have successfully escaped." << std::endl;

						// Set the health of all remaining enemies to 0
						goblin1.setHealth(0);
						goblin2.setHealth(0);

						// Go to the location of 'END:' and player from there
						//   (exits the loop & ends the battle)
						goto END;
					}
					// Otherwise (If the random number is not 1 -- the 66% chance of failed retreat passes)...
					else {
						std::this_thread::sleep_for(std::chrono::milliseconds(200));  // Pause 0.2 sec

						// Output failed escape notification
						std::cout << "\n  Retreat failed." << std::endl;

						// If Goblin 1 is still alive
						if (goblin1.getHealth() > 0) {
							// Output free attack
							std::cout << "\n  Goblin 1 got in a free attack. [-10 HP]" << std::endl;

							// Subtract 10 health from the player
							player.setHealth(player.getHealth() - 10);
						}
						// If Goblin 2 is still alive
						if (goblin2.getHealth() > 0) {
							// Output free attack
							std::cout << "  Goblin 2 got in a free attack. [-10 HP]" << std::endl;

							// Subtract 10 health from the player
							player.setHealth(player.getHealth() - 10);
						}
						// Set option to true
						//   (so that the player attack occurs next)
						option = true;
					}
				}
				// If 'option' is true -- player chose "Attack" ('A'/'a') or failed to retreat
				if (option == true) {
					std::this_thread::sleep_for(std::chrono::milliseconds(350));  // Pause 0.35 sec

					// Set the player's lost health variable, 'hpLost', to 0 (to reset upon loop repeat)
					hpLost = 0;

					// Randomize player attack damage between: 1/2 to full base atk damage
					attack = ((player.getDamage() / 2) + (rand() % (player.getDamage() - (player.getDamage() / 2) + 1)));
					// Randomize enemy attack damage between: 1/2 to full base atk damage
					mobAttack1 = ((goblin1.getDamage() / 2) + (rand() % (goblin1.getDamage() - (goblin1.getDamage() / 2) + 1)));
					mobAttack2 = ((goblin2.getDamage() / 2) + (rand() % (goblin2.getDamage() - (goblin2.getDamage() / 2) + 1)));

					// Modify player attack damage to subtract 1/2 DEF stat value multiplied by level
					//   (higher defense & higher level = less damage taken)
					fAttack = attack - ((goblin1.getLevel() * goblin1.getDEF()) / 2);
					// Modify enemy attack damage to subtract 1/2 DEF stat value multiplied by level
					//   (higher defense & higher level = less damage taken)
					fMobAttack1 = mobAttack1 - ((player.getLevel() * (player.getDEF() + player.getDEFBoost())) / 2);
					fMobAttack2 = mobAttack2 - ((player.getLevel() * (player.getDEF() + player.getDEFBoost())) / 2);

					// If any attack damages are less than zero...
					// Set them to zero (there can't be negative damage)
					if (fAttack < 0) {
						fAttack = 0;
					}
					if (fMobAttack1 < 0) {
						fMobAttack1 = 0;
					}
					if (fMobAttack2 < 0) {
						fMobAttack2 = 0;
					}

					// Set the player's dodge rate to double variable 'dodgeRate'
					//   (for dodge rate percentage calculations)
					dodgeRate = player.getDodgeRate();

					// Subtract Goblin 1's health by the player's attack damage
					goblin1.setHealth(goblin1.getHealth() - fAttack);

					// Output attack notification
					std::cout << "\n  You attack Goblin 1 for " << fAttack << " damage!" << std::endl;

					std::this_thread::sleep_for(std::chrono::milliseconds(200));  // Pause 0.2 sec

					// If Goblin 1 is alive
					if (goblin1.getHealth() > 0) {
						// Output that Goblin 3 is beginning a counter attack
						std::cout << "\n  [Goblin 1 begins their counter attack.]" << std::endl;

						// Set integer variable 'agilityModifier' to 0 (to reset upon loop repeat)
						agilityModifier = 0;

						// Set integer variable 'randomDodge' to a random number of 1-100
						//   (for matching usage to determine player's dodge percentage)
						randomDodge = (1 + (rand() % ((100 - 1) + 1)));

						// Set boolean 'fullDodge' to false (to reset upon loop repeat)
						//   (this is used to break out of the loop
						//    if the first dodge check is a success)
						fullDodge = false;

						// 'numIncrease' & 'numIncrease2' are used as the two values
						// for the range of the dodge rate checker, used with 'randomDodge'

						// Set integer 'numIncrease' to 1 and integer
						// 'numIncrease2' to the player's dodge rate times 100
						numIncrease = 1;
						numIncrease2 = (int)(dodgeRate * 100);  // 0.01-1 (decimal) to 1-100 (whole #)

						// FIRST DODGE CHECK:
						// If the dodge check is a success
						//   (randomized num of 1-100 is within the
						//    starting range of the dodge rate checker)
						if (randomDodge > numIncrease && randomDodge <= numIncrease2) {
							// Set boolean 'fullDodge' to true
							fullDodge = true;
						}
						// Otherwise (If the dodge check failed)...
						else {
							// Increase the range of the
							// dodge rate checker up one notch
							numIncrease = numIncrease2;
							numIncrease2 = numIncrease2 + 20;
						}

						// Loop five times (after 5 times, dodge rate is guaranteed 0%)
						for (unsigned i = 0;i < 5;++i) {
							// If boolean 'fullDodge' is true (if first check above succeeded)
							if (fullDodge == true) {
								// Break out of the loop
								break;
							}

							// If the modifier is between 0 and 1 (but not actually 1)
							if (agilityModifier < 1 && agilityModifier >= 0) {
								// Increase the modifier by 0.25 (-25% damage avoided)
								agilityModifier = agilityModifier + 0.25;  // Dodges: 100% - 75% - 50% - 25% - 0%
							}
							// If the modifier is equal to 1 (0% damage avoided)
							if (agilityModifier == 1.0) {
								// Break out of the loop
								break;
							}

							// If 'numIncrease' or 'numIncrease2' reaches 100
							//   (the loop ran through all checks to 100%)
							if (numIncrease > 100 || numIncrease2 > 100) {
								// Break out of the loop
								break;
							}

							// NEXT DODGE CHECK:
							// If the dodge check is a success
							//   (randomized num of 1-100 is within the
							//    increased range of the dodge rate checker)
							if (randomDodge > numIncrease && randomDodge <= numIncrease2) {
								// Break out of the loop
								break;
							}

							// Increase the two values of the range of the dodge rate checker
							numIncrease = numIncrease + 20;
							numIncrease2 = numIncrease2 + 20;
						}

						// If the modifier is equal to 0 -- 100% damage avoided (0 x dmg = no dmg taken)
						if (agilityModifier == 0.0) {
							// Output that the player avoided 100% of Goblin 1's attack damage
							std::cout << "\n  You avoided Goblin 1's attack [" << fMobAttack1 << " DMG] with your agility!" << std::endl;
						}  // OR
						// If the modifier is equal to 1 -- 0% damage avoided (1 x dmg = full dmg taken)
						else if (agilityModifier == 1.0) {
							// Subtract 100% of Goblin 1's attack damage from the player's health
							player.setHealth(player.getHealth() - fMobAttack1);

							// Output that the player took 100% of Goblin 1's attack damage
							std::cout << "\n  Goblin 1 counter attacks for " << fMobAttack1 << " damage!" << std::endl;

							// Add the damage the player received to variable 'hpLost'
							//   (for output after the round ends)
							hpLost = (hpLost + fMobAttack1);
						}
						// Otherwise (If the modifier is more than 0 and less than 1 -- 0.25, 0.5, 0.75)...
						else {
							// Subtract Goblin 1's attack (minus the avoided damage) from the player's health
							//   - atk x 0.25 = 75% dmg avoided (Player gets damaged 25% of the enemy's dmg)
							//   - atk x 0.50 = 50% dmg avoided (Player gets damaged 50% of the enemy's dmg)
							//   - atk x 0.75 = 25% dmg avoided (Player gets damaged 75% of the enemy's dmg)
							player.setHealth(player.getHealth() - (fMobAttack1 * agilityModifier));

							// Output the % of damage the player negated and how much damage the player took
							std::cout << "\n  You have negated " << ((1 - agilityModifier) * 100) << "% of Goblin 1's attack damage [" << fMobAttack1 << " DMG] " <<
								"by maneuvering with your agility! You only take " << (fMobAttack1 * agilityModifier) << " damage!" << std::endl;

							// Add the damage the player received to variable 'hpLost'
							//   (for output after the round ends)
							hpLost = (hpLost + (fMobAttack1 * agilityModifier));
						}
					}

					// Otherwise (If Goblin 1 is dead)...
					else {
						// Output that Goblin 1 has died & how much experience the player receives
						std::cout << "\n  [Goblin 1 has perished.]\n  [EXP+" << goblin1.getEXP() << "]" << std::endl;
					}

					// If Goblin 2 is alive
					if (goblin2.getHealth() > 0) {
						// Output that the other goblins are beginning their attacks
						std::cout << "\n\n  [The other goblin begins their attack.]" << std::endl;

						// Set integer variable 'agilityModifier' to 0 (to reset upon loop repeat)
						agilityModifier = 0;

						// Set integer variable 'randomDodge' to a random number of 1-100
						//   (for matching usage to determine player's dodge percentage)
						randomDodge = (1 + (rand() % ((100 - 1) + 1)));

						// Set boolean 'fullDodge' to false (to reset upon loop repeat)
						//   (this is used to break out of the loop
						//    if the first dodge check is a success)
						fullDodge = false;

						// 'numIncrease' & 'numIncrease2' are used as the two values
						// for the range of the dodge rate checker, used with 'randomDodge'

						// Set integer 'numIncrease' to 1 and integer
						// 'numIncrease2' to the player's dodge rate times 100
						numIncrease = 1;
						numIncrease2 = (int)(dodgeRate * 100);  // 0.01-1 (decimal) to 1-100 (whole #)

						// FIRST DODGE CHECK:
						// If the dodge check is a success
						//   (randomized num of 1-100 is within the
						//    starting range of the dodge rate checker)
						if (randomDodge > numIncrease && randomDodge <= numIncrease2) {
							// Set boolean 'fullDodge' to true
							fullDodge = true;
						}
						// Otherwise (If the dodge check failed)...
						else {
							// Increase the range of the
							// dodge rate checker up one notch
							numIncrease = numIncrease2;
							numIncrease2 = numIncrease2 + 20;
						}

						// Loop five times (after 5 times, dodge rate is guaranteed 0%)
						for (unsigned i = 0;i < 5;++i) {
							// If boolean 'fullDodge' is true (if first check above succeeded)
							if (fullDodge == true) {
								// Break out of the loop
								break;
							}

							// If the modifier is between 0 and 1 (but not actually 1)
							if (agilityModifier < 1 && agilityModifier >= 0) {
								// Increase the modifier by 0.25 (-25% damage avoided)
								agilityModifier = agilityModifier + 0.25;  // Dodges: 100% - 75% - 50% - 25% - 0%
							}
							// If the modifier is equal to 1 (0% damage avoided)
							if (agilityModifier == 1.0) {
								// Break out of the loop
								break;
							}

							// If 'numIncrease' or 'numIncrease2' reaches 100
							//   (the loop ran through all checks to 100%)
							if (numIncrease > 100 || numIncrease2 > 100) {
								// Break out of the loop
								break;
							}

							// NEXT DODGE CHECK:
							// If the dodge check is a success
							//   (randomized num of 1-100 is within the
							//    increased range of the dodge rate checker)
							if (randomDodge > numIncrease && randomDodge <= numIncrease2) {
								// Break out of the loop
								break;
							}

							// Increase the two values of the range of the dodge rate checker
							numIncrease = numIncrease + 20;
							numIncrease2 = numIncrease2 + 20;
						}

						// If the modifier is equal to 0 -- 100% damage avoided (0 x dmg = no dmg taken)
						if (agilityModifier == 0.0) {
							// Output that the player avoided 100% of Goblin 2's attack damage
							std::cout << "\n  You avoided Goblin 2's attack [" << fMobAttack2 << " DMG] with your agility!" << std::endl;
						}  // OR
						// If the modifier is equal to 1 -- 0% damage avoided (1 x dmg = full dmg taken)
						else if (agilityModifier == 1.0) {
							// Subtract 100% of Goblin 2's attack damage from the player's health
							player.setHealth(player.getHealth() - fMobAttack2);

							// Output that the player took 100% of Goblin 2's attack damage
							std::cout << "\n  Goblin 2 attacks you for " << fMobAttack2 << " damage!" << std::endl;

							// Add the damage the player received to variable 'hpLost'
							//   (for output after the round ends)
							hpLost = (hpLost + fMobAttack2);
						}
						// Otherwise (If the modifier is more than 0 and less than 1 -- 0.25, 0.5, 0.75)...
						else {
							// Subtract Goblin 2's attack (minus the avoided damage) from the player's health
							//   - atk x 0.25 = 75% dmg avoided (Player gets damaged 25% of the enemy's dmg)
							//   - atk x 0.50 = 50% dmg avoided (Player gets damaged 50% of the enemy's dmg)
							//   - atk x 0.75 = 25% dmg avoided (Player gets damaged 75% of the enemy's dmg)
							player.setHealth(player.getHealth() - (fMobAttack2 * agilityModifier));

							// Output the % of damage the player negated and how much damage the player took
							std::cout << "\n  You have negated " << ((1 - agilityModifier) * 100) << "% of Goblin 2's attack damage [" << fMobAttack2 << " DMG] " <<
								"by maneuvering with your agility! You only take " << (fMobAttack2 * agilityModifier) << " damage!" << std::endl;

							// Add the damage the player received to variable 'hpLost'
							//   (for output after the round ends)
							hpLost = (hpLost + (fMobAttack2 * agilityModifier));
						}
					}

					// Otherwise (If Goblin 2 is dead)...
					else {
						// Output that Goblin 2 has died & how much experience the player receives
						std::cout << "\n  [Goblin 2 has perished.]\n  [EXP+" << goblin2.getEXP() << "]" << std::endl;
					}

					// Output the amount of health the player lost after the round
					std::cout << "\n\n  [-" << hpLost << " HP]" << std::endl;

					std::this_thread::sleep_for(std::chrono::milliseconds(350));  // Pause 0.35 sec
				}
			} while (goblin1.getHealth() > 0 && player.getHealth() > 0);
			// Keep repeating the block of code until Goblin 1 or the player dies

			// If any of the Enemys' health has dropped below zero,
			// set their health to 0 (you can't have negative health)
			if (goblin1.getHealth() < 0) {
				goblin1.setHealth(0);
			}
			if (goblin2.getHealth() < 0) {
				goblin2.setHealth(0);
			}

			// If the player has died
			if (player.getHealth() <= 0) {
				// Run the Death() method
				Death();
				// Terminate the program
				exit(0);
			}

			// Output the health status of player & all enemies
			std::cout << "\n\n  ###############################\n  HP:       (" << player.getHealth() << "/" << player.getMaxHealth() << ")\n  " <<
				"Goblin 1: (" << goblin1.getHealth() << "/" << goblin1.getMaxHealth() << ")\n  " <<
				"Goblin 2: (" << goblin2.getHealth() << "/" << goblin2.getMaxHealth() << ")\n  " <<
				"Goblin 3: (" << goblin3.getHealth() << "/" << goblin3.getMaxHealth() << ")\n  " <<
				"###############################" << std::endl;

			// Update the Character object 'player' by calculating
			// the updated experience from Goblin 1's death
			player = CalculateEXP(player, goblin1);

			// Output to the player that there is only one enemy remaining
			std::cout << "\n\n  There is only one goblin remaining. You're almost there!" << std::endl;

			/*  ===================================================================================  */
			/*  ================================                   ================================  */
			/*  ================================    LAST BATTLE    ================================  */
			/*  ================================                   ================================  */
			/*  ===================================================================================  */

			// ATTACK GOBLIN 2

			// Block of code to loop while Goblin 2 is still alive
			do {
				// Output health status of player & all enemies
				std::cout << "\n\n  ###############################\n  HP:       (" << player.getHealth() << "/" << player.getMaxHealth() << ")\n  " <<
					"Goblin 1: (" << goblin1.getHealth() << "/" << goblin1.getMaxHealth() << ")\n  " <<
					"Goblin 2: (" << goblin2.getHealth() << "/" << goblin2.getMaxHealth() << ")\n  " <<
					"Goblin 3: (" << goblin3.getHealth() << "/" << goblin3.getMaxHealth() << ")\n  " <<
					"###############################" << std::endl;

				std::this_thread::sleep_for(std::chrono::milliseconds(200));  // Pause 0.2 sec

				// Ask the player to either Attack or Retreat
				std::cout << "\n  Attack or Retreat? ";
				// Get user input
				option = choiceYesNo("Attack", "Retreat");

				clear();  // Clear console window

				// If 'option' is false -- player chose "Retreat" ('R'/'r')
				if (option == false) {
					// If a random number of 1-3 results as 1 (33% chance)
					if ((rand() % 3) == 1) {
						// Output successful escape notification
						std::cout << "\n  You have successfully escaped." << std::endl;

						// Set the health of the enemy to 0
						goblin2.setHealth(0);

						// Go to the location of 'END:' and player from there
						//   (exits the loop & ends the battle)
						goto END;
					}
					// Otherwise (If the random number result is not 1 -- the 66% chance of failed retreat passes)...
					else {
						std::this_thread::sleep_for(std::chrono::milliseconds(200));  // Pause 0.2 sec

						// Output failed escape notification
						std::cout << "\n  Retreat failed." << std::endl;

						// If Goblin 2 is still alive
						if (goblin2.getHealth() > 0) {
							// Output free attack notification
							std::cout << "\n  Goblin 2 got in a free attack. [-10 HP]" << std::endl;

							// Subtract 10 health from the player
							player.setHealth(player.getHealth() - 10);
						}
						// Set option to true
						//   (so that the player attack occurs next)
						option = true;
					}
				}
				// If 'option' is true -- player chose "Attack" ('A'/'a') or failed to retreat
				if (option == true) {
					std::this_thread::sleep_for(std::chrono::milliseconds(350));  // Pause 0.35 sec

					// Set the player's lost health variable, 'hpLost', to 0 (to reset upon loop repeat)
					hpLost = 0;

					// Randomize player attack damage between: 1/2 to full base atk damage
					attack = ((player.getDamage() / 2) + (rand() % (player.getDamage() - (player.getDamage() / 2) + 1)));
					// Randomize enemy attack damage between: 1/2 to full base atk damage
					mobAttack2 = ((goblin2.getDamage() / 2) + (rand() % (goblin2.getDamage() - (goblin2.getDamage() / 2) + 1)));

					// Modify player attack damage to subtract 1/2 DEF stat value multiplied by level
					//   (higher defense & higher level = less damage taken)
					fAttack = attack - ((goblin2.getLevel() * goblin2.getDEF()) / 2);
					// Modify enemy attack damage to subtract 1/2 DEF stat value multiplied by level
					//   (higher defense & higher level = less damage taken)
					fMobAttack2 = mobAttack2 - ((player.getLevel() * (player.getDEF() + player.getDEFBoost())) / 2);

					// If any attack damages are less than zero...
					// Set them to zero (there can't be negative damage)
					if (fAttack < 0) {
						fAttack = 0;
					}
					if (fMobAttack2 < 0) {
						fMobAttack2 = 0;
					}

					// Set the player's dodge rate to double variable 'dodgeRate'
					//   (for dodge rate percentage calculations)
					dodgeRate = player.getDodgeRate();

					// Subtract Goblin 2's health by the player's attack damage
					goblin2.setHealth(goblin2.getHealth() - fAttack);

					// Output attack notification
					std::cout << "\n  You attack Goblin 2 for " << fAttack << " damage!" << std::endl;

					std::this_thread::sleep_for(std::chrono::milliseconds(200));  // Pause 0.2 sec

					// If Goblin 2 is alive
					if (goblin2.getHealth() > 0) {
						// Output that Goblin 2 is beginning a counter attack
						std::cout << "\n  [Goblin 2 begins their counter attack.]" << std::endl;

						// Set integer variable 'agilityModifier' to 0 (to reset upon loop repeat)
						agilityModifier = 0;

						// Set integer variable 'randomDodge' to a random number of 1-100
						//   (for matching usage to determine player's dodge percentage)
						randomDodge = (1 + (rand() % ((100 - 1) + 1)));

						// Set boolean 'fullDodge' to false (to reset upon loop repeat)
						//   (this is used to break out of the loop
						//    if the first dodge check is a success)
						fullDodge = false;

						// 'numIncrease' & 'numIncrease2' are used as the two values
						// for the range of the dodge rate checker, used with 'randomDodge'

						// Set integer 'numIncrease' to 1 and
						// integer 'numIncrease2' to the player's dodge rate times 100
						numIncrease = 1;
						numIncrease2 = (int)(dodgeRate * 100);  // 0.1-1 (decimal) to 1-100 (whole #)

						// FIRST DODGE CHECK:
						// If the dodge check is a success
						//   (randomized num of 1-100 is within the
						//    starting range of the dodge rate checker)
						if (randomDodge > numIncrease && randomDodge <= numIncrease2) {
							// Set boolean 'fullDodge' to true
							fullDodge = true;
						}
						// Otherwise (If the dodge check failed)...
						else {
							// Increase the range of the
							// dodge rate checker up one notch
							numIncrease = numIncrease2;
							numIncrease2 = numIncrease2 + 20;
						}

						// Loop five times (after 5 times, dodge rate is guaranteed 0%)
						for (unsigned i = 0;i < 5;++i) {
							// If boolean 'fullDodge' is true (if first check above succeeded)
							if (fullDodge == true) {
								// Break out of the loop
								break;
							}

							// If the modifier is between 0 and 1 (but not actually 1)
							if (agilityModifier < 1 && agilityModifier >= 0) {
								// Increase the modifier by 0.25 (-25% damage avoided)
								agilityModifier = agilityModifier + 0.25;  // Dodges: 100% - 75% - 50% - 25% - 0%
							}
							// If the modifier is equal to 1 (0% damage avoided)
							if (agilityModifier == 1.0) {
								// Break out of the loop
								break;
							}

							// If 'numIncrease' or 'numIncrease2' reaches 100
							//   (the loop ran through all checks to 100%)
							if (numIncrease > 100 || numIncrease2 > 100) {
								// Break out of the loop
								break;
							}

							// NEXT DODGE CHECK:
							// If the dodge check is a success
							//   (randomized num of 1-100 is within the
							//    increased range of the dodge rate checker)
							if (randomDodge > numIncrease && randomDodge <= numIncrease2) {
								// Break out of the loop
								break;
							}

							// Increase the two values of the range of the dodge rate checker
							numIncrease = numIncrease + 20;
							numIncrease2 = numIncrease2 + 20;
						}

						// If the modifier is equal to 0 -- 100% damage avoided (0 x dmg = no dmg taken)
						if (agilityModifier == 0.0) {
							// Output that the player avoided 100% of Goblin 2's attack damage
							std::cout << "\n  You avoided Goblin 2's attack [" << fMobAttack2 << " DMG] with your agility!" << std::endl;
						}  // OR
						// If the modifier is equal to 1 -- 0% damage avoided (1 x dmg = full dmg taken)
						else if (agilityModifier == 1.0) {
							// Subtract 100% of Goblin 2's attack damage from the player's health
							player.setHealth(player.getHealth() - fMobAttack2);

							// Output that the player took 100% of Goblin 2's attack damage
							std::cout << "\n  Goblin 2 counter attacks for " << fMobAttack2 << " damage!" << std::endl;

							// Add the damage the player received to variable 'hpLost'
							//   (for output after the round ends)
							hpLost = (hpLost + fMobAttack2);
						}
						// Otherwise (If the modifier is more than 0 and less than 1 -- 0.25, 0.5, 0.75)...
						else {
							// Subtract Goblin 3's attack (minus the avoided damage) from the player's health
							//   - atk x 0.25 = 75% dmg avoided (Player gets damaged 25% of the enemy's dmg)
							//   - atk x 0.50 = 50% dmg avoided (Player gets damaged 50% of the enemy's dmg)
							//   - atk x 0.75 = 25% dmg avoided (Player gets damaged 75% of the enemy's dmg)
							player.setHealth(player.getHealth() - (fMobAttack2 * agilityModifier));

							// Output the % of damage the player negated and how much the player took
							std::cout << "\n  You have negated " << ((1 - agilityModifier) * 100) << "% of Goblin 2's attack damage [" << fMobAttack2 << " DMG] " <<
								"by maneuvering with your agility! You only take " << (fMobAttack2 * agilityModifier) << " damage!" << std::endl;

							// Add the damage the player received to variable 'hpLost'
							//   (for output after the round ends)
							hpLost = (hpLost + (fMobAttack2 * agilityModifier));
						}
					}

					// Otherwise (If Goblin 2 is dead)...
					else {
						// Output that Goblin 2 has died & how much experience the player receives
						std::cout << "\n  [Goblin 2 has perished.]\n  [EXP+" << goblin2.getEXP() << "]" << std::endl;
					}

					// If Goblin 2 is alive
					if (goblin2.getHealth() > 0) {
						// Output the amount of health lost after the round
						std::cout << "\n\n  [-" << hpLost << " HP]" << std::endl;
					}

					std::this_thread::sleep_for(std::chrono::milliseconds(350));  // Pause 0.35 sec
				}
			} while (goblin2.getHealth() > 0 && player.getHealth() > 0);
			// Keep repeating the block of code until Goblin 2 or the player dies

			// If the Enemy's health has dropped below zero, set
			// their health to 0 (you can't have negative health)
			if (goblin2.getHealth() < 0) {
				goblin2.setHealth(0);
			}

			// If the player has died
			if (player.getHealth() <= 0) {
				// Run the Death() method
				Death();
				// Terminate the program
				exit(0);
			}

			// Output the health status of player & all enemies
			std::cout << "\n\n  ###############################\n  HP:       (" << player.getHealth() << "/" << player.getMaxHealth() << ")\n  " <<
				"Goblin 1: (" << goblin1.getHealth() << "/" << goblin1.getMaxHealth() << ")\n  " <<
				"Goblin 2: (" << goblin2.getHealth() << "/" << goblin2.getMaxHealth() << ")\n  " <<
				"Goblin 3: (" << goblin3.getHealth() << "/" << goblin3.getMaxHealth() << ")\n  " <<
				"###############################" << std::endl;

			// Update the Character object 'player' by calculating
			// the updated experience from Goblin 2's death
			player = CalculateEXP(player, goblin2);

			// Output completion notification
			std::cout << "\n\n  Congratulations, you have killed the goblins!!\n  What now?" << std::endl;

		}

		// If user chose Goblin 2 ('B'/'b')
		// ATTACK GOBLIN 2 -- GOBLIN 1 STILL ALIVE
		else if (optionChar == 'B') {
			// Block of code to loop while Goblin 2 is still alive
			do {
				// Output health status of player & all enemies
				std::cout << "\n\n  ###############################\n  HP:       (" << player.getHealth() << "/" << player.getMaxHealth() << ")\n  " <<
					"Goblin 1: (" << goblin1.getHealth() << "/" << goblin1.getMaxHealth() << ")\n  " <<
					"Goblin 2: (" << goblin2.getHealth() << "/" << goblin2.getMaxHealth() << ")\n  " <<
					"Goblin 3: (" << goblin3.getHealth() << "/" << goblin3.getMaxHealth() << ")\n  " <<
					"###############################" << std::endl;

				std::this_thread::sleep_for(std::chrono::milliseconds(200));  // Pause 0.2 sec

				// Ask the player to either Attack or Retreat
				std::cout << "\n  Attack or Retreat? ";
				// Get user input
				option = choiceYesNo("Attack", "Retreat");

				clear();  // Clear console window

				// If 'option' is false -- player chose "Retreat" ('R'/'r')
				if (option == false) {
					// If a random number of 1-3 results as 1 (33% chance)
					if ((rand() % 3) == 1) {
						// Output successful escape notification
						std::cout << "\n  You have successfully escaped." << std::endl;

						// Set the health of all remaining enemies to 0
						goblin1.setHealth(0);
						goblin2.setHealth(0);

						// Go to the location of 'END:' and play from there
						//   (exits the loop & ends the battle)
						goto END;
					}
					// Otherwise (If the random number result is not 1 -- the 66% chance of failed retreat passes)...
					else {
						std::this_thread::sleep_for(std::chrono::milliseconds(200));  // Pause 0.2 sec

						// Output failed escape notification
						std::cout << "\n  Retreat failed." << std::endl;

						// If Goblin 1 is still alive
						if (goblin1.getHealth() > 0) {
							// Output free attack notification
							std::cout << "\n  Goblin 1 got in a free attack. [-10 HP]" << std::endl;

							// Subtract 10 health from the player
							player.setHealth(player.getHealth() - 10);
						}
						// If Goblin 2 is still alive
						if (goblin2.getHealth() > 0) {
							// Output free attack notification
							std::cout << "  Goblin 2 got in a free attack. [-10 HP]" << std::endl;

							// Subtract 10 health from the player
							player.setHealth(player.getHealth() - 10);
						}
						// Set option to true
						//   (so that the player attack occurs next)
						option = true;
					}
				}
				// If 'option' is true -- player chose "Attack" ('A'/'a') or failed retreat
				if (option == true) {
					std::this_thread::sleep_for(std::chrono::milliseconds(350));  // Pause 0.35 sec

					// Set the player's lost health variable, 'hpLost', to 0 (to reset upon loop repeat)
					hpLost = 0;

					// Randomize player attack damage between: 1/2 to full base atk damage
					attack = ((player.getDamage() / 2) + (rand() % (player.getDamage() - (player.getDamage() / 2) + 1)));
					// Randomize enemy attack damage between: 1/2 to full base atk damage
					mobAttack1 = ((goblin1.getDamage() / 2) + (rand() % (goblin1.getDamage() - (goblin1.getDamage() / 2) + 1)));
					mobAttack2 = ((goblin2.getDamage() / 2) + (rand() % (goblin2.getDamage() - (goblin2.getDamage() / 2) + 1)));

					// Modify player attack damage to subtract 1/2 DEF stat value multiplied by level
					//   (higher defense & higher level = less damage taken)
					fAttack = attack - ((goblin2.getLevel() * goblin2.getDEF()) / 2);
					// Modify enemy attack damage to subtract 1/2 DEF stat value multiplied by level
					//   (higher defense & higher level = less damage taken)
					fMobAttack1 = mobAttack1 - ((player.getLevel() * (player.getDEF() + player.getDEFBoost())) / 2);
					fMobAttack2 = mobAttack2 - ((player.getLevel() * (player.getDEF() + player.getDEFBoost())) / 2);

					// If any attack damages are less than zero...
					// Set them to zero (there can't be negative damage)
					if (fAttack < 0) {
						fAttack = 0;
					}
					if (fMobAttack1 < 0) {
						fMobAttack1 = 0;
					}
					if (fMobAttack2 < 0) {
						fMobAttack2 = 0;
					}

					// Set the player's dodge rate to double variable 'dodgeRate'
					//   (for dodge rate percentage calculations)
					dodgeRate = player.getDodgeRate();

					// Subtract Goblin 2's health by the player's attack damage
					goblin2.setHealth(goblin2.getHealth() - fAttack);

					// Output attack notification
					std::cout << "\n  You attack Goblin 2 for " << fAttack << " damage!" << std::endl;

					std::this_thread::sleep_for(std::chrono::milliseconds(200));  // Pause 0.2 sec

					// If Goblin 2 is alive
					if (goblin2.getHealth() > 0) {
						// Output that Goblin 2 is beginning a counter attack
						std::cout << "\n  [Goblin 2 begins their counter attack.]" << std::endl;

						// Set integer variable 'agilityModifier' to 0 (to reset upon loop repeat)
						agilityModifier = 0;

						// Set integer variable 'randomDodge' to a random number of 1-100
						//   (for matching usage to determine player's dodge percentage)
						randomDodge = (1 + (rand() % ((100 - 1) + 1)));

						// Set boolean 'fullDodge' to false (to reset upon loop repeat)
						//   (this is used to break out of the loop
						//    if the first dodge check is a success)
						fullDodge = false;

						// 'numIncrease' & 'numIncrease2' are used as the two values
						// for the range of the dodge rate checker, used with 'randomDodge'

						// Set integer 'numIncrease' to 1 and
						// integer 'numIncrease2' to the player's dodge rate times 100
						numIncrease = 1;
						numIncrease2 = (int)(dodgeRate * 100);

						// FIRST DODGE CHECK:
						// If the dodge check is a success
						//   (randomized num of 1-100 is within the
						//    starting range of the dodge rate checker)
						if (randomDodge > numIncrease && randomDodge <= numIncrease2) {
							// Set boolean 'fullDodge' to true
							fullDodge = true;
						}
						// Otherwise (If the dodge check failed)...
						else {
							// Increase the range of the
							// dodge rate checker up one notch
							numIncrease = numIncrease2;
							numIncrease2 = numIncrease2 + 20;
						}

						// Loop five times (after 5 times, dodge rate is guaranteed 0%)
						for (unsigned i = 0;i < 5;++i) {
							// If boolean 'fullDodge' is true (if first check above succeeded)
							if (fullDodge == true) {
								// Break out of the loop
								break;
							}

							// If the modifier is between 0 and 1 (but not actually 1)
							if (agilityModifier < 1 && agilityModifier >= 0) {
								// Increase the modifier by 0.25 (-25% damage avoided)
								agilityModifier = agilityModifier + 0.25;  // Dodges: 100% - 75% - 50% - 25% - 0%
							}
							// If the modifier is equal to 1 (0% damage avoided)
							if (agilityModifier == 1.0) {
								// Break out of the loop
								break;
							}

							// If 'numIncrease' or 'numIncrease2' reaches 100
							//   (the loop ran through all checks to 100%)
							if (numIncrease > 100 || numIncrease2 > 100) {
								// Break out of the loop
								break;
							}

							// NEXT DODGE CHECK:
							// If the dodge check is a success
							//   (randomized num of 1-100 is within the
							//    increased range of the dodge rate checker)
							if (randomDodge > numIncrease && randomDodge <= numIncrease2) {
								// Break out of the loop
								break;
							}

							// Increase the two values of the range of the dodge rate checker
							numIncrease = numIncrease + 20;
							numIncrease2 = numIncrease2 + 20;
						}

						// If the modifier is equal to 0 -- 100% damage avoided (0 x dmg = no dmg taken)
						if (agilityModifier == 0.0) {
							// Output that the player avoided 100% of Goblin 2's attack damage
							std::cout << "\n  You avoided Goblin 2's attack [" << fMobAttack2 << " DMG] with your agility!" << std::endl;
						}  // OR
						// If the modifier is equal to 1 -- 0% damage avoided (1 x dmg = full dmg taken)
						else if (agilityModifier == 1.0) {
							// Subtract 100% of Goblin 2's attack damage from the player's health
							player.setHealth(player.getHealth() - fMobAttack2);

							// Output that the player took 100% of Goblin 2's attack damage
							std::cout << "\n  Goblin 2 counter attacks for " << fMobAttack2 << " damage!" << std::endl;

							// Add the damage the player received to variable 'hpLost'
							//   (for output after the round ends)
							hpLost = (hpLost + fMobAttack2);
						}
						// Otherwise (If the modifier is more than 0 and less than 1 -- 0.25, 0.5, 0.75)...
						else {
							// Subtract Goblin 3's attack (minus the avoided damage) from the player's health
							//   - atk x 0.25 = 75% dmg avoided (Player gets damaged 25% of the enemy's dmg)
							//   - atk x 0.50 = 50% dmg avoided (Player gets damaged 50% of the enemy's dmg)
							//   - atk x 0.75 = 25% dmg avoided (Player gets damaged 75% of the enemy's dmg)
							player.setHealth(player.getHealth() - (fMobAttack2 * agilityModifier));

							// Output the % of damage the player negated and how much damage the player took
							std::cout << "\n  You have negated " << ((1 - agilityModifier) * 100) << "% of Goblin 2's attack damage [" << fMobAttack2 << " DMG] " <<
								"by maneuvering with your agility! You only take " << (fMobAttack2 * agilityModifier) << " damage!" << std::endl;

							// Add the damage the player received to variable 'hpLost'
							//   (for output after the round ends)
							hpLost = (hpLost + (fMobAttack2 * agilityModifier));
						}
					}

					// Otherwise (If Goblin 2 is dead)...
					else {
						// Output that Goblin 2 has died & how much experience the player receives
						std::cout << "\n  [Goblin 2 has perished.]\n  [EXP+" << goblin2.getEXP() << "]" << std::endl;
					}

					// If Goblin 1 is alive
					if (goblin1.getHealth() > 0) {
						// Output that the other goblins are beginning their attacks
						std::cout << "\n\n  [The other goblin begins their attack.]" << std::endl;

						// Set integer variable 'agilityModifier' is 0 (to reset upon loop repeat)
						agilityModifier = 0;

						// Set integer variable 'randomDodge' to a random number of 1-100
						//   (for matching usage to determine player's dodge percentage)
						randomDodge = (1 + (rand() % ((100 - 1) + 1)));

						// Set boolean 'fullDodge' to false (to reset upon loop repeat)
						//   (this is used to break out of the loop
						//    if the first dodge check is a success)
						fullDodge = false;

						// 'numIncrease' & 'numIncrease2' are used as the two values
						// for the range of the dodge rate checker, used with 'randomDodge'

						// Set integer 'numIncrease' to 1 and
						// integer 'numIncrease2' to the player's dodge rate times 100
						numIncrease = 1;
						numIncrease2 = (int)(dodgeRate * 100);

						// FIRST DODGE CHECK:
						// If the dodge check is a success
						//   (randomized num of 1-100 is within the
						//    starting range of the dodge rate checker)
						if (randomDodge > numIncrease && randomDodge <= numIncrease2) {
							// Set boolean 'fullDodge' to true
							fullDodge = true;
						}
						// Otherwise (If the dodge check failed)...
						else {
							// Increase the range of the
							// dodge rate checker up one notch
							numIncrease = numIncrease2;
							numIncrease2 = numIncrease2 + 20;
						}

						// Loop five times (after 5 times, dodge rate is guaranteed 0%)
						for (unsigned i = 0;i < 5;++i) {
							// If boolean 'fullDodge' is true (if first check above succeeded)
							if (fullDodge == true) {
								// Break out of the loop
								break;
							}

							// If the modifier is between 0 and 1 (but not actually 1)
							if (agilityModifier < 1 && agilityModifier >= 0) {
								// Increase the modifier by 0.25 (-25% damage avoided)
								agilityModifier = agilityModifier + 0.25;  // Dodges: 100% - 75% - 50% - 25% - 0%
							}
							// If the modifier is equal to 1 (0% damage avoided)
							if (agilityModifier == 1.0) {
								// Break out of the loop
								break;
							}

							// If 'numIncrease' or 'numIncrease2' reaches 100
							//   (the loop ran through all checks to 100%)
							if (numIncrease > 100 || numIncrease2 > 100) {
								// Break out of the loop
								break;
							}

							// NEXT DODGE CHECK:
							// If the dodge check is a success
							//   (randomized num of 1-100 is within the
							//    increased range of the dodge rate checker)
							if (randomDodge > numIncrease && randomDodge <= numIncrease2) {
								// Break out of the loop
								break;
							}

							// Increase the two values of the range of the dodge rate checker
							numIncrease = numIncrease + 20;
							numIncrease2 = numIncrease2 + 20;
						}

						// If the modifier is equal to 0 -- 100% damage avoided (0 x dmg = no dmg taken)
						if (agilityModifier == 0.0) {
							// Output that the player avoided 100% of Goblin 1's attack damage
							std::cout << "\n  You avoided Goblin 1's attack [" << fMobAttack1 << " DMG] with your agility!" << std::endl;
						}  // OR
						// If the modifier is equal to 1 -- 0% damage avoided (1 x dmg = full dmg taken)
						else if (agilityModifier == 1.0) {
							// Subtract 100% of Goblin 1's attack damage from the player's health
							player.setHealth(player.getHealth() - fMobAttack1);

							// Output that the player took 100% of Goblin 1's attack damage
							std::cout << "\n  Goblin 1 attacks you for " << fMobAttack1 << " damage!" << std::endl;

							// Add the damage the player received to variable 'hpLost'
							//   (for output after the round ends)
							hpLost = (hpLost + fMobAttack1);
						}
						// Otherwise (If the modifier is more than 0 and less than 1 -- 0.25, 0.5, 0.75)...
						else {
							// Subtract Goblin 1's attack (minus the avoided damage) from the player's health
							//   - atk x 0.25 = 75% dmg avoided (Player gets damaged 25% of the enemy's dmg)
							//   - atk x 0.50 = 50% dmg avoided (Player gets damaged 50% of the enemy's dmg)
							//   - atk x 0.75 = 25% dmg avoided (Player gets damaged 75% of the enemy's dmg)
							player.setHealth(player.getHealth() - (fMobAttack1 * agilityModifier));

							// Output the % of damage the player negated and how much damage the player took
							std::cout << "\n  You have negated " << ((1 - agilityModifier) * 100) << "% of Goblin 1's attack damage [" << fMobAttack1 << " DMG] " <<
								"by maneuvering with your agility! You only take " << (fMobAttack1 * agilityModifier) << " damage!" << std::endl;

							// Add the damage the player received to variable 'hpLost'
							//   (for output after the round ends)
							hpLost = (hpLost + (fMobAttack1 * agilityModifier));
						}
					}

					// Otherwise (If Goblin 1 is dead)...
					else {
						// Output that Goblin 1 has died & how much experience the player receives
						std::cout << "\n  [Goblin 1 has perished.]\n  [EXP+" << goblin1.getEXP() << "]" << std::endl;
					}

					// Output the amount of health the player lost after the round
					std::cout << "\n\n  [-" << hpLost << " HP]" << std::endl;

					std::this_thread::sleep_for(std::chrono::milliseconds(350));  // Pause 0.35 sec
				}
			} while (goblin2.getHealth() > 0 && player.getHealth() > 0);
			// Keep repeating the block of code until Goblin 2 or the player dies

			// If any of the Enemys' health has dropped below zero,
			// set their health to 0 (you can't have negative health)
			if (goblin1.getHealth() < 0) {
				goblin1.setHealth(0);
			}
			if (goblin2.getHealth() < 0) {
				goblin2.setHealth(0);
			}

			// If the player has died
			if (player.getHealth() <= 0) {
				// Run the Death() method
				Death();
				// Terminate the program
				exit(0);
			}

			// Output the health status of player & all enemies
			std::cout << "\n\n  ###############################\n  HP:       (" << player.getHealth() << "/" << player.getMaxHealth() << ")\n  " <<
				"Goblin 1: (" << goblin1.getHealth() << "/" << goblin1.getMaxHealth() << ")\n  " <<
				"Goblin 2: (" << goblin2.getHealth() << "/" << goblin2.getMaxHealth() << ")\n  " <<
				"Goblin 3: (" << goblin3.getHealth() << "/" << goblin3.getMaxHealth() << ")\n  " <<
				"###############################" << std::endl;

			// Update the Character object 'player' by calculating
			// the updated experience from Goblin 2's death
			player = CalculateEXP(player, goblin2);

			// Output to the player that there is only one enemy remaining
			std::cout << "\n\n  There is only one goblin remaining. You're almost there!" << std::endl;

			/*  ===================================================================================  */
			/*  ================================                   ================================  */
			/*  ================================    LAST BATTLE    ================================  */
			/*  ================================                   ================================  */
			/*  ===================================================================================  */

			// ATTACK GOBLIN 1

			// Block of code to loop while Goblin 1 is still alive
			do {
				// Output health status of player & all enemies
				std::cout << "\n\n  ###############################\n  HP:       (" << player.getHealth() << "/" << player.getMaxHealth() << ")\n  " <<
					"Goblin 1: (" << goblin1.getHealth() << "/" << goblin1.getMaxHealth() << ")\n  " <<
					"Goblin 2: (" << goblin2.getHealth() << "/" << goblin2.getMaxHealth() << ")\n  " <<
					"Goblin 3: (" << goblin3.getHealth() << "/" << goblin3.getMaxHealth() << ")\n  " <<
					"###############################" << std::endl;

				std::this_thread::sleep_for(std::chrono::milliseconds(200));  // Pause 0.2 sec

				// Ask the player to either Attack or Retreat
				std::cout << "\n  Attack or Retreat? ";
				// Get user input
				option = choiceYesNo("Attack", "Retreat");

				clear();  // Clear console window

				// If 'option' is false -- player chose "Retreat" ('R'/'r')
				if (option == false) {
					// If a random number of 1-3 results as 1 (33% chance)
					if ((rand() % 3) == 1) {
						// Output successful escape notification
						std::cout << "\n  You have successfully escaped." << std::endl;

						// Set the health of the enemy to 0
						goblin1.setHealth(0);

						// Go to the location of 'END:' and play from there
						//   (exits the loop & ends the battle)
						goto END;
					}
					// Otherwise (If the random number result is not 1 -- the 66% chance of failed retreat passes)...
					else {
						std::this_thread::sleep_for(std::chrono::milliseconds(200));  // Pause 0.2 sec

						// Output failed escape notification
						std::cout << "\n  Retreat failed." << std::endl;

						// If Goblin 1 is still alive
						if (goblin1.getHealth() > 0) {
							// Output free attack notification
							std::cout << "\n  Goblin 1 got in a free attack. [-10 HP]" << std::endl;

							// Subtract 10 health from the player
							player.setHealth(player.getHealth() - 10);
						}
						// Set option to true
						//   (so that the player attack occurs next)
						option = true;
					}
				}
				// If 'option' is true -- player chose "Attack" ('A'/'a') or failed to retreat
				if (option == true) {
					std::this_thread::sleep_for(std::chrono::milliseconds(350));  // Pause 0.35 sec

					// Set the player's lost health variable, 'hpLost', to 0 (to reset upon loop repeat)
					hpLost = 0;

					// Randomize player attack damage between: 1/2 to full base atk damage
					attack = ((player.getDamage() / 2) + (rand() % (player.getDamage() - (player.getDamage() / 2) + 1)));
					// Randomize enemy attack damage between: 1/2 to full base atk damage
					mobAttack1 = ((goblin1.getDamage() / 2) + (rand() % (goblin1.getDamage() - (goblin1.getDamage() / 2) + 1)));

					// Modify player attack damage to subtract 1/2 DEF stat value multiplied by level
					//   (higher defense & higher level = less damage taken)
					fAttack = attack - ((goblin1.getLevel() * goblin1.getDEF()) / 2);
					// Modify enemy attack damage to subtract 1/2 DEF stat value multiplied by level
					//   (higher defense & higher level = less damage taken)
					fMobAttack1 = mobAttack1 - ((player.getLevel() * (player.getDEF() + player.getDEFBoost())) / 2);

					// If any attack damages are less than zero...
					// Set them to zero (there can't be negative damage)
					if (fAttack < 0) {
						fAttack = 0;
					}
					if (fMobAttack1 < 0) {
						fMobAttack1 = 0;
					}

					// Set the player's dodge rate to double variable 'dodgeRate'
					//   (for dodge rate percentage calculations)
					dodgeRate = player.getDodgeRate();

					// Subtract Goblin 1's health by the player's attack damage
					goblin1.setHealth(goblin1.getHealth() - fAttack);

					// Output attack notification
					std::cout << "\n  You attack Goblin 1 for " << fAttack << " damage!" << std::endl;

					std::this_thread::sleep_for(std::chrono::milliseconds(200));  // Pause 0.2 sec

					// If Goblin 1 is alive
					if (goblin1.getHealth() > 0) {
						// Output that Goblin 1 is beginning a counter attack
						std::cout << "\n  [Goblin 1 begins their counter attack.]" << std::endl;

						// Set integer variable 'agilityModifier' to 0 (to reset upon loop repeat)
						agilityModifier = 0;

						// Set integer variable 'randomDodge' to a random number of 1-100
						//   (for matching usage to determine player's dodge percentage)
						randomDodge = (1 + (rand() % ((100 - 1) + 1)));

						// Set boolean 'fullDodge' to false (to reset upon loop repeat)
						//   (this is used to break out of the loop
						//    if the first dodge check is a success)
						fullDodge = false;

						// 'numIncrease' & 'numIncrease2' are used as the two values
						// for the range of the dodge rate checker, used with 'randomDodge'

						// Set integer 'numIncrease' to 1 and
						// integer 'numIncrease2' to the player's dodge rate times 100
						numIncrease = 1;
						numIncrease2 = (int)(dodgeRate * 100);  // 0.01-1 (decimal) to 1-100 (whole #)

						// FIRST DODGE CHECK:
						// If the dodge check is a success
						//   (randomized num of 1-100 is within the
						//    starting range of the dodge rate checker)
						if (randomDodge > numIncrease && randomDodge <= numIncrease2) {
							// Set boolean 'fullDodge' to true
							fullDodge = true;
						}
						// Otherwise (If the dodge check failed)...
						else {
							// Increase the range of the
							// dodge rate checker up one notch
							numIncrease = numIncrease2;
							numIncrease2 = numIncrease2 + 20;
						}

						// Loop five times (after 5 times, dodge rate is guaranteed 0%)
						for (unsigned i = 0;i < 5;++i) {
							// If boolean 'fullDodge' is true (if first check above succeeded)
							if (fullDodge == true) {
								// Break out of the loop
								break;
							}

							// If the modifier is between 0 and 1 (but not actually 1)
							if (agilityModifier < 1 && agilityModifier >= 0) {
								// Increase the modifier is 0.25 (-25% damage avoided)
								agilityModifier = agilityModifier + 0.25;  // Dodges: 100% - 75% - 50% - 25% - 0%
							}
							// If the modifier is equal to 1 (0% damage avoided)
							if (agilityModifier == 1.0) {
								// Break out of the loop
								break;
							}

							// If 'numIncrease' or 'numIncrease2' reaches 100
							//   (the loop ran through all checks to 100%)
							if (numIncrease > 100 || numIncrease2 > 100) {
								// Break out of the loop
								break;
							}

							// NEXT DODGE CHECK:
							// If the dodge check is a success
							//   (randomized num of 1-100 is within the
							//    increased range of the dodge rate checker)
							if (randomDodge > numIncrease && randomDodge <= numIncrease2) {
								// Break out of the loop
								break;
							}

							// Increase the two values of the range of the dodge rate checker
							numIncrease = numIncrease + 20;
							numIncrease2 = numIncrease2 + 20;
						}

						// If the modifier is equal to 0 -- 100% damage avoided (0 x dmg = no dmg taken)
						if (agilityModifier == 0.0) {
							// Output that the player avoided 100% of Goblin 1's attack damage
							std::cout << "\n  You avoided Goblin 1's attack [" << fMobAttack1 << " DMG] with your agility!" << std::endl;
						}  // OR
						// If the modifier is equal to 1 -- 0% damage avoided (1 x dmg = full dmg taken)
						else if (agilityModifier == 1.0) {
							// Subtract 100% of Goblin 1's attack damage from the player's health
							player.setHealth(player.getHealth() - fMobAttack1);

							// Output that the player took 100% of Goblin 1's attack damage
							std::cout << "\n  Goblin 1 counter attacks for " << fMobAttack1 << " damage!" << std::endl;

							// Add the damage the player received to variable 'hpLost'
							//   (for output after the round ends)
							hpLost = (hpLost + fMobAttack1);
						}
						// Otherwise (If the modifier is more than 0 and less than 1 -- 0.25, 0.5, 0.75)...
						else {
							// Subtract Goblin 2's attack (minus the avoided damage) from the player's health
							//   - atk x 0.25 = 75% dmg avoided (Player gets damaged 25% of the enemy's dmg)
							//   - atk x 0.50 = 50% dmg avoided (Player gets damaged 50% of the enemy's dmg)
							//   - atk x 0.75 = 25% dmg avoided (Player gets damaged 75% of the enemy's dmg)
							player.setHealth(player.getHealth() - (fMobAttack1 * agilityModifier));

							// Output the % of damage the player negated and how much damage the player took
							std::cout << "\n  You have negated " << ((1 - agilityModifier) * 100) << "% of Goblin 1's attack damage [" << fMobAttack1 << " DMG] " <<
								"by maneuvering with your agility! You only take " << (fMobAttack1 * agilityModifier) << " damage!" << std::endl;

							// Add the damage the player received to variable 'hpLost'
							//   (for output after the round ends)
							hpLost = (hpLost + (fMobAttack1 * agilityModifier));
						}
					}

					// Otherwise (If Goblin 1 is dead)...
					else {
						// Output that Goblin 1 has died & how much experience the player receives
						std::cout << "\n  [Goblin 1 has perished.]\n  [EXP+" << goblin1.getEXP() << "]" << std::endl;
					}

					// If Goblin 1 is alive
					if (goblin1.getHealth() > 0) {
						// Output the amount of health lost after the round
						std::cout << "\n\n  [-" << hpLost << " HP]" << std::endl;
					}

					std::this_thread::sleep_for(std::chrono::milliseconds(350));  // Pause 0.35 sec
				}
			} while (goblin1.getHealth() > 0 && player.getHealth() > 0);
			// Keep repeating the block of code until Goblin 1 or the player dies

			// If the Enemy's health has dropped below zero, set
			// their health to 0 (you can't have negative health)
			if (goblin1.getHealth() < 0) {
				goblin1.setHealth(0);
			}

			// If the player has died
			if (player.getHealth() <= 0) {
				// Run the Death() method
				Death();
				// Terminate the program
				exit(0);
			}

			// Output the health status of player & all enemies
			std::cout << "\n\n  ###############################\n  HP:       (" << player.getHealth() << "/" << player.getMaxHealth() << ")\n  " <<
				"Goblin 1: (" << goblin1.getHealth() << "/" << goblin1.getMaxHealth() << ")\n  " <<
				"Goblin 2: (" << goblin2.getHealth() << "/" << goblin2.getMaxHealth() << ")\n  " <<
				"Goblin 3: (" << goblin3.getHealth() << "/" << goblin3.getMaxHealth() << ")\n  " <<
				"###############################" << std::endl;

			// Update the Character object 'player' by calculating
			// the updated experience from Goblin 1's death
			player = CalculateEXP(player, goblin1);

			// Output completion notification
			std::cout << "\n\n  Congratulations, you have killed the goblins!!\n  What now?" << std::endl;
		}
	}

	// When 'goto END:' is called, it goes to this location and plays from here
	END:

	// Return the updated Character object 'player' back to where this was called
	return player;
}

