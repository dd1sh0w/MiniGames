#include "Greeting.h"

Player Greeting()
{
	Player player;
	player.getName();

	std::cout << "\n\n\nHi," << player.name << "!\n";
	std::cout << "You have a 100$ at the start, but if you lose them, then the game is over \n" <<
		"But if you reach 1000$ then you will become a winner! \n \t\t\t Good luck! \n";
	std::cout << "\n#############################################################################################\n\n";
	return player;
}
