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
    set<vector<int>> s;
    
    int m, n; cin >> m >> n;
    int clause = m;
    while (m--) {
        vector<int> v;
        for (int i = 0; i < n; i++) {
            int num; cin >> num;
        }
    }
    
    if (clause >= 8) {
        cout << "satisfactory" << endl;
    } else {
        cout << "unsatisfactory" << endl;
    }
}
