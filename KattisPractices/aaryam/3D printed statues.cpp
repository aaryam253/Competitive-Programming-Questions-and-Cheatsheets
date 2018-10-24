//
//  main.cpp
//  3D Printed Statues
//
//  Created by Aaryam Srivastava on 24/1/2018.
//  Copyright © 2018 LearnAppMaking. All rights reserved.
//

#include <iostream>
#include <math.h>
using namespace std;

int main(void) {
    int printers = 1, statues, days = 0;
    
    cin >> statues;
    
    while (1) {
        if (statues == 1) {
            days = 1;
            break;
        }
        else if (printers >= statues) {
            days++;
            break;
        }
        
        printers += printers;
        days++;
    }
    
    cout << days << endl;
    
    return 0;
}
