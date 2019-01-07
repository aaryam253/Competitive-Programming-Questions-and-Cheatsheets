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
    int ranges; cin >> ranges;
    int arr[1000] = {};
    while (ranges--) {
        int a, b; cin >> a >> b;
        for (int i = a; i <= b; i++) {
            arr[i]++;
        }
    }
    int count = 0;
    for (int i = 0; i < 370; i++) {
        if (arr[i]) count++;
    }
    cout << count << endl;
}
