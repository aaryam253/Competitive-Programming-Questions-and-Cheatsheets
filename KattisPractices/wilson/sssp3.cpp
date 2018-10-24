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

const long long INF = 2000000000000;

using namespace std;


void bellman_ford (int s, vector<long long> *added_weight, list<pair<long long, int> > AL[],  unordered_set<int> *neg_cycle, int numv) {
    
    added_weight->operator[](s) = 0;
    // 3 for loops :o
    for (int i = 0; i < numv - 1; i++) {
        // Relax the edges numv - 1 times (max number of possible edges is numv - 1)
        
        for (int d = 0; d < numv; ++d)
        {
            int v = d;
            for (auto it = AL[d].begin(); it != AL[d].end(); it++) {
                
                int v2 = it->second;
                long long w = it->first;
                
                // Relax
                if (added_weight->operator[](v2) > added_weight->operator[](v) + w) {
                    added_weight->operator[](v2) = added_weight->operator[](v) + w;
                }
                
            }
            
        }
    }
    // Neg cycles checker
    bool ch = true;
    
    while (ch) {
        ch = false;
        for (int u = 0; u < numv; u++) {
            // one more pass to check
            if (added_weight->operator[](u) >= INF) continue;
            for (auto it : AL[u]) {
                if (added_weight->operator[](it.second) > added_weight->operator[](u) + it.first && neg_cycle->find(it.second) == neg_cycle->end()) {
                    // should be false
                    //neg_cycle->insert(u);
                    added_weight->operator[](it.second) = -INF;
                    ch = true;
                    neg_cycle->insert(it.second);
                }
            }
        }
    }
}




int main () {
    while (true) {
        int numv;
        cin >> numv;

        list<pair<long long, int> > AL[numv + 10];
        vector<long long> added_weight (numv + 10, INF);
        unordered_set<int> neg_cycle;

        int m, q, s; cin >> m >> q >> s;
        if (!m && !numv && !q && !s) break;
        
        while (m--) {
            int u, v, w;
            cin >> u >> v >> w;
            AL[u].push_back(make_pair((long long)w, v));
        }
        
        bellman_ford(s, &added_weight, AL, &neg_cycle, numv);
        
        while (q--) {
            int d;
            cin >> d;
            if (neg_cycle.find(d) == neg_cycle.end()) {
                if (added_weight[d] >= INF) {
                    cout << "Impossible" << endl;
                }else {
                    cout << added_weight[d] << endl;
                }
            } else {
                cout << "-Infinity" << endl;
            }
        }
        cout << endl;
    }
    
}

