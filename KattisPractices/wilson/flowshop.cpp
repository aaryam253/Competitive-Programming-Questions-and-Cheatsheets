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
    int N, stages; cin >> N >> stages;
    long long timings[1001][1001] = {};
    for (int i = 0; i < N; i++) {
        for (int d = 0; d < stages; d++) {
            cin >> timings[i][d];
        }
    }
    long long timingAdditions [1001][1001] = {};
    for (int i = 0; i < N; i++) {
        if (!i) {
            timingAdditions[0][i] = timings[i][0];
        } else {
            timingAdditions[0][i] = timingAdditions[0][i-1] + timings[i][0];
        }
    }
    
    for (int i = 1; i < stages; i++) {
        timingAdditions[i][0] = timingAdditions[i-1][0] + timings[0][i];
        for (int d = 1; d < N; d++) {
            if (timingAdditions[i-1][d] < timingAdditions[i][d-1]) {
                // if previous timing for d is less than the completion time of this stage
                timingAdditions[i][d] = timings[d][i] + timingAdditions[i][d-1];
            } else {
                timingAdditions[i][d] = timings[d][i] + timingAdditions[i-1][d];
            }
        }
    }
    for (int d = 0; d < N; d++) {
        cout << timingAdditions[stages-1][d] << " ";
    }
    cout << endl;
}
