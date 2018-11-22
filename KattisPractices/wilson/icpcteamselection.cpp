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

using namespace std;

int main () {
    int T; cin >> T;
    while (T--) {
        int N; cin >> N;
        vector<int> scores;
        for (int i = 0; i < N*3; i++) {
            int score; cin >> score;
            scores.push_back(score);
        }
        sort(scores.rbegin(), scores.rend());
        int sum = 0;
        for (int i = 0; i < N; i++) {
            sum += scores[i*2+1];
        }
        cout << sum << endl;
    }
}
