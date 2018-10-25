//
//  main.cpp
//  Numbers on a tree
//
//  Created by Aaryam Srivastava on 25/1/2018.
//  Copyright © 2018 LearnAppMaking. All rights reserved.
//

#include <iostream>
#include <math.h>
#include <string.h>
using namespace std;

int main(void) {
    int height;
    
    cin >> height;
    char directions[height + 1];
    int elements = pow(2, (height + 1)) - 1;
    
    if (scanf("%s", directions) == EOF) {
        cout << elements << endl;
    }
    else {
        int position = 1;
        for (int i = 0; i < strlen(directions); i++) {
            position *= 2;
            if (directions[i] == 'R') {
                position++;
            }
        }
        cout << elements - position + 1 << endl;
    }
    
    return 0;
}
