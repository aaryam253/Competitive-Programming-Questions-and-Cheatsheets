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
#include <iomanip>

#define MAX 2147483640

using namespace std;


int main () {
    long long shares = 0;
    double average = 0;
    
    
    while (true) {
        string input; cin >> input;
        
        if (input == "buy") {
            int x, y; cin >> x >> y;
            average = ((shares*average) + (x*y))/ (double)(shares + x);
            shares += x;
        } else if (input == "sell") {
            int x, y; cin >> x >> y;
            shares -= x;
        } else if (input == "split") {
            int y; cin >> y;
            shares *= y;
            average /= y;
        } else if (input == "merge") {
            int y; cin >> y;
            shares /= y;
            average *= y;
        } else if (input == "die") {
            int y; cin >> y;
            double temp = y - average;
            if (temp < 0) {
                
                cout << fixed << setprecision(2) << y * shares << endl;
            } else {
                // subjected to tax
                cout << fixed << setprecision(2) << (double)(shares * (double)(y - temp * 0.3)) << endl;
            }
            break;
        }
    }
}

