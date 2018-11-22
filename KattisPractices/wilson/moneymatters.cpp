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
    bool visited[20000] = {};
    int moneys[20000] = {};
    list<int> adjList[55000];
    
    int money, friendships; cin >> money >> friendships;
    
    for (int i = 0; i < money; i++) {
        cin >> moneys[i];
    }
    
    for (int i = 0; i < friendships; i++) {
        int x, y; cin >> x >> y;
        adjList[x].push_back(y);
        adjList[y].push_back(x);
    }
    
    bool possible = true;
    for (int i = 0; i < money; i++) {
        if (visited[i] != true) {
            int total = 0;
            queue<int> q;
            q.push(i);
            visited[i] = true;
            total += moneys[i];
            
            while (!q.empty()) {
                int curr = q.front();
                q.pop();
                for (auto it : adjList[curr]) {
                    if (visited[it] == false) {
                        total += moneys[it];
                        q.push(it);
                        visited[it] = true;
                    }
                }
                
            }
            if (total != 0) {
                possible = false;
                break;
            }
            
            
        }
    }
    
    if (possible) {
        cout << "POSSIBLE" << endl;
    } else {
        cout << "IMPOSSIBLE" << endl;
    }
    

}
