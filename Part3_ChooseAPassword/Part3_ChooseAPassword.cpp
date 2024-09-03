#include <iostream>
#include <string>
#include "utlis.hpp"

int main()
{
	std::string password;
	std::string confirmPassword;
	bool passIsValid = false;

	std::cout << "Please choose a password: ";
	std::cin >> password;

	do {
		switch (chcekPasswordValid(password)) {
		case 0:
			std::cout << "Password needs to be at least 8 characters. \n";
			std::cout << "Please Try Again: ";
			password = setPassword();
			break;
		case 1:
			std::cout << "Password needs to have at least 1 lower case letter. \n";
			std::cout << "Please Try Again: ";
			password = setPassword();
			break;
		case 2:
			std::cout << "Password needs to have at least 1 upper case letter. \n";
			std::cout << "Please Try Again: ";
			password = setPassword();
			break;
		case 3:
			std::cout << "Password needs to have at least 1 number. \n";
			std::cout << "Please Try Again: ";
			password = setPassword();
			break;
		case 4:
			clearCin();
			std::cout << "Please type the password again to confirm it: ";
			std::cin >> confirmPassword;
			if (confirmPassword == password) {
				passIsValid = true; // Escape do while when confirming password
			}
			else {
				std::cout << "Sorry that was incorrect, please start again. \n";
				std::cout << "Please choose a password: ";
				password = setPassword();
			}
		}
	} while (!passIsValid);

	std::cout << "Thank you, you have now set your password to: " << password;
}