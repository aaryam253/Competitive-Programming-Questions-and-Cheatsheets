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

#define MAX 2147483646

using namespace std;

int main () {
    int B, B_r, B_s, A, A_s;
    cin >> B >> B_r >> B_s >> A >> A_s;
    int totalB = (B_r - B) * B_s;
    
    int numYears = ceil(totalB/(double)A_s);

    if (numYears * A_s == totalB) {
        numYears++;
    }
    cout << numYears + A << endl;
}
