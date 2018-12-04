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


double euclideanDist (long double x1, long double y1, long double x2, long double y2) {
    return sqrt(pow(x1-x2, 2) + pow(y1-y2, 2));
}

int main () {
    int TC; cin >> TC;
    
    while (TC--) {
        long double x, y; cin >> x >> y;
        int n; cin >> n;
        bool flag = false;
        
        while (n--) {
            long double xc, yc; cin >> xc >> yc;
            if (euclideanDist(x, y, xc, yc) <= 8.000000001) {
                flag = true;
            }
        }
        
        if (!flag) {
            cout << "curse the darkness" << endl;
        } else {
            cout << "light a candle" << endl;
        }
    }
}


