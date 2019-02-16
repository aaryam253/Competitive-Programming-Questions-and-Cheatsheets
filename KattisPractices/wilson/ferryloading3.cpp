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


pair<string, int> findBest (queue<pair<int, int>> left, queue<pair<int, int>> right, string curr) {
    pair<string, int> a = {"left", 0};
    pair<string, int> b = {"right", 0};

    if (left.empty()) {
        a.second = MAX;
    } else {
        a.second = left.front().second;
    }
    
    if (right.empty()) {
        b.second = MAX;
    } else {
        b.second = right.front().second;
    }
    
    if (a.second < b.second) {
        return a;
    } else if (a.second > b.second) {
        return b;
    } else {
        // a.second == b.second
        if (curr == a.first) return a;
        else return b;
    }
}


int main () {
    int c; cin >> c;
    while (c--) {
        queue<pair<int, int>> left;
        queue<pair<int, int>> right;
        
        int n,t,m; cin >> n >> t >> m;
        for (int i = 0; i < m; i++) {
            int time; cin >> time;
            string direction; cin >> direction;
            if (direction == "left") {
                left.push({i, time});
            } else {
                right.push({i, time});
            }
        }
        
        long long cars[10001] = {};
        long long currTime = 0;
        string curr = "left";
        vector<int> currLoad;
        
        for (;;) {
            string nextCurr = findBest(left, right, curr).first;
            int nextTime = findBest(left, right, curr).second;
            if (nextTime == MAX && currLoad.empty()) break;

            if (nextTime > currTime && currLoad.empty()) {
                currTime = nextTime;
                if (nextCurr != curr) currTime += t;
                curr = nextCurr;
            }
            
            if (curr == "left") {
                if (!left.empty() && left.front().second <= currTime && currLoad.size() < n) {
                    currLoad.push_back(left.front().first);
                    left.pop();
                } else {
                    // Time to travel across
                    currTime += t;
                    for (auto it: currLoad) {
                        cars[it] = currTime;
                    }
                    
                    currLoad.clear();
                    curr = "right";
                }
            } else {
                if (!right.empty() && right.front().second <= currTime && currLoad.size() < n) {
                    currLoad.push_back(right.front().first);
                    right.pop();
                } else {
                    currTime += t;
                    for (auto it : currLoad) {
                        cars[it] = currTime;
                    }
                    currLoad.clear();
                    curr = "left";
                }
            }
        }
        
        // Can be improved by hashing instead
        for (int i = 0; i < m; i++) {
            cout << cars[i] << endl;
        }
        cout << endl;
    }
}
