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
    vector<string> d, kat;
    
    for (int i = 0; i < n; i++) {
        string input; cin >> input;
        d.push_back(input);
    }
    for (int i = 0; i < n; i++) {
        string input; cin >> input;
        kat.push_back(input);
    }
    
    sort(d.begin(), d.end());
    sort(kat.begin(), kat.end());
    
    int match = 0;
    
    while (d.size() > 0 && kat.size() > 0) {
        if(kat.back() == d.back()) {
            d.pop_back();
            kat.pop_back();
            match++;
        } else if(kat.back() < d.back()) {
            d.pop_back();
        } else {
            kat.pop_back();
        }
    }
    
    cout << match << endl;
}
