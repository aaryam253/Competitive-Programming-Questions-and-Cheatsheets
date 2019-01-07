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
    // anything more than or equals to 6 is not explored
    int TC; cin >> TC;
    while (TC--) {
        unordered_map<string, int> stringIndex;
        list<int> AL[4000];
        int M; cin >> M;
        int count = 0;
        while (M--) {
            string a, b; cin >> a >> b;
            if (stringIndex.find(a) == stringIndex.end()) {
                stringIndex[a] = count++;
            }
            if (stringIndex.find(b) == stringIndex.end()) {
                stringIndex[b] = count++;
            }
            
            AL[stringIndex[b]].push_back(stringIndex[a]);
            AL[stringIndex[a]].push_back(stringIndex[b]);
        }
        
        vector<int> counts (count, 0);
        
        for (int i = 0; i < count; i++) {
            vector<int> added_weights(count, MAX);
            added_weights[i] = 0;
            queue<int> q;
            q.push(i);
            
            while (!q.empty()) {
                int curr = q.front();
                q.pop();
                for (auto it : AL[curr]) {
                    if (added_weights[it] == MAX && added_weights[curr] + 1 <= 6) {
                        if (added_weights[it] > added_weights[curr] + 1) {
                            added_weights[it] = added_weights[curr] + 1;
                        }
                        q.push(it);
                    }
                }
            }
            
            for (int i = 0; i < count; i++) {
                if (added_weights[i] == MAX) counts[i]++;
            }
        }
        int maximum = 0;
        for (auto it : counts) {
            maximum = max(it, maximum);
        }
        int removed = 0;
        for (auto it : counts) {
            if (it >= 1) removed++;
        }
        if (removed/(double)count > 0.05) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
        }
        
//        for (auto it : counts) {
//            cout << it << " ";
//        }
//        cout << endl;
    }
}
