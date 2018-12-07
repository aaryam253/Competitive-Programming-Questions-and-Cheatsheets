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


int main () {
    double totalDouble;
    double rateDouble;
    double monthlyDouble;
    
    int TC; cin >> TC;
    
    while (TC--) {
        cin >> rateDouble;
        cin >> totalDouble;
        cin >> monthlyDouble;
        
        long long total;
        long long rate;
        long long monthly;
        
        total = totalDouble * 100.0  + 0.5;
        rate = rateDouble * 100.0 + 0.5;
        monthly = monthlyDouble * 100.0 + 0.5;
        
        int i = 0;
        for (i = 1; i <= 1200; i++) {
            
            long long balance_ = rate * total;
            int round_up = balance_ % 10000 >= 5000;
            total += balance_ / 10000 + round_up;
            total -= monthly;
            
            if (total <= 0) {
                break;
            }
        }
        if (i > 1200) {
            cout << "impossible" << endl;
        } else {
            cout << i << endl;
        }
    }
}


