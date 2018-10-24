//
//  main.cpp
//  Time_Loop
//
//  Created by Aaryam Srivastava on 16/12/2017.
//  Copyright © 2017 LearnAppMaking. All rights reserved.
//

#include <iostream>

int main(void) {
    int spells, i;
    
    scanf("%d", &spells);
    
    for (i = 0; i < spells; i++) {
        printf("%d Abracadabra\n", i+1);
    }
    
    return 0;
}
