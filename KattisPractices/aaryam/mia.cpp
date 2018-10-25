//
//  main.cpp
//  Mia
//
//  Created by Aaryam Srivastava on 7/1/2018.
//  Copyright © 2018 LearnAppMaking. All rights reserved.
//

#include <iostream>
// function to determine who is the winner given the hand of the two players
int winner (int number1, int number2);
int main(void) {
    int player11, player12, player21, player22;
    int winner1, winner2;
    
    //while loop that continues to read the data inputs until a row of zeroes
    while (1) {
        std::cin >> player11 >> player12 >> player21 >> player22;
        if (player11 == 0 && player12 == 0 && player21 == 0 && player22 == 0) {
            return 0;
        }
        
        winner1 = winner(player11, player12);
        winner2 = winner(player21, player22);
        
        if (winner1 > winner2) {
            std::cout << "Player 1 wins." << std::endl;
        }
        else if (winner1 < winner2) {
            std::cout << "Player 2 wins." << std::endl;
        }
        else {
            std::cout << "Tie." << std::endl;
        }
    }
    
    return 0;
}

int winner (int number1, int number2) {
    
    if ((number1 == 1 && number2 == 2) || (number1 == 2 && number2 == 1)) {
        return 999;
    }
    
    if (number1 > number2) {
        return number1 * 10 + number2;
    }
    else if (number1 < number2) {
        return number2 * 10 + number1;
    }
    else {
        return (10 * number1 + number2) * 10;
    }
    
    return 0;
}
