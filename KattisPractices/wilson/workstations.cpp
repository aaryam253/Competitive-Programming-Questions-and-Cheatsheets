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


int main() {
    int n, m; cin >> n >> m;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    for (int i = 0; i < n; i++) {
        int a, s; cin >> a >> s;

        pq.push({a,s});
    }
    int count = 0;
    
    multiset<int> timings;
    
    while (!pq.empty()) {
        pair<int, int> curr = pq.top();
        pq.pop();
        
        auto it2 = timings.lower_bound(curr.first-m);
        
        if (it2 != timings.end() && *it2 <= curr.first) {
            timings.erase(it2);
            count++;
        }
        timings.insert(curr.first+curr.second);

    }
    
    
    cout << count << endl;
}



