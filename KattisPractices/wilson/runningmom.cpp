#include <iostream>
#include <stdio.h>
#include <unordered_map>
#include <list>
#include <queue>
#include <set>
#include <algorithm>
#include <vector>
#include <stack>
#include <unordered_set>

using namespace std;


//list<int> AL[1300]; // Push back when we wanna add new adjacent vertices
vector<list<int> > AL (10001);
queue<int> q;
vector<int> safe (10001, 1);
//unordered_map<int, int> degrees;
vector<int> degrees (10001, 0);

int id = 0;


void search () {
    for (int i = 0; i < id; i++) {
        if (degrees[i] == 0) {
            q.push(i);
        }
    }
    
    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        safe[curr] = 0;
        for (auto it = AL[curr].begin(); it != AL[curr].end(); it++) {
            degrees[*it]--;
            if (degrees[*it] == 0) q.push(*it);
        }
    }
    
}



void connect (int v, int v2) {
    //AL[v].push_back(v2);
    AL[v2].push_back(v);
    degrees[v]++;
}


int main () {
    unordered_map<string, int> id_map;
    int numv; cin >> numv;
    
    while (numv--) {
        string input, input2;
        cin >> input >> input2;
        
        // Assign them a unique ID
        if (id_map.find(input) == id_map.end()) {
            id_map[input] = id++;
        }
        if (id_map.find(input2) == id_map.end()) {
            id_map[input2] = id++;
        }
        
        connect(id_map[input], id_map[input2]);
    }

    search();
    string query;
    while (cin >> query) {
        int uid = id_map[query];
        
        cout << query << " ";
        if  (safe[uid]) cout << "safe" << endl;
        else cout << "trapped" << endl;
    }
}

