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
    // Flood first then move
    int r, c; cin >> r >> c;
    char mtx[60][60] = {};

    int addedWeights[60][60];
    int addedWeightsFlood[60][60];
    queue<pair<int, int>> flood;
    queue<pair<int, int>> player;
    
    pair<int, int> source;
    pair<int, int> dest;
    
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> mtx[i][j];
            addedWeights[i][j] = MAX;
            addedWeightsFlood[i][j] = MAX;
            if (mtx[i][j] == '*') {
                flood.push({i, j});
                addedWeightsFlood[i][j] = 0;
            }
            if (mtx[i][j] == 'S') {
                source = {i, j};
                addedWeights[i][j] = 0;
                player.push({i, j});
            }
            if (mtx[i][j] == 'D') {
                dest = {i, j};
            }
        }
    }
    
    int dx[4] = {1,0,-1,0};
    int dy[4] = {0,1,0,-1};

    while (!flood.empty()) {
        pair<int, int> curr = flood.front();
        int x = curr.second;
        int y = curr.first;
        
        flood.pop();
        for (int i = 0; i < 4; i++) {
            int x_new = x + dx[i];
            int y_new = y + dy[i];
            if (x_new >= 0 && y_new >= 0) {
                if (x_new < c && y_new < r) {
                    if (addedWeightsFlood[y_new][x_new] == MAX && mtx[y_new][x_new] != 'X' && mtx[y_new][x_new] != 'D') {
                        if (addedWeightsFlood[y_new][x_new] > addedWeightsFlood[y][x] + 1) {
                            addedWeightsFlood[y_new][x_new] = addedWeightsFlood[y][x] + 1;
                        }
                        flood.push({y_new, x_new});
                    }
                }
            }
        }
    }
    
    while (!player.empty()) {
        pair<int, int> curr = player.front();
        int x = curr.second;
        int y = curr.first;
        
        player.pop();
        
        for (int i = 0; i < 4; i++) {
            int x_new = x + dx[i];
            int y_new = y + dy[i];
            if (x_new >= 0 && y_new >= 0) {
                if (x_new < c && y_new < r) {
                    if (addedWeights[y_new][x_new] == MAX && mtx[y_new][x_new] != 'X' && addedWeightsFlood[y_new][x_new] > addedWeights[y][x] + 1) {
                        if (addedWeights[y_new][x_new] > addedWeights[y][x] + 1 ) {
                            addedWeights[y_new][x_new] = addedWeights[y][x] + 1;
                        }
                        player.push({y_new, x_new});
                    }
                }
            }
        }
    }

//    for (int i = 0; i < r; i++) {
//        for (int j = 0; j < c; j++) {
//            cout << addedWeights[i][j] << " ";
//        }
//        cout << endl;
//    }
//
    
    if (addedWeights[dest.first][dest.second] != MAX) {
        cout << addedWeights[dest.first][dest.second] << endl;
    } else {
        cout << "KAKTUS" << endl;
    }
    
}
