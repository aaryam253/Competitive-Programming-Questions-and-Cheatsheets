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
    int N; cin >> N;
    while (N--) {
        double a, b; cin >> a >> b;
        double act = 60.0*(a/b);
        double ac = 60.0/b;
        
        cout << act - ac << " " << act << " " << act + ac << endl;
    }
}
