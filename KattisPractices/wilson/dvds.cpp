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


int main () {
    // Scan the array for the smallest not ordered element
    int TC; cin >> TC;
    while (TC--) {
        vector<int> l;
        int n; cin >> n;
        for (int i = 0; i < n; i++) {
            int number; cin >> number;
            l.push_back(number);
        }
        int count = 0;
        for (int i = 0; i < l.size(); i++) {
            if (l[i] == count + 1) count++;
        }
        cout << l.size() - count << endl;
    }
    
}
