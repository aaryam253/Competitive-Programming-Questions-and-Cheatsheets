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
    while (true) {
        int TC; cin >> TC;
        if (TC == -1) break;
        int prev = 0;
        int totalDist = 0;
        for (int i = 0; i < TC; i++) {
            int speed; cin >> speed;
            int hours; cin >> hours;
            totalDist += speed * (hours - prev);
            prev = hours;
        }
        cout << totalDist << " miles" << endl;
        
    }
}
