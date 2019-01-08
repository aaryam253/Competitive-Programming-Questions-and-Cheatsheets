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

#define MAX 2147483640

using namespace std;


int main () {
    int N, Q; cin >> N >> Q;
    vector<int> origin;
    for (int i = 0; i < N; i++) {
        int a; cin >> a;
        origin.push_back(a);
    }
    
    while (Q--) {
        int a, b, c; cin >> a >> b >> c;
        if (a == 1) {
            origin[b-1] = c;
        } else {
            cout << abs(origin[b-1]-origin[c-1]) << endl;
        }
    }
    
}
