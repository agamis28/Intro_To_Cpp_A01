#include <iostream>

void playGame() {
    
}

int pickLowBoundsOfGame() {
    int low;
    std::cout << "What is the lower bound for the secret number?: ";
    std::cin >> low;
    return low;
}
int pickHighBoundsOfGame() {
    int high;
    std::cout << "What is the higher bound for the secret number?: ";
    std::cin >> high;
    return high;
}


int main()
{
    std::cout << "Let's Play A Number Guessing Game!!";

}

