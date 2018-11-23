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

int main () {
    int TC; cin >> TC;
    while (TC--) {
        double currCap = 0;
        string curr = "left";
        int l, m; cin >> l >> m;
        queue<int> left, right;
        int turns = 0;
        while (m--) {
            int len; cin >> len;
            string direction; cin >> direction;
            if (direction == "left") left.push(len);
            else right.push(len);
        }
        
        while (true) {
//            cout << "left" << left.size() << endl;
//            cout << "right" << right.size() << endl;
            if (curr == "left") {
                bool flag = false;
                while (!left.empty()) {
                    int car = left.front();
                    if (currCap + car/100.0 <= l) {
                        currCap += car/100.0;
                        left.pop();
                    } else {
                        flag = true;
                        break;
                    }
                    
                }
                if (left.empty() || flag) {
                    turns++;
                    currCap = 0;
                    curr = "right";
                }
            } else {
                bool flag = false;
                while (!right.empty()) {
                    int car = right.front();
                    if (currCap + car/100.0 <= l) {
                        currCap += car/100.0;
                        right.pop();
                    } else {
                        flag = true;
                        break;
                    }
                }
                if (right.empty() || flag) {
                    turns++;
                    currCap = 0;
                    curr = "left";
                }
            }
            if (right.empty() && left.empty()) {
                break;
            }
        }
        cout << turns << endl;
        
    }
}
