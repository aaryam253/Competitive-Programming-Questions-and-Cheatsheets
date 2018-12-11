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
    int W; cin >> W;
    int N; cin >> N;
    long long totalArea = 0;
    while (N--) {
        int w, l; cin >> w >> l;
        totalArea += w*l;
    }
    
    cout << totalArea/W << endl;
}
