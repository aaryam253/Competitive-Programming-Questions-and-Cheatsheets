//
//  main.cpp
//  Mjehuric
//
//  Created by Aaryam Srivastava on 10/1/2018.
//  Copyright © 2018 LearnAppMaking. All rights reserved.
//

#include <iostream>

int main(void) {
    int numbers[5], i, j;
    bool swapped = false;
    
    
    for (i = 0; i < 5; i++) {
        std::cin >> numbers[i];
    }
    
    do {
        swapped = false;
        for (i = 0; i < 4; i++) {
            if (numbers[i] > numbers[i+1]) {
                std::swap(numbers[i], numbers[i+1]);
                
                for (j = 0; j < 5; j++) {
                    std::cout << numbers[j] << " ";
                } std::cout << std::endl;
                
                swapped = true;
            }
        }
    } while(swapped);
    
    return 0;
}
