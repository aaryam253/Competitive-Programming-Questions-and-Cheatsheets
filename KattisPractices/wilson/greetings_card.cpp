#include <iostream>
#include <set>
#include <stdio.h>
#include <math.h>

using namespace std;


double distance_points (long long x1, long long x2, long long y1, long long y2) {
    return sqrt(pow(x1-x2, 2) + pow(y1-y2, 2));
}

int main () {
    
    long long points;
    cin >> points;
    set<pair<long long, long long>> coords;
    
    for (int i = 0; i < points; i++) {
        long long x, y;
        cin >> x >> y;
        coords.insert(make_pair(x, y));
    }

    
    long count = 0;
    for (auto it = coords.begin(); it != coords.end(); ) {
        vector<pair<long long, long long>> a;
        // Whole chunk of mathematical possibilities
        a.push_back({it->first + 0,    it->second + 2018});
        a.push_back({it->first + 1118, it->second + 1680});
        a.push_back({it->first + 1680, it->second + 1118});
        a.push_back({it->first + 2018, it->second + 0});
        a.push_back({it->first + 0,    it->second - 2018});
        a.push_back({it->first + 1118, it->second - 1680});
        a.push_back({it->first + 1680, it->second - 1118});
        
        // Match it up to all possible points
        for (auto it2 = a.begin(); it2 != a.end(); it2++) {
            auto it3 = coords.find(*it2);
            if (it3 != coords.end()) {
                count++;
                //coords.erase(it3);
            }
        }
        // Remove current one and give others a chance to pair up
        it = coords.erase(it);
    }
    
    
    
    cout << count << endl;
    
    return 0;
}
