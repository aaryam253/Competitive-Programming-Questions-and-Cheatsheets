#include <stdio.h>
#include <iostream>
#include <vector>
#include <set>

using namespace std;


int main () {
    string input;
    vector<string> word_v;
    set<string> words;
    while (cin >> input) {
        // First input will be "" nothing
        for (auto it = word_v.begin(); it != word_v.end(); it++) {
            words.insert(*it + input);
            words.insert(input + *it);
        }
        word_v.push_back(input);
    }
    
    
    for (auto it = words.begin(); it != words.end(); it++) {
        cout << *it << endl;
    }
    
}

