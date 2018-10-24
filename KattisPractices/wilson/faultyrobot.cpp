#include <iostream>
#include <queue>
#include <set>
#include <unordered_set>
#include <list>

using namespace std;

list<pair<int, int> > AL[100000];
unordered_set<int> visited;
unordered_set<int> forced_moves;
unordered_set<int> stop_point;

void dfs (int v, int check) {
    if (visited.find(v) != visited.end()) return;
    
    visited.insert(v);
    
    if (forced_moves.find(v) == forced_moves.end() || AL[v].empty()) {
        stop_point.insert(v);
    }
    
    for (auto it : AL[v]) {
        if (it.first == 1) dfs(it.second, 0); // reset the check
        else if (check == 0) dfs(it.second, 1);
    }
}


int main () {
    int n, m; cin >> n >> m;
    while (m--) {
        int a, b;
        cin >> a >> b;
        if (a < 0) {
            AL[-a].push_back(make_pair(1, b)); // forced move
            forced_moves.insert(-a);
        }else {
            AL[a].push_back(make_pair(0, b));
        }
    }
    /*
    if (forced_moves.find(1) != forced_moves.end())
        dfs(1, 0);
    else
        dfs(1, 1);
    */
    //dfs(1, 0);
    dfs(1, 0);
    /*
    for (auto it : visited) {
        cout << it << " ";
    }
    cout << endl;
     */
    //cout << visited.size() << endl;
     cout << stop_point.size() << endl;
}
