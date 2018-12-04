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


double euclideanDistance (int x1, int y1, int x2, int y2) {
    int diffX = x1 - x2;
    int diffY = y1 - y2;
    return sqrt(pow(diffX,2) + pow(diffY, 2));
}

int main () {
    int cx, cy, n; cin >> cx >> cy >> n;
    vector<int> distances;
    
    while (n--) {
        int x, y, r; cin >> x >> y >> r;
        int dist = euclideanDistance(cx, cy, x, y) - r;
        distances.push_back(dist);
    }
    
    sort(distances.begin(), distances.end());
    
    
    cout << max(0, distances[2]) << endl;
    
}
