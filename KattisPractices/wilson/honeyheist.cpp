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

void findAdjacent (int curr) {
    // Only 6 directions
}

int main () {
    int mtx[150][150] = {}; // 0 is sentinel
    int weights[150][150] = {};
    
    int R, N, A, B, X; cin >> R >> N >> A >> B >> X;
    pair<int, int> start;
    pair<int, int> end;
    unordered_set<int> hardenedCells;
    int count = 1;
    int maxX = 0;
    
    while (X--) {
        int ID; cin >> ID;
        hardenedCells.insert(ID);
    }
    
    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= R + i - 1; j++) {
            if (count == A) start = make_pair(i, j);
            if (count == B) end = make_pair(i, j);
            
            weights[i][j] = MAX;
            
            if (hardenedCells.find(count) != hardenedCells.end()) {
                mtx[i][j] = 0;
            } else {
                mtx[i][j] = count;
            }
            
            count++;
            maxX = j;
        }
    }
    int myCount = 1;
    for (int i = R + 1; i < R * 2; i++) {
        for (int j = 1 + myCount; j <= maxX; j++) {
            
            if (count == A) start = make_pair(i, j);
            if (count == B) end = make_pair(i, j);
            
            if (hardenedCells.find(count) != hardenedCells.end()) {
                mtx[i][j] = 0;
            } else {
                mtx[i][j] = count;
            }
            
            weights[i][j] = MAX;
            count++;
        }
        myCount++;
    }
    
//    for (int i = 0; i <= R*2 + 1; i++) {
//        for (int j = 0; j <= R*2; j++) {
//            cout << mtx[i][j] << "\t";
//        }
//        cout << endl;
//    }

    queue<pair<int, int> > q;
    q.push(start);
    weights[start.first][start.second] = 0; // source be zero
    while (!q.empty()) {

        pair<int, int> curr = q.front();
        q.pop();
        int dx[6] = {0,1,1,0,-1,-1};
        int dy[6] = {1,1,0,-1,-1,0};
        
        for (int i = 0; i < 6; i++) {
            int x = curr.second + dx[i];
            int y = curr.first + dy[i];
            
            if (x >= 0 && x < R*2 && y >= 0 && y <= R*2) {
                if (mtx[y][x] != 0) {
                    // Not a barrier (extra condition)
                    if (weights[y][x] == MAX) {
                        // Unvisited
                        if (weights[y][x] > weights[curr.first][curr.second] + 1) {
                            weights[y][x] = weights[curr.first][curr.second] + 1;
                            if (y == end.first && x == end.second) {
//                                cout << curr.first << " " << curr.second << " " << mtx[curr.first][curr.second] << endl;
                                // TODO: Find out why its approaching from 35 instead of 34
                            }
                        }
                        q.push(make_pair(y, x));
                    }
                }
            }
            
        }
    }
    
    if (weights[end.first][end.second] > N) {
        cout << "No" << endl;
    } else {
        cout << weights[end.first][end.second] << endl;
    }
    
}
