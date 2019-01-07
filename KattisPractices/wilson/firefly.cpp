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

#define MAX 2147483640

using namespace std;


int main () {
    int N, H; cin >> N >> H;
    vector<int> s; // floor
    vector<int> t; // ceiling
    
    bool flag = true;
    while (N--) {
        if (flag) {
            int num; cin >> num;
            s.push_back(num);
            flag = false;
        } else {
            int num; cin >> num;
            t.push_back(num);
            flag = true;
        }
    }
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    
    int minimium = MAX;
    int levels = 0;
    for (int i = 1; i <= H; i++) {
        // Brute force
        int combined = (s.end() - lower_bound(s.begin(), s.end(), i)) + (t.end() - lower_bound(t.begin(), t.end(), H-i + 1));
    
        if (combined < minimium) {
            minimium = combined;
            levels = 1;
        } else if (combined == minimium) {
            levels++;
        }
        
    }
    cout << minimium << " " << levels << endl;
}
