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
    int n; cin >> n;
    unordered_map<string, int> freq;
    while (n--) {
        string input; cin >> input;
        freq[input]++;
    }
    
    int minNum = 100000000;
    for (auto it : freq) {
        if (it.second < minNum) {
            minNum = it.second;
        }
    }
    vector<string> v;
    for (auto it : freq) {
        if (it.second == minNum)
            v.push_back(it.first);
    }
    sort(v.begin(), v.end());
    for (auto it : v) {
        cout << it << endl;
    }
}


