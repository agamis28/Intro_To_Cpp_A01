#include <iostream>
#include <string>
#include <limits>

float chirpsToTemp(int chirps, std::string type) {
	const float f = 50 + (chirps * 4 - 40) / 4; // Chrips * 4 to get chirps per minute then add equation to get fahrenheit

	// Return Fahrenheit if type f or return celcius otherwise
	if (type == "f") {
		return f;
	}
		return (f - 32) * 5 / 9;
}

bool validateChrips(float fahrenheit) {
	if (fahrenheit < 50) {
		return false;
	}
	return true;
}

void clearCin() {
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int main()
{
	int chirps;
	float fahrenheit;

	std::cout << "Hi, there is a cricket in the field that reacts to temperature to decide how many times it chirps. Need to know the temperature outside but only have the cricket as a way to find it out. \n You count how many times the cricket chirps in 15 seconds. How many times did it chirp? \n";

	std::cin >> chirps;

	fahrenheit = chirpsToTemp(chirps, "f");

	if (!validateChrips(fahrenheit)) {
		do {
			clearCin();
			std::cout << "Sorry, incorrect format. \n Crickets also do not chirp below 50 degrees fahrenheit. \n Try again: ";
			std::cin >> chirps;
			fahrenheit = chirpsToTemp(chirps, "f");
		} while (fahrenheit < 50);
	}

	std::cout << "Temperature in Fahrenheit: " << chirpsToTemp(chirps, "f") << "\n";
	std::cout << "Temperature in Celsius: " << chirpsToTemp(chirps, "c");


}

