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
#include <algorithm>


using namespace std;
int n;
const long long LLINF = 2e18;


struct edge {
    int v;
    int t_not;
    int P;
    int d;
};


vector<long long> dijkstra (int s, list<edge> *AL) {
    vector<long long> added_weight (n, LLINF);
    // current_total, connected to
    priority_queue<pair<long long, int>, vector<pair<long long, int> >, greater<> > q;
    
    added_weight[s] = 0;
    q.push(make_pair(0, s));
    
    while (!q.empty()) {
        pair<long long, int> curr = q.top();
        q.pop();
        
        if (added_weight[curr.second] < curr.first) continue;
        
        for (auto it : AL[curr.second]) {
            /*
            if (it.t_not >= curr.first && !it.P) {
                // Relax here
                long long t = it.t_not - curr.first; // waiting time
                if (added_weight[it.v] > added_weight[curr.second] + t + it.d) {
                    // relax
                    added_weight[it.v] = added_weight[curr.second] + t + it.d;
                    q.push(make_pair(added_weight[it.v], it.v));
                }
            }else if (it.P){
                long long t = curr.first; // waiting time
                t -= it.t_not;
                t %= it.P;
                t = it.P - t;
                
                if (added_weight[it.v] > added_weight[curr.second] + t + it.d) {
                    // relax
                    added_weight[it.v] = added_weight[curr.second] + t + it.d;
                    q.push(make_pair(added_weight[it.v], it.v));
                }
            }
            */
            
            long long dst = LLINF;
            if (it.t_not >= added_weight[curr.second] && it.P == 0)
                dst = it.t_not + it.d;
            else if (it.P > 0) {
                dst = it.t_not + max(0LL, added_weight[curr.second] - it.t_not) / it.P * it.P;
                if (dst < added_weight[curr.second]) dst += it.P;
                dst += it.d;
            }
            if (dst < added_weight[it.v]) {
                added_weight[it.v] = dst;
                q.push({dst, it.v});
            }

        }
    }
    
    return added_weight;
}





int main () {
    while (true) {
        

        int m, q, s;
        cin >> n >> m >> q >> s;
        list<edge> AL[n+1];

        if (!n && !m && !q && !s) break;
        
        while (m--) {
            int u, v, t_not, p, d;
            cin >> u >> v >> t_not >> p >> d;
            AL[u].push_back({v, t_not, p, d});
        }
        vector<long long> added_weight;
        
        added_weight = dijkstra(s, AL);
        
        while (q--) {
            int query; cin >> query;
            if (added_weight[query] >= LLINF) cout << "Impossible" << endl;
            else cout << added_weight[query] << endl;
        }
        cout << endl;
    }
    
}

