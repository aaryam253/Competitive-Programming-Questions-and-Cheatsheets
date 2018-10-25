//
//  main.cpp
//  Battle Simulation
//
//  Created by Aaryam Srivastava on 10/2/2018.
//  Copyright © 2018 Developers. All rights reserved.
//

#include <iostream>
#include <string.h>
#include <stdio.h>
#include <vector>
using namespace std;

int main(void) {
    char attacks[1000001]; scanf("%s", attacks);
    vector <char> commands;
    size_t len = strlen(attacks);

    size_t i = 0;
    while (i < len){
        if (attacks[i] == 'R') {
            if (i + 2 < len && ((attacks[i+1] == 'B' && attacks[i+2] == 'L') ||(attacks[i+2] == 'B' && attacks[i+1] == 'L'))) {
                commands.push_back('C'); i+= 3;
            }
            else {
                commands.push_back('S');
                i++;
            }
        }
        else if (attacks[i] == 'B') {
            if (i + 2 < len && ((attacks[i+1] == 'R' && attacks[i+2] == 'L') ||(attacks[i+2] == 'L' && attacks[i+1] == 'R'))) {
                commands.push_back('C'); i+= 3;
            }
            else {
                commands.push_back('K');
                i++;
            }
        }
        else if (attacks[i] == 'L') {
            if (i + 2 < len && ((attacks[i+1] == 'B' && attacks[i+2] == 'R') ||(attacks[i+2] == 'R' && attacks[i+1] == 'B'))) {
                commands.push_back('C'); i+= 3;
            }
            else {
                commands.push_back('H');
                i++;
            }
        }
    }
    
    for (auto &a : commands) cout << a;
    cout << endl;
    
    return 0;
}
