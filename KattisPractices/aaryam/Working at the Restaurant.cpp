//
//  main.cpp
//  Working at the Restaurant
//
//  Created by Aaryam Srivastava on 19/2/2018.
//  Copyright © 2018 Developers. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

struct Commands{
    string instruction;
    int plates;
};

int main(void) {
    int N;
    while (1) {
        cin >> N; if (N == 0) break;
        
        int platesP1 = 0, platesP2 = 0;
        Commands *cmds = new Commands[N];
        for (int i = 0; i < N; i++) {
            cin >> cmds[i].instruction >> cmds[i].plates;
        }
        
        for (int i = 0; i < N; i++) {
            if (cmds[i].instruction == "DROP") {
                cout << "DROP 2 " << cmds[i].plates << endl;
                platesP2 += cmds[i].plates;
            }
            else {
                if (platesP1 >= cmds[i].plates) {
                    platesP1 -= cmds[i].plates;
                    cout << "TAKE 1 " << cmds[i].plates << endl;
                }
                else {
                    if (platesP1 != 0) {
                        cout << "TAKE 1 " << platesP1 << endl;
                        cmds[i].plates -= platesP1;
                        platesP1 = 0;
                    }
                    cout << "MOVE 2->1 " << platesP2 << endl;
                    platesP1 = platesP2 - cmds[i].plates;
                    platesP2 = 0;
                    cout << "TAKE 1 " << cmds[i].plates << endl;
                }
            }
        }
        cout << endl;
    }
    
    return 0;
}

