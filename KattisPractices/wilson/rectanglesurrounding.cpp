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


using namespace std;

int main () {
    
    while (true) {
        int N; cin >> N;
        if (!N) return 0;
        int mtx[500][500] = {{0}};
        int occupancyCount = 0;
        while (N--) {
            int a,b,c,d;
            cin >> a >> b >> c >> d;
            for (int i = a; i < c; i++) {
                for (int j = b; j < d; j++) {
                    if (!mtx[i][j]) {
                        mtx[i][j] = true;
                        occupancyCount++;
                    } else {
                        // pass it
                    }
                }
            }

        }
        cout << occupancyCount << endl;
    }
}
