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

set<vector<string>> mySet;

// All possible wins
bool win(vector<string> v) {
    if (v[0][0] == v[0][1] && v[0][1] == v[0][2] && v[0][0] != '.') {
        return true;
    }
    if(v[1][0] == v[1][1] && v[1][1] == v[1][2] && v[1][0] != '.') {
        return true;
    }
    if(v[2][0] == v[2][1] && v[2][1] == v[2][2] && v[2][0] != '.') {
        return true;
    }
    if(v[0][0] == v[1][0] && v[1][0] == v[2][0] && v[0][0] != '.') {
        return true;
    }
    if(v[0][1] == v[1][1] && v[1][1] == v[2][1] && v[0][1] != '.') {
        return true;
    }
    if(v[0][2] == v[1][2] && v[1][2] == v[2][2] && v[0][2] != '.') {
        return true;
    }
    if(v[0][0] == v[1][1] && v[1][1] == v[2][2] && v[0][0] != '.') {
        return true;
    }
    if(v[0][2] == v[1][1] && v[1][1] == v[2][0] && v[0][2] != '.') {
        return true;
    }
    return false;
}

int main () {
    int TC; cin >> TC;
    pair<vector<string>, char> state;
    vector<string> def = {"...", "...", "..."};
    mySet.insert(def);
    state = {def, 'X'};
    
    queue<pair<vector<string>, char>> bfs;
    
    // Complete search
    bfs.push(state);
    while (!bfs.empty()) {
        char c = bfs.front().second;
        vector<string> s = bfs.front().first;
        bfs.pop();
        
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (s[i][j] == '.') {
                    s[i][j] = c;
                    mySet.insert(s);
                    
                    if (!win(s)) {
                        if (c == 'X') {
                            bfs.push({s, 'O'});
                        } else {
                            bfs.push({s, 'X'});
                        }
                    }
                    s[i][j] = '.';
                }
            }
        }

    }
    
    
    while (TC--) {
        vector<string> sample;
        for (int i = 0; i < 3; i++) {
            string input; cin >> input;
            sample.push_back(input);
        }
        if (mySet.find(sample) != mySet.end()) cout << "yes" << endl;
        else cout << "no" << endl;
    }
    
}

