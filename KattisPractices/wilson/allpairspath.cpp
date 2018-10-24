#include <iostream>
#include <stdio.h>
#include <list>
#include <math.h>
#include <vector>
#include <set>
#include <queue>
#define MAX 200

using namespace std;


vector<vector<int> > floydWarshall (int V, vector<vector<int> > mtx)
{
    vector<vector<int> > dist (V, vector<int> (V, 100000));
    int i, j, k;
    // Copy the graph to dist
    for (i = 0; i < V; i++)
        for (j = 0; j < V; j++)
            dist[i][j] = mtx[i][j];
    
    
    for (k = 0; k < V; k++)
    {
        for (i = 0; i < V; i++)
        {
            for (j = 0; j < V; j++)
            {
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
    return dist;
}

int main () {
    int n, m, q;
    while (true) {
        cin >> n >> m >> q;
        if (!n && !m && !q) break;
        
        vector<vector<int> > mtx (n, vector<int> (n, 100000));
        while (m--) {
            int u, v, w;
            cin >> u >> v >> w;
            mtx[u][v] = w;
            
        }
        // TODO: add a negative cycle checker
        vector<vector<int> > compiled_dist = floydWarshall(n, mtx);
        
        while (q--) {
            int u, v; cin >> u >> v;
            if (u == v)
                cout << 0 << endl;
            else if (compiled_dist[u][v] >= 100000)
                cout << "Impossible" << endl;
            else
                cout << compiled_dist[u][v] << endl;
        }
        cout << endl;

    }
}
