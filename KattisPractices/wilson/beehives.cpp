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

using namespace std;


int main () {
    while (true) {
        float minDist; cin >> minDist;
        int N; cin >> N;
        if (minDist == 0 && N == 0) break;
        unordered_set<int> isSour;
        vector<pair<float, float>> coords;
        int size = N;
        while (N--) {
            float x, y; cin >> x >> y;
            coords.push_back({x, y});
        }
        
        
        for (int i = 0; i < coords.size(); i++) {
            for (int d = 0; d < coords.size(); d++) {
                if (d != i) {
                    float diffX = fabs(coords[i].first - coords[d].first);
                    float diffY = fabs(coords[i].second - coords[d].second);
                    if (hypot(diffX, diffY) <= minDist) {
                        isSour.insert(i); isSour.insert(d);
                    }
                }
            }
        }
        
        cout << isSour.size() << " sour, " << size - isSour.size() << " sweet" << endl;
    }
}
