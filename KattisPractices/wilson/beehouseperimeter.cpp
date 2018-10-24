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

void findAdjacent (int curr) {
    // Only 6 directions
}

int main () {
    int mtx[150][150] = {}; // 0 is sentinel
    unordered_set<int> Alice;
    int R, K; cin >> R >> K;
    int count = 1;
    int maxX = 0;
    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= R + i - 1; j++) {
            mtx[i][j] = count++;
            maxX = j;
        }
    }
    
    int myCount = 1;
    for (int i = R + 1; i < R * 2; i++) {
        for (int j = 1 + myCount; j <= maxX; j++) {
            mtx[i][j] = count++;
        }
        myCount++;
    }
    
//    for (int i = 0; i <= R*2 + 1; i++) {
//        for (int j = 0; j <= R*2; j++) {
//            cout << mtx[i][j] << "\t";
//        }
//        cout << endl;
//    }
    
    while (K--) {
        int num; cin >> num;
        Alice.insert(num);
    }
    
    
    stack<pair<int, int> > coordStack;
    coordStack.push(make_pair(0, 0));
    long long total = 0;

    while (!coordStack.empty()) {
//        cout << "loop" << endl;
        int dx[6] = {0,1,1,0,-1,-1};
        int dy[6] = {1,1,0,-1,-1,0};
        pair<int, int> curr = coordStack.top(); // y, x
        coordStack.pop();
        if (mtx[curr.first][curr.second] != -1) {
            for (int i = 0; i < 6; i++) {
                // 3 cases - touch Alice, touch -1, touch empty space
                if (curr.first + dy[i] >= 0 && curr.first + dy[i] <= R*2) {
                    if (curr.second + dx[i] >= 0 && curr.second + dx[i] <= R*2) {
                        int x = curr.second + dx[i];
                        int y = curr.first + dy[i];
                        if (Alice.find(mtx[y][x]) != Alice.end()) {
                            // Alice, just pass and increment
//                            cout << curr.first << " " << curr.second << " " << mtx[curr.first][curr.second] << endl;
                            
                            total++;
                        } else if (mtx[y][x] != -1) {
                            coordStack.push(make_pair(y, x));
                        }
                    }
                }
            }
        }
        mtx[curr.first][curr.second] = -1; // visited
    }
    cout << total << endl;
    
}
