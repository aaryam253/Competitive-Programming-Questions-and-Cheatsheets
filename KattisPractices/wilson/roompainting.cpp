#include <iostream>
#include <stdio.h>
#include <stdarg.h>
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


using namespace std;

int main () {
    int n, m; cin >> n >> m;
    vector<int> paints;
    unsigned long long wastage = 0;
    while (n--) {
        int size; cin >> size;
        paints.push_back(size);
    }
    sort(paints.begin(), paints.end());

    while (m--) {
        int size; cin >> size;
        wastage += (*lower_bound(paints.begin(), paints.end(), size) - size);
    }
    
    cout << wastage << endl;
    
}
