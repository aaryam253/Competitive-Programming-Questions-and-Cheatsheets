#include <iostream>
#include <vector>
#include <stdio.h>
#include <sstream>
#include <unordered_map>
#include <map>
#include <algorithm>
#include <functional>

using namespace std;


int main () {
    map<string, vector<int> > grandpa;
    
    int num;
    cin >> num;
    
    
    for (int i = 0; i < num; i++) {
        string name;
        int date;
        cin >> name >> date;
        //grandpa[name][date] = date; // TODO: Cant use an ordered map as we have multiple dupe date values
        // Try coding my own implementation of seperate chaining hash table.
        grandpa[name].push_back(date);
    }
    
    for (auto it = grandpa.begin(); it != grandpa.end(); it++) {
        sort(it->second.begin(), it->second.end());
    }

    
    cin >> num;
    for (int i = 0; i < num; i++) {
        string name;
        int query;
        cin >> name >> query;
        cout << grandpa[name][query-1] << endl;
    }
    
}

