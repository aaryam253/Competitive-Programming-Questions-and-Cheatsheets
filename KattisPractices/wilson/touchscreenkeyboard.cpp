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

#define MAX 2147483646

using namespace std;


int main () {
    unordered_map<char, int> codeMap;
    codeMap = {{'q', 0}, {'w', 10}, {'e', 20}, {'r', 30}, {'t', 40}, {'y', 50}, {'u', 60}, {'i', 70}, {'o', 80}, {'p', 90},
                {'a', 1}, {'s', 11}, {'d', 21}, {'f', 31}, {'g', 41}, {'h', 51}, {'j', 61}, {'k', 71}, {'l', 81},
                {'z', 2}, {'x', 12}, {'c', 22}, {'v', 32}, {'b', 42}, {'n', 52}, {'m', 62}};

    
    int TC; cin >> TC;
    while (TC--) {
        vector<pair<int, string>> orderedStrings;
        string input; cin >> input; int myCase; cin >> myCase;
        for (int i = 0; i < myCase; i++) {
            string thisInput; cin >> thisInput;
            long long total = 0;
            for (int d = 0; d < thisInput.length(); d++) {
                total += abs(codeMap[thisInput[d]]/10 - codeMap[input[d]]/10) + abs(codeMap[thisInput[d]]%10 - codeMap[input[d]]%10);
            }
            orderedStrings.push_back(make_pair(total, thisInput));
        }
        
        sort(orderedStrings.begin(), orderedStrings.end());
        
        for (auto it : orderedStrings) {
            cout << it.second << " " << it.first << endl;
        }
    }
    
}
