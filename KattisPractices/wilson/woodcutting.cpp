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
    int TC; cin >> TC;
    while (TC--) {
        int N; cin >> N;
        vector<long double> times;
        for (long long i = 0; i < N; i++) {
            int n; cin >> n;
            long long total = 0;
            while (n--) {
                long long num; cin >> num;
                total += num;
            }
            times.push_back(total);
        }
        sort(times.begin(), times.end());
        long double currTime = 0;
        long double sum = 0;
        for (auto it : times) {
            sum += it;
            currTime += sum;
        }
//        cout << currTime << endl;
        cout.precision(9);
        cout << currTime/N << endl;
    }
}
