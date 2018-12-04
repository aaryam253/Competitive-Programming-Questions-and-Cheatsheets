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
        unordered_map<string, int> f;
        while (n--) {
            string input; cin >> input;
            int num; cin >> num;
            if (f[input] == 0)
                f[input] = num;
            else
                f[input] += num;
        }
        vector<pair<int, string>> v;
        for (auto it : f) {
            v.push_back({-it.second, it.first});
        }
        sort(v.begin(), v.end());
        cout << v.size() << endl;
        for (auto it : v) {
            cout << it.second << " " << -it.first << endl;
        }
    }
}


