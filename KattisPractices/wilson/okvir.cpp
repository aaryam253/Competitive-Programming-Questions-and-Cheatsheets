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
#include <sstream>

#define MAX 2147483640

using namespace std;


int main () {
    int r, c; cin >> r >> c;
    int U, L, R, D; cin >> U >> L >> R >> D;
    char mtx[20][20];
    for (int i = 0; i < r; i++) {
        for (int d = 0; d < c; d++) {
            cin >> mtx[i][d];
        }
    }
    
//    for (int i = 0; i < r; i++) {
//        for (int d = 0; d < c; d++) {
//            cout << mtx[i][d];
//        }
//        cout << endl;
//    }
    
    int newRow = r + U + D;
    int newCol = c + L + R;
    char alt = '#';
    for (int i = 0; i < newRow; i++) {
        char alt_ = alt;
        for (int d = 0; d < newCol; d++) {
            if (i < U || i > (U + r - 1) || d < L || d > (L + c - 1)) {
                cout << alt_;
            } else {
                cout << mtx[i-U][d-L];
            }
            
            if (alt_ == '#') {
                alt_ = '.';
            } else {
                alt_ = '#';
            }
        }
        cout << endl;
        if (alt == '#') {
            alt = '.';
        } else {
            alt = '#';
        }
    }

}
