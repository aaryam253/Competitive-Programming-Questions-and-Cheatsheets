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
    int TC, num; cin >> TC >> num;
    int mainCount = 0;
    while (TC--) {
        int count = 0;
        for (int i = 0; i < num; i++) {
            string input; cin >> input;
            bool go = true;
            for (int d = 0; d < input.size(); d++) {
                if (d == 0) {
                    
                } else if (isupper(input[d])){
                    go = false;
                    break;
                }
            }
            if (go) count++;
        }
        if (count == num) mainCount++;
    }
    
    cout << mainCount << endl;
}
