//
//  main.cpp
//  Judging Moose
//
//  Created by Aaryam Srivastava on 7/1/2018.
//  Copyright © 2018 LearnAppMaking. All rights reserved.
//

#include <iostream>

int main (void) {
    int left, right, points;
    
    std::cin >> left;
    std::cin >> right;
    
    if (left == 0 && right == 0) {
        std::cout << "Not a moose";
        std::cout << std::endl;
    }
    else if (left < right) {
        points = 2 * right;
        std::cout << "Odd " << points << std::endl;
    }
    else if (left > right) {
        points = 2 * left;
        std::cout << "Odd " << points << std::endl;
    }
    else {
        points = 2 * left;
        std::cout << "Even " << points << std::endl;
    }
    
    return 0;
}
