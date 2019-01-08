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
    int N, K; cin >> N >> K;
    vector<pair<int, int>> locationPos;
    vector<pair<int, int>> locationNeg;
    while (N--) {
        int l, a; cin >> l >> a;
        if (l >= 0)
            locationPos.push_back({l,a});
        else
            locationNeg.push_back({-l,a});
    }
    sort(locationPos.begin(), locationPos.end());
    sort(locationNeg.begin(), locationNeg.end());
    
    long long travel = 0;
    while (locationNeg.size() > 0) {
        travel += locationNeg[locationNeg.size()-1].first*2;
        long long letters = K;
        for (int i = locationNeg.size()-1; i >= 0; i--) {
            if (letters >= locationNeg[i].second) {
                letters -= locationNeg[i].second;
                locationNeg.pop_back();
            } else {
                locationNeg[i].second -= letters;
                break;
            }
        }
    }
    
    while (locationPos.size() > 0) {
        travel += locationPos[locationPos.size()-1].first*2;
        long long letters = K;
        for (int i = locationPos.size()-1; i >= 0; i--) {
            if (letters >= locationPos[i].second) {
                letters -= locationPos[i].second;
                locationPos.pop_back();
            } else {
                locationPos[i].second -= letters;
                break;
            }
        }

    }
    
    cout << travel << endl;
}
