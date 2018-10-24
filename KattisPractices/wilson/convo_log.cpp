#include <stdio.h>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

int main () {
    int numlines; cin >> numlines;
    vector<pair<int, string>> words;
    unordered_map<string, int> mymap;
    unordered_set<string> names;

    for (int i = 0; i < numlines; i++) {
        string input;
        string name;
        cin >> name;
        names.insert(name);
        cin.ignore();
        getline(cin, input);
        
        istringstream iss (input);
        string token;
        
        while (getline(iss, token, ' '))
        {
            mymap[token]++;
        }
    }
    
    
    for (auto it : mymap) {
        if (it.second >= names.size()) {
            words.push_back(make_pair(it.second, it.first));
        }
    }
    
    for (auto it = words.rbegin(); it != words.rend(); it++) {
        cout << it->second << endl;
    }
    
    if (words.empty()) cout << "ALL CLEAR" << endl;
}

