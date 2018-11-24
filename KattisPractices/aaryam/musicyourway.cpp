#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <sstream>
#include <iterator>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#include <math.h>
using namespace std;

int attribute;

struct CustomComparator {
    bool operator()(const vector<string> s1, const vector<string> s2) {
        return s1[attribute] < s2[attribute];
    }
};

int main(void) {
    vector<string> attributes;
    string attrs; getline(cin, attrs);
    istringstream iss(attrs);
    string singleatt;
    
    while (iss >> singleatt) {
        attributes.push_back(singleatt);
    }
    
    int n, s; cin >> n; cin.ignore();
    vector<vector<string>> music;
    
    for (int i = 0; i < n; i++) {
        vector<string> song;
        for (int j = 0; j < attributes.size(); j++) {
            cin >> singleatt;
            song.push_back(singleatt);
        }
        music.push_back(song);
    }
    
    cin >> s; cin.ignore();
    CustomComparator c;
    
    for (int i = 0; i < s; i++) {
        string attr; cin >> attr;
        
        for (int i = 0; i < attributes.size(); i++) {
            if (attr == attributes[i]) attribute = i;
        }
        
        stable_sort(music.begin(), music.end(), c);
        
        cout << attrs << endl;
        for (auto song : music) {
            for (auto items : song) {
                cout << items << " ";
            }
            cout << endl;
        }
        
        if (i != s - 1) cout << endl;
    }

    return 0;
}
