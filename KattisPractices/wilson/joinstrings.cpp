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

#define MAX 2147483646

#ifdef _WIN32
#define getchar_unlocked getchar
#endif
// DO NOT REMOVE THE CODE ABOVE
#include <cstdio>

using namespace std;



int main () {
    unordered_map<int, list<string>> mymap;
    int N; cin >> N;
    
    
    for (int i = 0; i < N; i++) {
        string input; cin >> input;
        mymap[i+1].push_back(input);
    }
    int a, b;
    while (cin >> a >> b) {
        mymap[a].splice(mymap[a].end(), mymap[b]);
        mymap.erase(b);
    }
    
    auto it = mymap.begin();
    for (auto it2 : (*it).second) {
        cout << it2;
    }
    cout << endl;
}
