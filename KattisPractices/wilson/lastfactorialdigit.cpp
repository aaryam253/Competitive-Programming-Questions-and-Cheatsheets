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
    int T; cin >> T;
    while (T--) {
        int num; cin >> num;
        int total = num;
        total %= 10;
        for (int i = num - 1; i >= 1; i--) {
            total *= i%10;
            total %= 10;
        }
        cout << total << endl;
        
    }
}
