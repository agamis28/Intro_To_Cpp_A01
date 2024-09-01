#include <iostream>
#include <string>
#include "utlis.hpp"

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