//
//  main.cpp
//  Line Them Up
//
//  Created by Aaryam Srivastava on 26/1/2018.
//  Copyright © 2018 LearnAppMaking. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, const char * argv[]) {
    int people;
    cin >> people;
    string temp;
    vector <string> names, sorted;
    
    for (int i = 0; i < people; i++) {
        cin >> temp;
        names.push_back(temp);
        sorted.push_back(temp);
    }

    sort(sorted.begin(), sorted.end());
    if (names == sorted) printf("INCREASING\n");
    else {
        reverse(sorted.begin(), sorted.end());
        if (names == sorted) cout << "DECREASING" << endl;
        else cout << "NEITHER" << endl;
    }

    return 0;
}
