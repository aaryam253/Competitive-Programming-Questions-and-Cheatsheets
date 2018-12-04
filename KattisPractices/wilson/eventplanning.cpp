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

#define MAX 1e9

using namespace std;


int main () {
    int n, b, h, w; cin >> n >> b >> h >> w;
    
    long long best = 2147483640;
    
    for (int i = 0; i < h; i++) {
        int price; cin >> price;
        for (int j = 0; j < w; j++) {
            int beds; cin >> beds;
            if (beds >= n) {
                long long totalCost = price * n;
                
                if (totalCost < best) best = totalCost;
            }
        }
    }
    if (best <= b) cout << best << endl;
    else cout << "stay home" << endl;
    
}


