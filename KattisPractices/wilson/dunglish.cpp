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

#define MAX 1e9

using namespace std;


int main () {
    int n; cin >> n;
    unordered_map<string, int> sMap;
    unordered_map<string, set<string>> correctWords;
    unordered_map<string, set<string>> incorrectWords;
    vector<string> original;
    unordered_map<string, string> translate;

    while (n--) {
        string input; cin >> input;
        sMap[input]++;
        original.push_back(input);
    }
    
    int m; cin >> m;
    while (m--) {
        string word, placeholder, valid; cin >> word >> placeholder >> valid;
        translate[word] = placeholder;
        if (valid.compare("correct") == 0) {
            correctWords[word].insert(placeholder);
        } else {
            incorrectWords[word].insert(placeholder);
        }
    }
    
    long long correct = 1;
    long long incorrect = 1;
    for (auto it : sMap) {
        correct *= pow(correctWords[it.first].size(), it.second);
        incorrect *= pow(incorrectWords[it.first].size() + correctWords[it.first].size(), it.second);
    }
    
    if (incorrect == 1) {
        for (auto it : original) {
            cout << translate[it] << " ";
        }
        cout << endl;
        if (correct == 1) cout << "correct" << endl;
        else cout << "incorrect" << endl;
    } else {
        cout << correct << " correct" << endl;
        cout << incorrect - correct << " incorrect"<< endl;
    }
    
    
    
}


