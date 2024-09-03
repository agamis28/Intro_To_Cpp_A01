#include <iostream>
#include <string>
#include <limits>
#include "utlis.hpp"


int main()
{
	int chirps;
	float fahrenheit;

	std::cout << "Hi, there is a cricket in the field that reacts to temperature to decide how many times it chirps. Need to know the temperature outside but only have the cricket as a way to find it out. \n You count how many times the cricket chirps in 15 seconds. How many times did it chirp? \n";

	std::cin >> chirps;

	fahrenheit = chirpsToTemp(chirps, "f");

	// Check if fahrenheit is valid if not clear Cin and try again untill everything is valid
	if (!validateChrips(fahrenheit)) {
		do {
			clearCin();
			std::cout << "Sorry, incorrect format. \n Crickets also do not chirp below 50 degrees fahrenheit. \n Try again: ";
			std::cin >> chirps;
			fahrenheit = chirpsToTemp(chirps, "f");
		} while (fahrenheit < 50);
	}

	// Output Temperature in f and in c
	std::cout << "Temperature in Fahrenheit: " << chirpsToTemp(chirps, "f") << "\n";
	std::cout << "Temperature in Celsius: " << chirpsToTemp(chirps, "c");


}

