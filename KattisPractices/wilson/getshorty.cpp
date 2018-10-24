#include <iostream>
#include <stdio.h>
#include <list>
#include <math.h>
#include <vector>
#include <set>
#include <queue>

using namespace std;

class mygraph {
public:
    list<pair<long double, int> > AL[100000];
    
    long double perform_djikstra (int source, int numv) {
        // Init a vector of sized numv all with values of 1000000
        vector<long double> added_weight(numv, 1000000);
        
        // Notice we use a BST instead for this one
        set<pair<long double, int> > q;
        // Init source to 0
        added_weight[source] = 0;
        q.insert(make_pair(0, source));
        
        while (!q.empty()) {
            int current = q.begin()->second;
            q.erase(q.begin());
            
            for (auto it = AL[current].begin(); it != AL[current].end(); it++) {
                
                // Relax
                int v = it->second;
                long double weight_curr = added_weight[current];
                
                // -log for larger factor when fraction is smaller
                if (added_weight[v] > weight_curr + -log10(it->first)) {
                    added_weight[v] = weight_curr + -log10(it->first);
                    q.insert(make_pair(added_weight[v], it->second));
                    //cout << v << " " << added_weight[v] << " " << -log10(it->first) << endl;
                }
            }
        }
        
        return added_weight[numv-1];
    }
    

};



int main () {
    int n, m;
    while (true) {
        mygraph newgraph;
        cin >> n >> m;
        if (!n && !m) return 0;
        for (int i = 0; i < m; i++) {
            int x, y;
            long double f;
            cin >> x >> y >> f;
            newgraph.AL[x].push_back(make_pair(f, y));
            newgraph.AL[y].push_back(make_pair(f, x));
        }
        printf("%.4Lf\n", pow(10, -newgraph.perform_djikstra(0, n)) );
    }
}

