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
    pair<int, int> year_month = {2018, 4}; // 4th month
    
    int year; cin >> year;
    while (true) {
        if (year_month.first == year) {
            cout << "yes" << endl;
            break;
        } else if (year_month.first > year) {
            cout << "no" << endl;
            break;
        }
        int currYear = year_month.first;
        int month = year_month.second;
        currYear += 2;
        month += 2;
        if (month > 12) {
            year_month = {currYear+1, month-12};
        } else {
            year_month = {currYear, month};
        }
    }
}
