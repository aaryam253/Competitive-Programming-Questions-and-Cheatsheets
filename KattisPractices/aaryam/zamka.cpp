//
//  main.cpp
//  Zamka
//
//  Created by Aaryam Srivastava on 22/12/2017.
//  Copyright © 2017 LearnAppMaking. All rights reserved.
//

#include <iostream>

int summation(int number);

int main(void) {
    int number_L, number_D, number_X;
    int number_M = 0, number_N = 10001;
    int i, sum;
    
    std::cin >> number_L >> number_D >> number_X;
    
    for (i = number_L; i < (number_D+1); i++) {
        sum = summation(i);
        
        if (sum == number_X) {
            if (i < number_N) {
                number_N = i;
            }
            
            if (i > number_M) {
                number_M = i;
            }
        }
    }
    
    std::cout << number_N << std::endl;
    std::cout << number_M << std::endl;
    
    return 0;
}

int summation(int number) {
    int sum = 0;
    
    if (number >= 10) {
        sum += (number % 10) + summation(number/10);
    }
    else {
        sum += number;
    }
    return sum;
}
