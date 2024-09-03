#include <iostream>
#include <string>
#include "utlis.hpp"

// If any characters in string passed through is lowercase return true
bool checkForLowerCase(const std::string pass) {
	for (int i = 0; i < pass.length(); i++) {
		if (std::islower(pass[i])) {
			return true;
		};
	}
	return false;
}

// If any characters in string passed through is uppercase return true
bool checkForUpperCase(const std::string pass) {
	for (int i = 0; i < pass.length(); i++) {
		if (std::isupper(pass[i])) {
			return true;
		};
	}
	return false;
}

// If any characters in string passed through is a number return true
bool checkForNumber(const std::string pass) {
	for (int i = 0; i < pass.length(); i++) {
		if (std::isdigit(pass[i])) {
			return true;
		};
	}
	return false;
}


//  Returns a string reason why the password is invalid. If not invalid return empty string.
int chcekPasswordValid(std::string pass) {
	if (pass.length() < 8) {
		return 0; // Return needs at least 8 characters case
	}
	else if (!checkForLowerCase(pass)) {
		return 1;
	}
	else if (!checkForUpperCase(pass)) {
		return 2;
	}
	else if (!checkForNumber(pass)) {
		return 3;
	}
	return 4;
}

void clearCin() {
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

std::string setPassword() {
	std::string pass;
	clearCin();
	std::cin >> pass;
	return pass;
}