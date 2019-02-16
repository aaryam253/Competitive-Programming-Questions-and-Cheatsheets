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
#include <iomanip>

#define MAX 2147483640

using namespace std;

int main () {
    pair<int, int> jim[20];
    tuple<int, int, int> others[20];
    vector<vector<int>> T_jim;
    vector<vector<int>> T_others;

    
    for (int i = 0; i < 10; i++) {
        int a, b; cin >> a >> b;
        jim[i] = {a,b};
    }
    
    for (int i = 0; i < 10; i++) {
        int a, b, c;
        others[i] = {a, b, c};
    }
    
    // Initial
    vector<int> v_others(20, 0);
    vector<int> v_jim(20, 0);
    for (int i = 0; i < 10; i++) {
        if (get<2>(others[i]) == 0) {
            v_others[i] = 1;
        }
        if (v_others[i] == 0 && i == 0) {
            v_jim[i] = 1;
        }
    }
    T_jim.push_back(v_jim);
    T_others.push_back(v_others);
    
    int count = 0;
    
    while (true) {
        // Use 2 2D arrays to keep track. One for Jim and the other for the others. 0 for idling, > 0 for workout, < 0 for resting
        vector<int> v_others(20, 0);
        vector<int> v_jim(20, 0);
        vector<int> curr_jim = T_jim.front();
        vector<int> curr_others = T_others.front();
        
        
        for (int i = 0; i < 10; i++) {
            if (curr_jim[i] == 0 && curr_others[i] == 0) {
                // both idling
                v_others[i] = 1;
            } else if (curr_jim[i] < 0 && curr_jim[i] == -1*jim[i].second && curr_others[i] < 0 && curr_others[i] == -1*get<1>(others[i])) {
                // Both finished their recovery
                v_others[i] = 1; // Let others go first
                v_jim[i] = 0;
            } else if (curr_jim[i] == 0 && curr_others[i] > -1*get<1>(others[i])) {
                // Jim is idling, others still recovering
                v_jim[i] = 1;
            } else if (curr_jim[i] < 0 && curr_jim[i] == -1*jim[i].second && curr_others[i] < 0 && curr_others[i] == 0) {
                // Jim is done but others is idling
                v_others[i] = 1;
                v_jim[i] = 0;
            } else if (curr_others[i] == 0 && curr_jim[i] < 0) {
                // Others is idling and Jim is resting
                v_others[i] = 1;
            }
            
            
            // To continue
            if (curr_jim[i] > 0 && curr_jim[i] < jim[i].first) {
                v_jim[i] = curr_jim[i] + 1;
            }
            if (curr_others[i] > 0 && curr_others[i] < get<0>(others[i])) {
                v_others[i] = curr_others[i] + 1;
            }
            if (curr_jim[i] < 0 && curr_jim[i] > -1*jim[i].second) {
                v_jim[i] = curr_jim[i] - 1;
            }
            if (curr_others[i] < 0 && curr_others[i] > -1*get<1>(others[i])) {
                v_others[i] = curr_others[i] - 1;
            }
            
            T_jim.push_back(v_jim);
            T_others.push_back(v_others);
        }
        
        
        if (T_jim.front()[9] < 0 && abs(T_jim.front()[9]) == jim[9].second) {
            count++;
        }
        
        if (count == 3) {
            break;
        }
        
        for (auto it : T_jim.front()) {
            cout << it << " ";
        }
        cout << endl;
    }
    
    
    cout << T_jim.size() << endl;
}

