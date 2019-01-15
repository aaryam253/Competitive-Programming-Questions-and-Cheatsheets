#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <sstream>
#include <iterator>
#include <string>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <stack>
#include <cmath>
#include <utility>
#define LSOne(S) (S & (-S))
#define INTMAX 1000000001
using namespace std;

typedef unsigned long long ull;
typedef pair<int, string> ps;
typedef pair<int, int> ii;
typedef pair<double, double> pd;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef vector<vector<int>> vvi;
typedef vector<vector<ll>> vvll;
typedef priority_queue<int, vector<int>, greater<>> pqmin;

vi labinspect(100000), degree(100000); vvi dependencies(100000);

int toposort(int lab, int n) {
    queue<int> q[2];
    
    for (int i = 0; i < n; i++) degree[i] = 0;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < dependencies[i].size(); j++) degree[dependencies[i][j]]++;
    }
    for (int i = 0; i < n; i++) {
        if (degree[i] == 0) q[labinspect[i]].push(i);
    }
    
    int transits = 0;
    
    while (q[0].size() + q[1].size() > 0) {
        if (q[lab].empty()) {
            lab = !lab; transits++;
        }
        int u = q[lab].front();
        q[lab].pop();
        for (int i = 0; i < dependencies[u].size(); i++) {
            int v = dependencies[u][i]; degree[v]--;
            if (degree[v] == 0) q[labinspect[v]].push(v);
        }
    }

    return transits;
}

int main (void) {
    int t; scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        int n, m; scanf("%d %d", &n, &m);
        for (int j = 0; j < n; j++) {scanf("%d", &labinspect[j]); labinspect[j]--;}
        for (int j = 0; j < m; j++) {
            int a,b; scanf("%d %d", &a, &b);
            dependencies[a-1].push_back(b-1);
        }
        int lab1 = toposort(0, n);
        int lab2 = toposort(1, n);
        
        if (lab1 > lab2) printf("%d\n", lab2);
        else printf("%d\n", lab1);
        
        for (int i = 0; i < n; i++) {
            vi clear; dependencies[i].swap(clear);
        }
    }
    
    return 0;
}
