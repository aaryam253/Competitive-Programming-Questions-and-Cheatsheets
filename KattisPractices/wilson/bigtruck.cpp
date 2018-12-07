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
    list<pair<int, int>> AL[200];
    int items[200];
    int cities;
    cin >> cities;
    for (int i = 0; i < cities; i++) {
        cin >> items[i];
    }
    
    int roads; cin >> roads;
    while (roads--) {
        int a, b, d; cin >> a >> b >> d;
        a -= 1;
        b -= 1;
        AL[a].push_back({b,d}); // vertex, weight
        AL[b].push_back({a,d});
    }
    
    vector<pair<int, int>> added_weight (cities, {MAX, MAX});
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<> > q; // Becareful of this
    added_weight[0] = {0, items[0]*-1};
    
    q.push({0, items[0]*-1, 0});
    
    while (!q.empty()) {
        tuple<int, int, int> curr = q.top();
        q.pop();
        int current = get<2>(curr);
        if (added_weight[current].first < get<0>(curr)) continue;
        
        for (auto it : AL[current]) {
            // Relax
            
            if (added_weight[it.first].first > added_weight[current].first + it.second) {
                added_weight[it.first].first = added_weight[current].first + it.second;
                added_weight[it.first].second = added_weight[current].second - items[it.first];

                // Keeps pushing into the pq, may contain duplicates
                q.push({added_weight[it.first].first, added_weight[it.first].second, it.first});

            } else if (added_weight[it.first].first == added_weight[current].first + it.second) {
                if (added_weight[it.first].second > added_weight[current].second  - items[it.first]) {
                    added_weight[it.first].second = added_weight[current].second - items[it.first];

                    q.push({added_weight[it.first].first, added_weight[it.first].second, it.first});
                }
            }
            
        }
    }
    
    if (added_weight[cities - 1].first == MAX) cout << "impossible" << endl;
    else cout << added_weight[cities - 1].first << " " << (-1*added_weight[cities - 1].second) << endl;
}


