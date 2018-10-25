//
//  main.cpp
//  Stacking Cups
//
//  Created by Aaryam Srivastava on 10/1/2018.
//  Copyright © 2018 LearnAppMaking. All rights reserved.
//

#include <iostream>
#include <sstream>
using namespace std;

int main (void) {
    int no_of_cups;
    bool swapped;
    string radius;
    string colour;
    int true_rad = 0;
    string temp;
    
    cin >> no_of_cups;
    string colours[no_of_cups];
    string radii[no_of_cups];
    int true_radii[no_of_cups];
    
    for (int i = 0; i < no_of_cups; i++) {
        cin >> radii[i] >> colours[i];
        
        if (isalnum(radii[i].at(0))) {
            stringstream geek(radii[i]);
            geek >> true_rad;
            true_rad /= 2;
            true_radii[i] = true_rad;
        }
        
        if (isalpha(radii[i].at(0))) {
            temp = radii[i];
            radii[i] = colours[i];
            colours[i] = temp;
            
            stringstream geek(radii[i]);
            geek >> true_rad;
            true_radii[i] = true_rad;
        }
    }
    
    
        do {
            swapped = false;
            for (int i = 0; i < no_of_cups-1; i++) {
                if (true_radii[i] > true_radii[i+1]) {
                    swap(true_radii[i], true_radii[i+1]);
                    temp = colours[i];
                    colours[i] = colours[i+1];
                    colours[i+1] = temp;
                    
                    swapped = true;
                }
            }
        } while (swapped);

    
    for (int i = 0; i < no_of_cups; i++) {
        cout << colours[i] << endl;
    }
    
    return 0;
}
