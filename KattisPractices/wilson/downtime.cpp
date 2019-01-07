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

using namespace std;

vector<int> timing (100005, 0);

int main () {
    int n, k; cin >> n >> k;
    int maxRequest = 0;
    while (n--) {
        int t; cin >> t;
        for (int i = t; i < t+1000 && i < timing.size(); i++) {
            timing[i]++;
        }
    }
    
    for (auto it : timing) {
        maxRequest = max(maxRequest, it);
    }
    
    cout << ceil(maxRequest/(float)k) << endl;
}
