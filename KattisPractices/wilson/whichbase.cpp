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
#include <algorithm>


using namespace std;

int octalToDecimal(long long octalNumber) {

    int decimal = 0, i = 0;
    while(octalNumber != 0)
    {
        if (octalNumber % 10 > 7) return 0;
        decimal = decimal + (octalNumber % 10) * pow(8,i++);
        octalNumber = octalNumber/10;
    }
    return decimal;
}


int hexaToDecimal (long long hexNumber) {
    int decimal = 0, i = 0;
    while (hexNumber != 0) {
        decimal += pow(16, i++) * (hexNumber % 10);
        hexNumber /= 10;
    }
    return decimal;
}


int main () {
    int TC; cin >> TC;
    while (TC--) {
        long long number; cin >> number;
        long long num; cin >> num;
        cout << number << " ";
        cout << octalToDecimal(num) << " " << num << " " << hexaToDecimal(num) << endl;
        
    }
}
