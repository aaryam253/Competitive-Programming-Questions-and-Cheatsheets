//
//  main.cpp
//  Statistics
//
//  Created by Aaryam Srivastava on 17/12/2017.
//  Copyright © 2017 LearnAppMaking. All rights reserved.
//

#include <iostream>

int main(void) {
    int values [10][30] = {{0}}, i, j;
    int cases = 0;
    int min, max, range;
    
    i = 0;
    while (std::cin >> values[i][0]) {
        cases++;
        
        for (j = 1; j < (values[i][0]+1); j++) {
            std::cin >> values[i][j];
        }
        
        i++;
    }
    
    std::cout << std::endl;
    
    for (i = 0; i < cases; i++) {
        std::cout << "Case " << i+1 << ":";
        min = 1000001;
        max = -1000001;
        range = 0;
        
        for (j = 1; j < (values[i][0]+1); j++) {
            if (values [i][j] < min) {
                min = values[i][j];
            }
            if (values [i][j] > max) {
                max = values[i][j];
            }
            range = max - min;
        }
        std::cout << " " << min << " " << max << " " << range << " " << std::endl;
    }
    
    return 0;
}
