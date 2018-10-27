#include <iostream>
#include <stdio.h>
#include <math.h>
#include <list>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <algorithm>
#include <tuple>
#include <string.h>

#define MAX 2147483646

using namespace std;

int main () {
    int TC; cin >> TC;
    while (TC--) {
        priority_queue<int> godzilla;
        priority_queue<int> mechaGodzilla;
        int g, m; cin >> g >> m;
        for (int i = 0; i < g; i++) {
            int input; cin >> input;
            godzilla.push(input);
        }
        
        for (int i = 0; i < m; i++) {
            int input; cin >> input;
            mechaGodzilla.push(input);
        }
        
        while (true) {
            if (godzilla.empty()) {
                cout << "MechaGodzilla" << endl;
                break;
            }
            
            if (mechaGodzilla.empty()) {
                cout << "Godzilla" << endl;
                break;
            }
            
            if (mechaGodzilla.top() <= godzilla.top()) {
                mechaGodzilla.pop();
            } else if (mechaGodzilla.top() > godzilla.top()) {
                godzilla.pop();
            }
        }
        
    }
    
}
