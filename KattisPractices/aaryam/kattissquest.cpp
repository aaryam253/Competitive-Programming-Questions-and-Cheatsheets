#include <bits/stdc++.h>
using namespace std;



int main() {
    int n; cin >> n;
    
    map<int, priority_queue<int>> pool; // pool of events
    
    while (n--) {
        string s; cin >> s;
        
        if (s == "add") {
            int e, g; cin >> e >> g;
            pool[e].push(g);
        } else { // query
            int X; cin >> X;
            long long gold = 0;
            
            while (X > 0 && !pool.empty()) {
                auto it = pool.upper_bound(X); //quest which requires energy level JUST ABOVE X
                
                if (it == pool.begin()) break;
                it--; //decrement iterator in order to point to the quest that requires less than or equal to energy than X
                
                X -= it->first; // use up energy
                gold += it->second.top(); // add up gold
                it->second.pop(); // remove that quest from your priority queue
                
                if (it->second.empty()) pool.erase(it);
            }
            
            cout << gold << endl;
        }
    }
    
    
    
    return 0;
}
