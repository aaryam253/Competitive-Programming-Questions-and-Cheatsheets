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

#define MAX 1e9

using namespace std;

char mtx[4][3] = {
    {'1', '2', '3'},
    {'4', '5', '6'},
    {'7', '8', '9'},
    {'#', '0', '#'}
};

vector<char> findClosest (char current) {
    int x, y;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 3; j++) {
            if (mtx[i][j] == current) {
                x = j;
                y = i;
            }
        }
    }
    queue<pair<int, int>> q;
    q.push({y,x});
    vector<char> backtrack;
    unordered_set<char> visited;
    visited.insert(mtx[y][x]);
    backtrack.push_back(mtx[y][x]);
    int dx[2] = {0,1};
    int dy[2] = {1,0};
    while (!q.empty()) {
        pair<int, int> curr = q.front();
        int x = curr.second;
        int y = curr.first;
        q.pop();
        for (int i = 0; i < 2; i++) {
            int x_new = x + dx[i];
            int y_new = y + dy[i];
            if (x_new >= 0 && x_new < 3 && y_new >= 0 && y_new < 4) {
                if (visited.find(mtx[y_new][x_new]) == visited.end() && mtx[y_new][x_new] != '#') {
                    q.push({y_new, x_new});
                    visited.insert(mtx[y_new][x_new]);
                    backtrack.push_back(mtx[y_new][x_new]);
                }
            }
        }
    }
    
    return backtrack;
}

int main () {
    
    int TC; cin >> TC;
    while (TC--) {
        string input; cin >> input;
        vector<int> numbers;
        vector<char> original;
        vector<char> prev;
        vector<char> temp;
        numbers.push_back(input[0] - '0');
        for (char d = '0'; d <= '9' ; d++) {
            numbers.push_back(d - '0');
            for (auto i : findClosest(d)) {
                string out = "";
                out += d;
                out += i;
                numbers.push_back(stoi(out));
                for (auto c : findClosest(i)) {
                    string temp = out;
                    temp += c;
                    numbers.push_back(stoi(temp));
                }
            }
        }
        
        int target = stoi(input);
        int min = 1000000;
        int number = -1;
        for (auto it : numbers) {
            if (abs(it - target) < min) {
                min = abs(it - target);
                number = it;
            }
        }
        cout << number << endl;

    }
    
}
