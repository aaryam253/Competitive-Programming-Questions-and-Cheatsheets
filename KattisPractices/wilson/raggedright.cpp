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
    string line;
    vector<int> words;
    int n = 0;
    while (getline(cin, line)) {
        words.push_back(line.size());
        n = max(n, (int)line.size());
    }
    words.erase(prev(words.end()));
    
    sort(words.rbegin(), words.rend());
    long long total = 0;
    for (int i = 0; i < words.size(); i++) {
        total += pow(n-words[i], 2);
    }
    cout << total << endl;
    
}
