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
    int dist[10] = {20,40,60,80,100,120,140,160,180,200};
    int scores[10] = {1,2,3,4,5,6,7,8,9,10};
    
    int TC; cin >> TC;
    while (TC--) {
        int throws; cin >> throws;
        int score = 0;
        while (throws--) {
            int x, y; cin >> x >> y;
            double distance = hypot(x, y);
            int i;
            for (i = 0; i < 10; i++) {
                if (distance <= (double)dist[i]) break;
            }
            
            if (i != 10)
                score += (11 - scores[i]);
//                cout << (11 - scores[i]) << " " << distance << endl;
            
        }
        cout << score << endl;
    }
    
}
