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

#define MAX 2147483646

using namespace std;


int main () {
    unordered_set<string> boat;
    int x, y; cin >> x >> y;
    int day = 1;
    while (y--) {
        string input; cin >> input;
        boat.insert(input);
        if (boat.size() == x) {
            cout << day << endl;
            return 0;
        }
        day++;
    }
    
    cout << "paradox avoided" << endl;
    
}
