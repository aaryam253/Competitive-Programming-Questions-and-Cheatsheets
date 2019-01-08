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

bool isHarshad (long long num) {
    string num_str = to_string(num);
    int total = 0;
    for (auto it : num_str) {
        total += it - '0';
    }
    if (!(num%total)) {
        return true;
    }
        
    return false;
}

int main () {
    long long num; cin >> num;
    for (long long i = num; i <= 1000000000; i++) {
        if (isHarshad(i)) {
            cout << i << endl;
            break;
        }
    }
}
