#include <iostream>
#include <fstream>
#include <iomanip>
#include <map>
#include <set>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <sstream>
#include <iterator>
#include <list>
#include <string>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <stack>
#include <cmath>
#include <utility>
#define LSOne(S) (S & (-S))
#define INTMAX 1e9
using namespace std;

typedef unsigned long long ull;
typedef pair<int, string> ps;
typedef pair<int, int> ii;
typedef pair<double, double> pd;
typedef tuple<int, int, int> iii;
typedef tuple<int, int, int, int> iiii;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef vector<vector<int>> vvi;
typedef vector<vector<ll>> vvll;
typedef priority_queue<int, vector<int>, greater<>> pqmin;

void fast() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

void file() {
    auto a = freopen("input.in",  "r", stdin);
    auto b = freopen("output.out", "w", stdout);
    if(!a || !b) cout << "Something wrong with your files :(" << endl;
}

int main() {
    fast();
    int n,s,t; cin >> n >> s >> t;
    
    vvi AL(n, vi(n));
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> AL[i][j];
        }
    }
    
    // Run BFS-SSSP algo
    vi dist(n, INTMAX); dist[s] = 0;
    set<ii> pq; pq.insert(ii(0, s));
    
    while (!pq.empty()) {
        ii front = *pq.begin(); pq.erase(pq.begin());
        int d = front.first, u = front.second;
        
        for (int j = 0; j < n; j++) {
            if (j == u) continue;
            if (dist[u] + AL[u][j] < dist[j]) {
                pq.erase(ii(dist[j], j));
                dist[j] = dist[u] + AL[u][j];
                pq.insert(ii(dist[j], j));
            }
        }
    }
    
    cout << dist[t] << endl;
    
    return 0;
}
