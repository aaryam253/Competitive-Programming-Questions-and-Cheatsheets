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

using namespace std;


int main () {
    // Circular
    // Both will move clockwise
    int n; cin >> n;
    int i = 0;
    int d = n-2;
    int count = 1;
    while (true) {
        if (abs(i - d) <= 1 || (n - (abs(d - i))) <= 1) {
            break;
        } else {
            i += 2; i %= n;
            d++; d %= n;
//            cout << i << " " << d << endl;
            count++;
        }
    }
    
    cout << count << endl;
}
