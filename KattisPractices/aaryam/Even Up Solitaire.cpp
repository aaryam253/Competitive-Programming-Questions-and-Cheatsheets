//
//  main.cpp
//  Even Up Solitaire
//
//  Created by Aaryam Srivastava on 18/1/2018.
//  Copyright © 2018 LearnAppMaking. All rights reserved.
//

#include <iostream>
#include <stack>
using namespace std;

int main(void) {
    stack <int> reversed;
    stack <int> temp;
    int total, num, remaining, even = 0;
    
    cin >> total;
    remaining = total;
    
    for (int i = 0; i < total; i++) {
        cin >> num;
        reversed.push(num);
    }
    
    while (1) {
        if (reversed.empty()) {
            cout << remaining << endl;
            break;
        }
        
        even += reversed.top();
        temp.push(reversed.top());
        reversed.pop();
        
        if (reversed.empty()) {
            cout << remaining << endl;
            break;
        }
        
        even += reversed.top();
        
        if (even % 2 == 0) {
            remaining -= 2;
            reversed.pop();
            temp.pop();
            while (!temp.empty()) {
                reversed.push(temp.top());
                temp.pop();
            }
            even = 0;
        }
        else {
            even = 0;
        }
    }

    return 0;
    
}
