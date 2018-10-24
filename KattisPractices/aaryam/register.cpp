//
//  main.cpp
//  Primary Register
//
//  Created by Aaryam Srivastava on 24/12/2017.
//  Copyright © 2017 LearnAppMaking. All rights reserved.
//

#include <iostream>

int main(void) {
    int registers[8];
    int limits[8] = {2,3,5,7,11,13,17,19};
    int operations = 0;
    
    for (int i = 0; i < 8; i++) {
        std::cin >> registers[i];
    }
    
    while (registers[7] < 19) {
        registers[0]++;
        operations++;
        for (int i = 0; i < 7; i++) {
            if (registers[i] >= limits[i]) {
                registers[i+1]++;
                registers[i] = 0;
            }
        }
    }
    operations--;
    
    std::cout << operations << std::endl;
    
    return 0;
}

