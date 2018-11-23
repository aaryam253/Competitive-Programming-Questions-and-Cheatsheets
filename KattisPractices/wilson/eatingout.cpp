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
    int arr[100001] = {};
    int m, a, b, c; cin >> m >> a >> b >> c;
    int count = 0;
    while (a--) {
        arr[count]++;
        count++;
        count %= m;
    }
    while (b--) {
        arr[count]++;
        count++;
        count %= m;
    }
    while (c--) {
        arr[count]++;
        count++;
        count %= m;
    }

    bool possible = true;
    for (int i = 0; i < m; i++) {
        if (arr[i] >= 3) {
            possible = false;
        }
    }
    
    if (possible) {
        cout << "possible" << endl;
    } else {
        cout << "impossible" << endl;
    }
}
