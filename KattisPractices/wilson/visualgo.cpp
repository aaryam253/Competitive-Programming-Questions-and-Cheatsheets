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
    list<pair<int, int>> AL[15000];
    int V, E; cin >> V >> E;
    
    for (int i = 0; i < E; i++) {
        int u, v, w; cin >> u >> v >> w;
        AL[u].push_back({w, v});
    }
    
    int s, t; cin >> s >> t;
    vector<int> added_weight(V, MAX);
//    priority_queue<pair<int, int>> q;
    set<pair<int, int>> q;
    
    q.insert({0,s});
    added_weight[s] = 0;
    int ways[15000] = {};
    ways[s] = 1;
    
    while (!q.empty()) {
        pair<int, int> curr = *q.begin();
        q.erase(q.begin());
        int current = curr.second;
        
        if (added_weight[current] < curr.first) continue;
        
        for (auto it : AL[current]) {
            if (added_weight[it.second] > added_weight[current] + it.first) {
                
//                added_weight[it.second].clear();
                added_weight[it.second] = (added_weight[current] + it.first);
                // Keeps pushing into the pq, may contain duplicates
                ways[it.second] = ways[current];
                q.insert(make_pair(added_weight[it.second], it.second));
                
            } else if (added_weight[it.second] == added_weight[current] + it.first) {
                
//                added_weight[it.second] = (added_weight[current] + it.first);
//                q.insert(make_pair(added_weight[it.second].front(), it.second)); // May take too much time
                ways[it.second] += ways[current];
            }
            
        }
        
    }
    
    //    cout << added_weight[t].size() << endl;
    cout << ways[t] << endl;
    
}
