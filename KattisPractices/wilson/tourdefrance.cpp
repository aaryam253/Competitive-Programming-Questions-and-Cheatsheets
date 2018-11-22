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
    while (true) {
        int r, f; cin >> r;
        if (!r) return 0;
        cin >> f;
        vector<int> rear, front;
        vector<double> divisions;
        for (int i = 0; i < r; i++) {
            int num; cin >> num;
            rear.push_back(num);
        }
        
        for (int i = 0; i < f; i++) {
            int num; cin >> num;
            front.push_back(num);
        }
        
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < f; j++) {
                divisions.push_back(rear[i]/(double)front[j]);
            }
        }
        
        sort(divisions.begin(), divisions.end());
        
        double maxSpread = -1;
        
        for (int i = 1; i < divisions.size(); i++) {
            if (divisions[i]/divisions[i-1] > maxSpread) {
                maxSpread = divisions[i]/divisions[i-1];
            }
        }
        
        printf("%0.2lf\n", maxSpread);
    }
}
