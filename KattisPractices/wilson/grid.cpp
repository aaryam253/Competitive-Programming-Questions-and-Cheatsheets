#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <queue>
#include <map>

using namespace std;



int main () {
    int inf = 2 << 28;
    int mtx[600][600];
    int added_weights [600][600];
    queue<pair<int, int> > q;
    int n, m; cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string input;
        cin >> input;
        int d = 0;
        for (auto it : input) {
            added_weights[i][d] = inf;
            mtx[i][d++] = it - '0';
        }
    }
    
    added_weights[0][0] = 0;
    q.push(make_pair(0, 0));
    
    
    
    while (!q.empty()) {
        pair<int, int> curr = q.front();
        q.pop();
        int x = curr.first, y = curr.second;
        int factor = mtx[y][x];
        
        // Scan 4 directions
        if (x + factor < m ) {
            if (added_weights[y][x+factor] >= inf) {
                // if not found
                if (added_weights[y][x+factor] > added_weights[y][x] + 1) {
                    added_weights[y][x+factor] = added_weights[y][x]+ 1;
                    q.push(make_pair(x + factor, y));
                }
            }
        }
        if (x - factor >= 0) {
            if (added_weights[y][x-factor] >= inf) {
                // if not found
                if (added_weights[y][x-factor] > added_weights[y][x] + 1) {
                    added_weights[y][x-factor] = added_weights[y][x]  + 1;
                    q.push(make_pair(x - factor, y));
                }
            }
        }

        if (y + factor < n ) {
            if (added_weights[y+factor][x] >= inf) {
                // if not found
                if (added_weights[y+factor][x] > added_weights[y][x] + 1) {
                    added_weights[y+factor][x] = added_weights[y][x]+ 1;
                    q.push(make_pair(x, y + factor));
                }
            }
        }

        if (y - factor >= 0 ) {
            if (added_weights[y-factor][x] >= inf) {
                // if not found
                if (added_weights[y-factor][x] > added_weights[y][x]+ 1) {
                    added_weights[y-factor][x] = added_weights[y][x] + 1;
                    q.push(make_pair(x, y - factor));
                }
            }
        }
        
    }
    if (added_weights[n-1][m-1] >= inf) cout << -1 << endl;
    else cout << added_weights[n-1][m-1] << endl;
    
}
