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

#define MAX 2147483646

using namespace std;


int main () {
    int TC; cin >> TC;
    while (TC--) {
        int totalDays; cin >> totalDays;
        int months; cin >> months;
        // need to know what's the date at the start of each month
        int totalFridays = 0;
        int currentDate = 0;
        for (int i = 0; i < months; i++) {
            int days; cin >> days;
//            cout << currentDate + 12 << endl;
            if (days >= 13) {
                if ((currentDate + 13) % 7 == 6) totalFridays++;
            }
            currentDate = days + currentDate;
        }
        cout << totalFridays << endl;
//        cout << "=======" << endl;
    }
}
