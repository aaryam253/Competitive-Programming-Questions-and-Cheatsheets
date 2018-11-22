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
    long long C;
    int N;
    cin >> C >> N;
    bool impossible = false;
    long long current = 0;
    long long stay = 0;
    long long entered = 0;
    while (N--) {
        long long left; cin >> left;
        current -= left;
        if (left < 0) {
            impossible = true;
        }
        
        cin >> entered;
        current += entered;
        if (current > C) {
            impossible = true;
        }
        
        cin >> stay;
        if (stay != 0 && current != C) {
            impossible = true;
        }
    }
    
    if (impossible || current || stay || entered) {
        cout << "impossible" << endl;
    } else {
        cout << "possible" << endl;
    }
    
}
