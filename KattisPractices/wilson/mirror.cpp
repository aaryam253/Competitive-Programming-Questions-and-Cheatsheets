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
    int TC; cin >> TC;
    int count = 1;
    while (TC--) {
        char mtx[25][25] = {};
        int r,c; cin >> r >> c;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                cin >> mtx[i][j];
            }
        }
        
        cout << "Test " << count++ << endl;
        for (int i = r-1; i >= 0; i--) {
            for (int j = c-1; j >= 0; j--) {
                cout << mtx[i][j];
            }
            cout << endl;
        }
        
    }
}
