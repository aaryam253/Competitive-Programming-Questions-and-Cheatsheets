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
#include <iomanip>

#define MAX 2147483640

using namespace std;

void printMtx (vector<int> asterixRows, int col) {
    int pos = col-1;
    int index = 0;
    vector<vector<char>> v (asterixRows.size(), vector<char>(col, '.'));
    for (int i = 0; i < asterixRows.size(); i++) {
        int numAsterixes = asterixRows[index++];
        for (int d = col-1; d >= 0; d--) {
            if (d <= pos && numAsterixes) {
                v[i][d] = '*';
                pos--;
                numAsterixes--;
            }
        }
    }
    
    for (int i = 0; i < asterixRows.size(); i++) {
        for (int d = 0; d < col; d++) {
            cout << v[i][d];
        }
        cout << endl;
    }
    cout << endl;
}

int main () {
    string input;
    int col = 0;
    vector<int> asterixRows;
    while (getline(cin, input)) {
        if (input == "") {
            printMtx(asterixRows, col);
//            cout << "clear" << endl;
            asterixRows.clear();
        } else {
            col = input.length();
            int sum = 0;
            for (int i = 0; i < input.length(); i++) {
                if (input[i] == '*') sum++;
            }
            asterixRows.push_back(sum);
        }
    }
    
    printMtx(asterixRows, col);
}
