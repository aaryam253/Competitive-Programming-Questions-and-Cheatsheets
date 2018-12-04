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
    int TC; cin >> TC;
    while (TC--) {
        int n; cin >> n;
        unsigned long long leftovers = 0;
        unsigned long long input;
        for (int i = 0; i < n; i++) {
            cin >> input;
            leftovers += input % n;
        }
        if (leftovers % n == 0) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}
