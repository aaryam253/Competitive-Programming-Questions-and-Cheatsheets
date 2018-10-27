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

#define MAX 2147483646

using namespace std;


double euclidean (int x_1, int x_2, int y_1, int y_2) {
    double Xdifference = x_1-x_2;
    Xdifference = pow(Xdifference, 2);
    double Ydifference = y_1-y_2;
    Ydifference = pow(Ydifference, 2);
    return sqrt(Ydifference + Xdifference);
}

int main () {
    int TC; cin >> TC;
    while (TC--) {
        int d; cin >> d;
        vector<tuple<int, int, double, string>> paints;
        for (int i = 0; i < d ; i++) {
            int X, Y, V; cin >> X >> Y >> V;
            string color; cin >> color;
            double radius = sqrt((double)V/M_PI);
            paints.push_back(make_tuple(X, Y, radius, color));
        }
        
        int queries; cin >> queries;
        for (int i = 0; i < queries; i++) {
            int X, Y; cin >> X >> Y;
            string finalName = "white";
            for (auto it : paints) {
                int x_1 = get<0>(it);
                int x_2 = X;
                int y_1 = get<1>(it);
                int y_2 = Y;
                double radius = get<2>(it);
                string colorName = get<3>(it);
                if (euclidean(x_1, x_2, y_1, y_2) <= radius) {
                    finalName = colorName;
                }
            }
            cout << finalName << endl;
        }
    }
    
}
