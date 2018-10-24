//
//  main.cpp
//  Booking A Room
//
//  Created by Aaryam Srivastava on 22/12/2017.
//  Copyright © 2017 LearnAppMaking. All rights reserved.
//

#include <iostream>

int included(int numbers[], int numb, int chosen);
int main(void) {
    int number_r, number_n;
    int i;
    int chosen_number;
    
    std::cin >> number_r;
    std::cin >> number_n;
    
    int numbers[number_n];
    
    for (i = 1; i < number_n+1; i++) {
        std::cin >> numbers[i];
    }
    
    if (number_n == number_r) {
        std::cout << "too late" << std::endl;
    }
    
    for (i = 1; i < number_r+1; i++) {
        chosen_number = i;
        
        if (included(numbers, number_n, chosen_number) == 0) {
            std::cout << chosen_number << std::endl;
            break;
        }
    }
    
    return 0;
}

int included(int numbers[], int numb, int chosen) {
    int i;
    
    for (i = 1; i < numb+1; i++) {
        if (chosen == numbers[i]) {
            return 1;
        }
    }
    
    return 0;
}
