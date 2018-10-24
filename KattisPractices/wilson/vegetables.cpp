#include <iostream>
#include <stdio.h>
#include <stdarg.h>
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

#define INTMAX 2147483647

using namespace std;

int main () {
    // Current, original, denom
    priority_queue<tuple<double, long long, int>> cuts;
    double threshold; cin >> threshold;
    int num; cin >> num;
    tuple<double, long long, int> min = make_tuple((double)INTMAX, INTMAX, 1);
    long long totalCuts = 0;
    
    while (num--) {
        int weight; cin >> weight;
        cuts.push(make_tuple((double)weight, weight, 1));
        if (get<0>(min) > (double)weight) {
            min = make_tuple((double)weight, weight, 1);
        }
    }
    
    while (true) {
        tuple<double, long long, int> max = cuts.top();
//        cout << get<0>(min)/get<0>(max) << " " << threshold << endl;
        if (get<0>(min)/get<0>(max) > threshold) {
            while (!cuts.empty()) {
//                cout << get<2>(cuts.top()) << endl;
                totalCuts += get<2>(cuts.top()) - 1;
                cuts.pop();
            }
            cout << totalCuts << endl;
            return 0;
        } else {
            cuts.pop();
            
            int denom = get<2>(max) + 1;
            long long original = get<1>(max);
            double newWeight = original/denom;
            tuple<double, long long, int> newCut = make_tuple(newWeight, original, denom);
            if (newWeight < get<0>(min)) {
                min = newCut;
            }
            cuts.push(newCut);
        }
        
    }
    
}
