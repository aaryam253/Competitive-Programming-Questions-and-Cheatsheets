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

#ifdef _WIN32
#define getchar_unlocked getchar
#endif
// DO NOT REMOVE THE CODE ABOVE
#include <cstdio>

inline int getint(){
    char c;
    while ((c = getchar_unlocked()) <= ' ');
    int v = 0;
    do { v = (v << 3) + (v << 1) + (c ^ '0'); }
    while ((c = getchar_unlocked()) >= '0' && c <= '9');
    return v;
}


vector<int> dist;
list<pair<int, int>> AL[100000];
int v, e, t;


int dijkstra (int cap) {
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
    dist = vector<int>(v, MAX);
    dist[0] = 0;
    pq.push({0, 0});
    
    while (!pq.empty()) {
        pair<int, int> curr = pq.top();
        pq.pop();
        if (dist[curr.second] < curr.first) continue;
        
        for (auto it : AL[curr.second]) {
            if (it.first > cap) continue; // edge cap implementation

            if (dist[it.second] > dist[curr.second] + it.first) {
                dist[it.second] = dist[curr.second] + it.first;
                pq.push({dist[it.second], it.second});
            }
        }
    }
    
    return dist[v-1];
}



int main(){
    v = getint();
    e = getint();
    t = getint();

    vector<int> edges;
    for (int i = 0; i < e; i++) {
        int a, b, w;
        a = getint();
        b = getint();
        w = getint();

        AL[a-1].push_back({w,b-1});
        AL[b-1].push_back({w,a-1});
        edges.push_back(w);
    }
    sort(edges.begin(), edges.end());
    // Change this to binary search instead of linear search
    
    int min_path = dijkstra(MAX);
    
    int p1 = 0;
    int p2 = edges.size()-1;
    while (p1+1 < p2) {
        int mid = p1 + (p2 - p1)/2;
        int edge_cap = edges[mid];
        int shortest = dijkstra(edge_cap);
        
        
        if (shortest <= (((double)t+100.0)/100)*min_path) {
            p2 = mid;
        } else {
            p1 = mid;
        }

    }
    cout << edges[p2] << endl;
    return 0;
}



