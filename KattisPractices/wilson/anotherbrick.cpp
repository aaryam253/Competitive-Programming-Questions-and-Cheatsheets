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
    int h, w, n; cin >> h >> w >> n;
    int count = 0;
    int width = w;
    while (n--) {
        int brick; cin >> brick;
        if (width > brick) {
            // Place
            width -= brick;
        } else if (width == brick) {
            width = w; // reset
            count++;
        } else {
            break;
        }
    }
    if (count >= h) cout << "YES" << endl;
    else cout << "NO" << endl;
}


