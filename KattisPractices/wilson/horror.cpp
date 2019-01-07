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

#define MAX 2147483640

using namespace std;



int main () {
    int N, H, L; cin >> N >> H >> L;
    list<int> AL[100000];
    queue<int> q;
    vector<int> addedWeights (N, MAX);
    for (int i = 0; i < H; i++) {
        int source; cin >> source;
        q.push(source);
        addedWeights[source] = 0;
    }
    for (int i = 0; i < L; i++) {
        int a, b; cin >> a >> b;
        AL[a].push_back(b);
        AL[b].push_back(a);
    }
    
    while (!q.empty()) {
//        cout << "test" << endl;
        int curr = q.front();
        q.pop();
        
        for (auto it : AL[curr]) {
            if (addedWeights[it] == MAX) {
                if (addedWeights[it] > addedWeights[curr] + 1) {
                    addedWeights[it] = addedWeights[curr] + 1;
                }
                q.push(it);
            }
        }
    }
    int index = 0;
    int weight = addedWeights[index];
    for (int i = 0; i < N; i++) {
        if (addedWeights[i] > weight) {
            weight = addedWeights[i];
            index = i;
        }
    }
    cout << index << endl;
}
