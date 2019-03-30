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
#include <iomanip>

#define MAX 2147483640

using namespace std;

int main() {
    unordered_map<int, vector<int>> languages;
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        int lang; cin >> lang;
        languages[lang].push_back(i);
    }
    int minimum = n;
    
    for (auto it : languages) {
        if (it.second.size() > 1) {
            for (int i = 0; i < it.second.size() - 1; i+=2) {
                minimum = min(minimum, it.second[i+1]-it.second[i]);
            }
        }
    }
    cout << minimum << endl;
    return 0;
}
