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
    int TC; cin >> TC;
    while (TC--) {
        int w, h; cin >> w >> h;
        char mtx[1005][1005] = {};
        
        queue<pair<int, int>> fireFlood;
        queue<pair<int, int>> player;
        
//        int addedWeightFire[1005][1005] = {};
//        int addedWeight[1005][1005] = {};
        
        vector<vector<int>> addedWeightFire(h, vector<int>(w, MAX));
        vector<vector<int>> addedWeight(h, vector<int>(w, MAX));
        
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                cin >> mtx[i][j];
                addedWeightFire[i][j] = MAX;
                addedWeight[i][j] = MAX;
                if (mtx[i][j] == '*') {
                    fireFlood.push({i, j});
                    addedWeightFire[i][j] = 0;
                }
                if (mtx[i][j] == '@') {
                    player.push({i, j});
                    addedWeight[i][j] = 0;
                }
            }
        }
        
        int dx[4] = {0,1,0,-1};
        int dy[4] = {1,0,-1,0};
        int min = MAX;

        // Entirely dependent on the player
        while (!fireFlood.empty()) {
            
            if (!fireFlood.empty()) {
                pair<int, int> curr = fireFlood.front();
                int x = curr.second;
                int y = curr.first;
                fireFlood.pop();
                
                for (int i = 0; i < 4; i++) {
                    int x_new = x + dx[i];
                    int y_new = y + dy[i];
                    
                    if (x_new >= 0 && y_new >= 0) {
                        if (x_new < w && y_new < h) {
                            if (addedWeightFire[y_new][x_new] == MAX && mtx[y_new][x_new] != '#') {
                                if (addedWeightFire[y_new][x_new] > addedWeightFire[y][x] + 1) {
                                    addedWeightFire[y_new][x_new] = addedWeightFire[y][x] + 1;
                                }
                                fireFlood.push({y_new, x_new});
                            }
                        }
                    }
                }
            }
        }
        
        while (!player.empty()) {
            if (!player.empty()) {
                pair<int, int> curr = player.front();
                int x = curr.second;
                int y = curr.first;
                player.pop();
                
                
                for (int i = 0; i < 4; i++) {
                    int x_new = x + dx[i];
                    int y_new = y + dy[i];
                    
                    if (x_new >= 0 && y_new >= 0) {
                        if (x_new < w && y_new < h) {
                            if (addedWeight[y_new][x_new] == MAX && mtx[y_new][x_new] != '#' && addedWeightFire[y_new][x_new] > addedWeight[y][x] + 1) {
                                if (addedWeight[y_new][x_new] > addedWeight[y][x] + 1) {
                                    addedWeight[y_new][x_new] = addedWeight[y][x] + 1;
                                }
//                                // Border
//                                if (y_new == h - 1 || x_new == w - 1 || y_new == 0 || x_new == 0) {
//                                    if (addedWeight[y_new][x_new] < min) {
//                                        min = addedWeight[y_new][x_new] + 1;
//                                    }
//                                }
                                player.push({y_new, x_new});
                            }
                            
                        }
                        
                    }
                }
            }
        }
        
        
        
        //        for (int i = 0; i < h; i++) {
        //            for (int j = 0; j < w; j++) {
        //                cout << (int)addedWeightFire[i][j] << " ";
        //            }
        //            cout << endl;
        //        }
        //
        //        for (int i = 0; i < h; i++) {
        //            for (int j = 0; j < w; j++) {
        //                cout << (int)addedWeight[i][j] << " ";
        //            }
        //            cout << endl;
        //        }
        
        
        for (int i = 0; i < w; i++) {
            if (addedWeight[h-1][i] < min) {
                min = addedWeight[h-1][i];
            }
            if (addedWeight[0][i] < min) {
                min = addedWeight[0][i];
            }
        }
        
        for (int i = 0; i < h; i++) {
            if (addedWeight[i][w-1] < min) {
                min = addedWeight[i][w-1];
            }
            if (addedWeight[i][0] < min) {
                min = addedWeight[i][0];
            }
        }
        
        if (min == MAX) {
            cout << "IMPOSSIBLE" << endl;
        } else {
            cout << min + 1 << endl;
        }
        
    }
    
    
}
