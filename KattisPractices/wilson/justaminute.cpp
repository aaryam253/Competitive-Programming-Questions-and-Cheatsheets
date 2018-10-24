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
    int N; cin >> N;
    int totalM = 0;
    int totalSec = 0;
    while (N--) {
        int M; cin >> M;
        int sec; cin >> sec;
        totalM += M;
        totalSec += sec;
    }
    double measurement = totalSec/((double)totalM*60);
    if (measurement <= 1) cout << "measurement error" << endl;
    else printf("%0.9lf\n", measurement);
}
