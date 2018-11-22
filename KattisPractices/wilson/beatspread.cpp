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
    int num; cin >> num;
    while (num--) {
        int sum, diff; cin >> sum >> diff;
        bool have = false;
        for (int i = 0; i <= sum; i++) {
            for (int j = 0; j <= sum; j++) {
                if (i+j == sum && i-j == diff) {
                    cout << i << " " << j << endl;
                    have = true;
                    break;
                }
            }
        }
        if (!have) {
            cout << "impossible" << endl;
        }
        
    }
}
