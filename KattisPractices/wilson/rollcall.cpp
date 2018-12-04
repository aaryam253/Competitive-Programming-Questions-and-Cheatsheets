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
    unordered_map<string, int> commonFirst, commonLast;
    vector<pair<string, string>> names;
    string input;
    while (getline(cin, input)) {
        istringstream iss (input);
        string token;
        bool flag = false;
        pair<string, string> name;
        while (getline(iss, token, ' ')) {
            if (!flag) {
                commonLast[token]++;
                name.second = token;
                flag = true;
            } else {
                commonFirst[token]++;
                name.first = token;
            }
        }
        names.push_back(name);
    }
    
    
    sort(names.begin(), names.end());
    for (auto it : names) {
        if (commonLast[it.second] > 1)
            cout << it.second << " " << it.first << endl;
        else
            cout << it.second << endl;
    }
}


