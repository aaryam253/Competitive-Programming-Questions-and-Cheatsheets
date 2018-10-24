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
    while (true) {
        int x, y; cin >> x >> y;
        if (!x && !y) return 0;
        if (x + y == 13) {
            cout << "Never speak again." << endl;
        } else if (x == y) {
            cout << "Undecided." << endl;
        } else if (x > y) {
            cout << "To the convention." << endl;
        } else if (x < y) {
            cout << "Left beehind." << endl;
        }

    }
    
}
