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
    // 3 cases
    char toiletSeat;
    
    string seats; cin >> seats;
    
    toiletSeat = seats[0];
    
    int adjustments = 0;
    // First policy
    for (int i = 1; i < seats.size(); i++) {
        if (toiletSeat != seats[i]) {
            toiletSeat = seats[i];
            adjustments++;
        }
        
        if (toiletSeat != 'U') {
            // Always leave it up
            adjustments++;
            toiletSeat = 'U';
        }

    }
    cout << adjustments << endl;
    
    adjustments = 0;
    toiletSeat = seats[0];
    for (int i = 1; i < seats.size(); i++) {
        if (toiletSeat != seats[i]) {
            toiletSeat = seats[i];
            adjustments++;
        }
        
        if (toiletSeat != 'D') {
            // Always leave it down
            adjustments++;
            toiletSeat = 'D';
        }

    }
    cout << adjustments << endl;
    
    adjustments = 0;
    toiletSeat = seats[0];
    for (int i = 1; i < seats.size(); i++) {
        if (toiletSeat != seats[i]) {
            toiletSeat = seats[i];
            adjustments++;
        }
    }
    cout << adjustments << endl;

    
}
