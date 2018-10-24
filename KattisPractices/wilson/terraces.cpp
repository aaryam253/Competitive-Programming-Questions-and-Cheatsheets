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
#include <stack>


using namespace std;

int mtx[600][600], mtx_prime[600][600];
int col, row;


bool check (stack<pair<int, int> > * check_points, stack<pair<int, int> > *converted_checkpoints, int number) {
    bool lower = false;
    while (!check_points->empty()) {
        converted_checkpoints->push(check_points->top());
        pair<int, int> curr = check_points->top();
        check_points->pop();
        mtx_prime[curr.second][curr.first] = 0;
        //cout << mtx[curr.second][curr.first] << endl;
        int x = curr.first;
        int y = curr.second;
        int dx [4] = {0, 1, 0, -1};
        int dy [4] = {1, 0, -1, 0};
        for (int i = 0; i < 4; i++) {
            if (x + dx[i] < col && y + dy[i] < row && x + dx[i] >= 0 && y + dy[i] >= 0) {
                if (mtx[y+dy[i]][x+dx[i]] == number && mtx_prime[y+dy[i]][x+dx[i]] == -1) {
                    check_points->push(make_pair(x+dx[i], y + dy[i]));
                }else if (mtx[y+dy[i]][x+dx[i]] < number) {
                    lower = true;
                }
            }
        }
    }
    //lower ? cout << "true" << endl : cout << "false" << endl;
    return lower;
}



void dfs_recur (int x, int y) {
    mtx_prime[y][x] = 0; // 0 means visited but not collection point
    int dx [4] = {0, 1, 0, -1};
    int dy [4] = {1, 0, -1, 0};
    bool moves = false;
    for (int i = 0; i < 4; i++) {
        if (x + dx[i] < col && y + dy[i] < row && x + dx[i] >= 0 && y + dy[i] >= 0) {
            if (mtx[y][x] > mtx[y+dy[i]][x+dx[i]]) {
                moves = true;
                if (mtx_prime[y + dy[i]][x + dx[i]] == -1) {
                    dfs_recur(x + dx[i], y + dy[i]);
                }
            }else if (mtx[y][x] == mtx[y + dy[i]][x + dx[i]] && mtx_prime[y + dy[i]][x + dx[i]] == -1) {
                
                // Found a similar node, flood fill that to find out if its a dead end or it can flow elsewhere :/
                
                stack< pair<int, int> > check_points, converted_checkpoints;
                check_points.push(make_pair(x, y));
                if (check(&check_points, &converted_checkpoints, mtx[y][x]) == false) {
                    while (!converted_checkpoints.empty()) {
                        pair<int, int> curr = converted_checkpoints.top();
                        converted_checkpoints.pop();
                        mtx_prime[curr.second][curr.first] = 1;
                    }
                }else{
                    moves = true;
                }
            }
        }
    }
    
    if (!moves) {
        mtx_prime[y][x] = 1;
    }
}


void dfs (int x, int y) {
    dfs_recur(x, y);
}



int main() {
    // Flood fill at unvisited nodes/ nodes that are not marked using DFS until it reaches a node with nowhere to flow to (ie bottom-most)
    // Mark that node as a collection point
    // Move on with the rest
    cin >> col >> row;
    for (int i = 0; i < row; i++) {
        for (int d = 0; d < col; d++) {
            cin >> mtx[i][d];
            mtx_prime[i][d] = -1; // -1 means unvisited
        }
    }
    
    for (int i = 0; i < row; i++) {
        for (int d = 0; d < col; d++) {
            if (mtx_prime[i][d] == -1) {
                dfs(d, i);
            }
        }
    }
    
    // Count number of 1s
    int count = 0;
    for (int i = 0; i < row; i++) {
        for (int d = 0; d < col; d++) {
            if (mtx_prime[i][d] == 1) count++;
        }
    }
    cout << count << endl;
    
}

