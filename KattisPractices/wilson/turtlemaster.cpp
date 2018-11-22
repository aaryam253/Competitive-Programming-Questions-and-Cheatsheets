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

#define MAX 2147483646

using namespace std;
char mtx[10][10];
int currOrientation = 90; // facing right
pair<int, int> currCoords = {7,0}; // 8th row, 0th column

bool checkMove () {
    if (currCoords.first >= 8 || currCoords.second >= 8 || currCoords.first < 0 || currCoords.second < 0) {
        return false;
    }
    if (mtx[currCoords.first][currCoords.second] == 'C') {
        return false;
    }
    if (mtx[currCoords.first][currCoords.second] == 'I') {
        return false;
    }
    return true;
}


bool checkFire () {
    switch (currOrientation) {
        case 0:
            if (currCoords.first - 1 >= 0 && mtx[currCoords.first-1][currCoords.second] == 'I') {
                mtx[currCoords.first-1][currCoords.second] = '.';
                return true;
            }
            break;
        case 90:
            if (currCoords.second + 1 < 8 && mtx[currCoords.first][currCoords.second+1] == 'I') {
                mtx[currCoords.first][currCoords.second+1] = '.';
                return true;
            }
            break;
        case 180:
            if (currCoords.first + 1 < 8 && mtx[currCoords.first+1][currCoords.second] == 'I') {
                mtx[currCoords.first+1][currCoords.second] = '.';
                return true;
            }
            break;
            
        case 270:
            if (currCoords.second - 1 >= 0 && mtx[currCoords.first][currCoords.second-1] == 'I') {
                mtx[currCoords.first][currCoords.second-1] = '.';
                return true;
            }
            break;
    }
    return false;
}

int main () {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            cin >> mtx[i][j];
        }
    }
    
    
    string instructions; cin >> instructions;
    for (auto it : instructions) {
        if (it == 'F') {
            switch (currOrientation) {
                case 0:
                    currCoords.first -= 1;
                    break;
                case 90:
                    currCoords.second += 1;
                    break;
                case 180:
                    currCoords.first += 1;
                    break;
                case 270:
                    currCoords.second -= 1;
                    break;
            }
            if (!checkMove()) {
                cout << "Bug!" << endl;
                return 0;
            }
            
        } else if (it == 'L') {
            if (!currOrientation) {
                currOrientation = 270;
            } else {
                currOrientation -= 90;
            }
            
        } else if (it == 'R') {
            if (currOrientation == 270) {
                currOrientation = 0;
            } else {
                currOrientation += 90;
            }
            
        } else if (it == 'X') {
            if (!checkFire()) {
                cout << "Bug!" << endl;
                return 0;
            }
        }
    }
    
//    for (int i = 0; i < 8; i++) {
//        for (int j = 0; j < 8; j++) {
//            cout << mtx[i][j];
//        }
//        cout << endl;
//    }
    
    if (mtx[currCoords.first][currCoords.second] == 'D') {
        cout << "Diamond!" << endl;
    } else {
        cout << "Bug!" << endl;
    }

}
