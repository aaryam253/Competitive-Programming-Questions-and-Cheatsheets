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
    int T; cin >> T;
    while (T--) {
        float a, b, c; cin >> a >> b >> c;
        if (a + b == c) {
            cout << "Possible" << endl;
            continue;
        }
        if (a / b == c) {
            cout << "Possible" << endl;
            continue;
        }
        if (b / a == c) {
            cout << "Possible" << endl;
            continue;
        }

        if (a * b == c) {
            cout << "Possible" << endl;
            continue;
        }
        if (abs(a - b) == c) {
            cout << "Possible" << endl;
            continue;
        }
        cout << "Impossible" << endl;

    }
}
