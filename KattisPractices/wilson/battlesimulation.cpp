#include <iostream>
#include <stdio.h>
#include <deque>

using namespace std;

int main () {
    string input;
    deque<char> attack;
    
    cin >> input;
    for (int i = 0; i < input.length(); i++) {
        switch (input[i]) {
            case 'R':
                attack.push_back('S');
                break;
            case 'B':
                attack.push_back('K');
                break;
            case 'L':
                attack.push_back('H');
                break;
        }
        if (attack.size() > 2) {
            auto it = prev(attack.end(), 1);
            auto it2 = prev(attack.end(), 2);
            auto it3 = prev(attack.end(), 3);
            if ((*it != *it2 && *it != *it3 && *it2 != *it3) && (*it != 'C' && *it2 != 'C' && *it3 != 'C')) {
                for (int d = 0; d < 3; d++) {
                    attack.pop_back();
                }
                attack.push_back('C');

            }
        }
        
        
    }
    
    for (auto it = attack.begin(); it != attack.end(); it++) {
        cout << *it;
    }
    cout << endl;
}
