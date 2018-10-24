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

#define MAX 2147483646

using namespace std;

int main () {
    int B = 0;
    int W = 0;
    string input; cin >> input;
    
    for (auto it : input) {
        if (it == 'B') B++;
        if (it == 'W') W++;
    }
    
    if (W == B) cout << 1 << endl;
    else cout << 0 << endl;
}
