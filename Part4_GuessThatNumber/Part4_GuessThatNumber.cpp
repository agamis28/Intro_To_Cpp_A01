#include <iostream>
#include <string>
#include <limits>

void clearCin() {
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

bool checkIfNumber(std::string input) {
	for (int i = 0; i < input.length(); i++) {
		if (!isdigit(input[i])) {
			return false;
		}
	}
	return true;
}

int pickLowBoundsOfGame() {
	std::string input;
	int low;
	bool isInt = false;
	bool isString = true;
	do {
		std::cout << "What is the lower bound for the secret number?: ";

		std::cin >> input;

		// If input is a number change isString condition and allow it to exit do while if other conditions are met
		if (checkIfNumber(input)) {
			isString = false;
			low = stoi(input); // Change string type to int type
			if ((int)low == low) {
				isInt = true;
			}
		}

		// If one of the conditions aren't met clear and try again
		if (!isInt || isString) {
			std::cout << "Please use an integer! \n";
			clearCin();
		}
	} while (!isInt || isString);
	std::cout << "Lower bound is: " << low << "\n";
	clearCin();
	return low;
}
int pickHighBoundsOfGame() {
	std::string input;
	int high;
	bool isInt = false;
	bool isString = true;
	do {
		std::cout << "What is the higher bound for the secret number?: ";

		std::cin >> input;

		// If input is a number change isString condition and allow it to exit do while if other conditions are met
		if (checkIfNumber(input)) {
			isString = false;
			high = stoi(input); // Change string type to int type
			if ((int)high == high) {
				isInt = true;
			}
		}

		// If one of the conditions aren't met clear and try again
		if (!isInt || isString) {
			std::cout << "Please use an integer! \n";
			clearCin();
		}
	} while (!isInt || isString);
	std::cout << "Higher bound is: " << high << "\n";
	clearCin();
	return high;
}

int pickRandomInt(int min, int max) {
	return rand() % (max - min + 1) + min;
}

void playGame() {
	std::srand(time(0));
	int lowBound;
	int highBound;
	int answer;
	std::string input;
	int guess;

	// Keep picking low bound untill it is greater than zero
	do {
		lowBound = pickLowBoundsOfGame();
		if (lowBound <= 0) {
			std::cout << "Please pick a number greater than 0! \n";
		}
	} while (lowBound <= 0);

	// Keep picking high bound untill it is higher than low bound
	do {
		highBound = pickHighBoundsOfGame();
		if (highBound <= lowBound) {
			std::cout << "Please pick a bound higher than the lower bound! \n";
		}
	} while (highBound <= lowBound);

	answer = pickRandomInt(lowBound, highBound);
	std::cout << "Okay, I have the secret number between " << lowBound << " and " << highBound << ".\n";	

	do {
		std::cout << "What is your guess: ";
		std::cin >> input;

		// If input is a number continue before repeating
		if (checkIfNumber(input)) {
			guess = stoi(input); // Change string type to int type
			if (guess < answer) {
				std::cout << "Sorry, your guess was to low!\n\n";
			}
			if (guess > answer) {
				std::cout << "Sorry, your guess was to high!\n\n";
			}
		}
		else {
			std::cout << "Please guess an integer!\n";
		}
		clearCin(); 
	} while (guess != answer);
}

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

