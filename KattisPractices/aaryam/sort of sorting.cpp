//
//  main.cpp
//  Sort of Sorting
//
//  Created by Aaryam Srivastava on 14/1/2018.
//  Copyright © 2018 LearnAppMaking. All rights reserved.
//

#include <iostream>
#include <string>
#define MAX 500
using namespace std;

void BubbleSort(string names[], int lim, int people) {
    string temp;
    
    for (int i = 0; i < people-1; i++) {
        for (int j = 0; j < people - i - 1; j++) {
            if (names[j][lim] > names[j+1][lim]) {
                swap(names[j], names[j+1]);
            } else if (names[j][lim] == names[j+1][lim] && names[j][lim+1] > names[j+1][lim+1]) {
                swap(names[j], names[j+1]);
            }
        }
    }
    
}



int main () {
    int people;
    string names[200];
    
    do {
        cin >> people;
        
        for (int i = 0; i < people; i++) {
            cin >> names[i];
        }
        
        BubbleSort(names, 0, people);
        
        cout << endl;
        
        for (int i = 0; i < people; i++) {
            cout << names[i] << endl;
        }
    } while (people != 0);
    
    return 0;
}
