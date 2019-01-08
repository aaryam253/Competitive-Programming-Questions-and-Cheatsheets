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
        int index; cin >> index;
        int base; cin >> base;
        int num; cin >> num;
        long long total = 0;
        
        while (num) {
            int r = num%base;
            num = num/base;
            total += pow(r, 2);
        }
        cout << index << " " <<  total << endl;
        
    }
}
