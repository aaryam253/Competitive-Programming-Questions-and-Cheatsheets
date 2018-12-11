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
    // time to explode - 210s
    int index; cin >> index;
    index -= 1;
    int n; cin >> n;
    int time = 0;
    while (n--) {
        int currTime; cin >> currTime;
        char outcome; cin >> outcome;
        
        time += currTime;
        if (time > 210) break;
        if (outcome == 'T') {
            // Move on
            index = (index + 1) % 8;
        }
    }
    
    cout << index + 1 << endl;
}
