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

char maze[1000][1000];
map<int, set<pair<int, int> > > fire_coords;
vector<pair<int, int> > fire_initial;
int fire[1000][1000];

pair<int, int> you;
int r, c;


void bfs_fire () {
    queue<pair<int, pair<int, int> > > q;
    for (auto it : fire_initial) {
        q.push(make_pair(0, it));
        fire[it.first][it.second] = 0;
    }
    
    while (!q.empty()) {
        pair<int, int> curr = q.front().second;
        int layer = q.front().first;
        int curr_x = curr.second, curr_y = curr.first;
        fire[curr_y][curr_x] = layer;
        q.pop();
        
        int dx[4] = {0,1,0,-1};
        int dy[4] = {1,0,-1,0};

        for (int i = 0; i < 4; i++) {
            if (curr_x + dx[i] < c && curr_x + dx[i] >= 0 && curr_y + dy[i] < r && curr_y + dy[i] >= 0) {
                int this_x = curr_x + dx[i];
                int this_y = curr_y + dy[i];
                if (maze[this_y][this_x] == '#') continue;
                if (fire[this_y][this_x] != -1) continue;
                
                q.push(make_pair(layer + 1, make_pair(this_y, this_x)));
            }
        }
        
    }
    
}


int bfs_everchanging () {
    queue<pair<int, pair<int, int> > > q;
    q.push(make_pair(0, you));
    
    int layer = 10000;
    
    while (!q.empty()) {
        pair<int, pair<int, int> > curr = q.front();
        int curr_x = curr.second.second;
        int curr_y = curr.second.first;
        
        // Setting the time stamped for when you get out
        if ((curr_x >= c-1 || curr_y >= r-1 || curr_x < 0 || curr_y < 0) && layer > curr.first) {
            layer = curr.first;
            // Better alternative would be to add sentinels, but for now let's assume that reaching the border means survival in the next iteration
        }
        
        q.pop();
        
        int dx[4] = {0,1,0,-1};
        int dy[4] = {1,0,-1,0};
        
        for (int i = 0; i < 4; i++) {
            if (curr_x + dx[i] < c && curr_x + dx[i] >= 0 && curr_y + dy[i] < r && curr_y + dy[i] >= 0) {
                int this_x = curr_x + dx[i];
                int this_y = curr_y + dy[i];
                
                // Find out whether the current layer contains a fire/ or its an obstacle
                if (maze[this_y][this_x] == '#') continue;
                
                /*
                if (fire_coords.find(curr.first + 1) == fire_coords.end()) {
                    // generate new fire map
                    spread(curr.first + 1);
                }
                */
                if (fire[this_y][this_x] <= curr.first + 1 && fire[this_y][this_x] != -1) continue;
                
                q.push(make_pair(curr.first + 1, make_pair(this_y, this_x)));
                
            }
        }
        
    }
    
    return layer;
}


int main () {
    cin >> r >> c;
    
    
    for (int i = 0; i < r; i++) {
        for (int d = 0; d < c; d++) {
            char input;
            cin >> input;
            fire[i][d] = -1;

            if (input == 'F') {
                fire_coords[0].insert(make_pair(i, d));
                fire_initial.push_back(make_pair(i, d));
                maze[i][d] = '.';
            }else if (input == 'J') {
                you = {i, d};
                maze[i][d] = '.';
            }else {
                maze[i][d] = input;
            }
        }
    }
    bfs_fire();
    /*
    for (int i = 0; i < r; i++) {
        for (int d = 0; d < c; d++) {
            cout << fire[i][d] << "\t";
        }
        cout << endl;
    }
     */
    int t = bfs_everchanging() + 1;
    if (t >= 10000) {
        cout << "IMPOSSIBLE" << endl;
    }else {
        cout << t << endl;
    }
}

