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
    int x, y; cin >> x >> y;
    if (x == 0 && y == 1) cout << "ALL GOOD";
    
    else if (y == 1) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        float point = (float)x/(1-y);
        printf("%0.7f", point);
    }
    
}
