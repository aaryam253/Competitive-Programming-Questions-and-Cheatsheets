#include <iostream>
#include <stdio.h>
#include <stdarg.h>
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

#define INF 1e9 + 7

using namespace std;

int v;
list<pair<int, int> > AL[10004];
int added_weight[2][10004];;

void perform_dijkstra (int source, int layer) {

    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<> > q;
    // Init source to 0
    added_weight[layer][source] = 0;
    q.push(make_pair(0, source));
    
    while (!q.empty()) {
        pair<int, int> curr = q.top();
        int current = curr.second;
        q.pop();
        
        // If added weight is smaller than weight itself, don't process
        if (added_weight[layer][current] < curr.first) continue;
        
        for (auto it = AL[current].begin(); it != AL[current].end(); it++) {
            // Relax
            if (added_weight[layer][it->second] > added_weight[layer][current] + it->first) {
                
                added_weight[layer][it->second] = added_weight[layer][current] + it->first;
                // Keeps pushing into the pq, may contain duplicates
                q.push(make_pair(added_weight[layer][it->second], it->second));
            }
        }
    }
    
}


int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int e; cin >> v >> e;
    
    while (e--) {
        int a, b, w;
        cin >> a >> b >> w;
        AL[a].push_back(make_pair(w, b));
        AL[b].push_back(make_pair(w, a));
    }
    for (int i = 0; i < 2; i++) {
        for (int d = 0; d < v; d++) {
            added_weight[i][d] = INF;
        }
    }

    
    perform_dijkstra(0, 0);
    perform_dijkstra(v-1, 1);
    
    long long ans = 0;
    
    for (int i = 0; i < v; i++) {
        for (auto it : AL[i]) {
            // Check whether layer 0 weight corresponds && whether it adds up to the total weight to the end point (since there can only be similar shortest paths)
            if (added_weight[0][i] + it.first == added_weight[0][it.second] && added_weight[0][i] + it.first + added_weight[1][it.second] == added_weight[0][v - 1]) {
                ans += it.first;
            }

        }
    }
    
    cout << 2*ans << endl;
}

