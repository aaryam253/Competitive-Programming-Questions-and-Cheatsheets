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
    int n; cin >> n;
    int index = 0;
    int min = MAX;
    for (int i = 0; i < n; i++) {
        int num; cin >> num;
        if (num < min) {
            index = i;
            min = num;
        }
    }
    
    cout << index << endl;
}
