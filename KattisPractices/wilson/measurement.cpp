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

#define MAX 2147483646

using namespace std;

int main () {
    // Convert it to thous first
    map<string, int> thous {
        {"thou",           1}, {"th",          1},
        {"inch",        1000}, {"in",       1000},
        {"foot",       12000}, {"ft",      12000},
        {"yard",       36000}, {"yd",      36000},
        {"chain",     792000}, {"ch",     792000},
        {"furlong",  7920000}, {"fur",   7920000},
        {"mile",    63360000}, {"mi",   63360000},
        {"league", 190080000}, {"lea", 190080000}
    };
    
    double input;
    string inputType;
    string in;
    string outputType;
    cin >> input >> inputType >> in >> outputType;
    
    double output = input * thous[inputType];
    output /= thous[outputType];
    cout.precision(13);
    cout << output << endl;
    
}
