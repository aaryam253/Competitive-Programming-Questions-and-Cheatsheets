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

// Need to use dijkstra for this since its 0,1 weighted SSSP (not a 1-weighted SSSP on a grid maze)


int main () {
    char mtx[450][450] = {};
    int addedWeights[450][450] = {};
    int R,C; cin >> R >> C;
    
//    priority_queue<int, vector<int>, greater<int> > shortestDoor;
    
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> mtx[i][j];
            addedWeights[i][j] = MAX;
        }
    }
    
    int r, c; cin >> r >> c;
    pair<int, int> target = make_pair(r - 1, c - 1);
    
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> q;
    q.push({0, target});
    addedWeights[target.first][target.second] = 1;
    int dx[4] = {0, 1, -1, 0};
    int dy[4] = {1, 0, 0, -1};
    
    while (!q.empty()) {
        int xCurrent = q.top().second.second;
        int yCurrent = q.top().second.first;
        q.pop();
        
        for (int i = 0; i < 4; i++) {
            int x = xCurrent + dx[i];
            int y = yCurrent + dy[i];
            
            if (x < C && x >= 0) {
                if (y < R && y >= 0) {
                    if (addedWeights[y][x] == MAX && mtx[y][x] != '#') {
                        int w = 0;
                        if (mtx[y][x] == 'c') w = 1;
                        if (addedWeights[y][x] > addedWeights[yCurrent][xCurrent] + w) {
                            addedWeights[y][x] = addedWeights[yCurrent][xCurrent] + w;
                        }
                        
                        q.push({addedWeights[y][x], make_pair(y, x)});
                    }
                }
            }
        }
    }
    
    int min = MAX;
    for(int i = 0; i < R; i++) {
        if (min > addedWeights[i][0]) min = addedWeights[i][0];
        if (min > addedWeights[i][C-1]) min = addedWeights[i][C-1];
    }
    for(int j = 0; j < C; j++) {
        if (min > addedWeights[0][j]) min = addedWeights[0][j];
        if (min > addedWeights[R-1][j]) min = addedWeights[R-1][j];
    }

    cout << min << endl;
    
//    for (int i = 0; i < R; i++) {
//        for (int j = 0; j < C; j++) {
//            if (addedWeights[i][j] == MAX) cout << "INF" << "\t";
//            else cout << addedWeights[i][j] << "\t";
//        }
//        cout << endl;
//    }
}
