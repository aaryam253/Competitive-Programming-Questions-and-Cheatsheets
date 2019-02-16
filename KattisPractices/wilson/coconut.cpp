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

int main () {
    list<pair<int, int>> l;
    // States
    // 0: folded
    // 1: fist
    // 2: palm down
    // pop it off
    
    int s, n; cin >> s >> n;
    
    for (int i = 0; i < n; i++) {
        l.push_back({0, i+1});
    }
    
    auto it = l.begin();
    int count = 1;
    while (l.size() > 1) {
        bool changes = false;
        
        if (it == l.end()) it = l.begin(); // circular
        
        auto curr = *it;
        if (count == s) {
            if (curr.first == 0) {
                // folded
                (*it).first = 1;
                it = l.insert(it, {1, curr.second});
                changes = true;
            } else if (curr.first == 1) {
                // fist
                (*it).first = 2;
            } else if (curr.first == 2) {
                // palm down - milk
//                cout << (*it).second << " ";
                it = l.erase(it);
//                if (it == l.end()) it = l.begin(); // circular
//                cout << (*it).second << endl;
                changes = true;
            }
            count = 0;
        }
        count++;
        if (!changes)
            it++;
    }
    
    cout << l.front().second << endl;
}
