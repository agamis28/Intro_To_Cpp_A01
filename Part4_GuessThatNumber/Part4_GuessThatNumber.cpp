#include <iostream>
#include <string>
#include "utlis.hpp"

int main()
{
	bool playAgain = true;
	std::string playAgainAnswer;
	std::cout << "Let's Play A Number Guessing Game!!\n";
	do {
		playGame();
		std::cout << "\n\nYou Win!!\n\n";

		do {
			std::cout << "Would you like to play again?(y/n): ";
			std::cin >> playAgainAnswer;
			if (playAgainAnswer == "n") {
				playAgain = false;
			}
			clearCin();
		} while (playAgainAnswer != "y" && playAgainAnswer != "n");
	} while (playAgain);
}

