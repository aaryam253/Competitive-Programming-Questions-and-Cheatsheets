#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <functional>

using namespace std;



int main () {
    int numTrees;
    cin >> numTrees;
    vector<int> seedlings;
    for (int i = 0; i < numTrees; i++) {
        int number;
        cin >> number;
        seedlings.push_back(number);
    }
    sort(seedlings.begin(), seedlings.end());
    reverse(seedlings.begin(), seedlings.end());
    
    int max = 0;
    for (int i = 0; i < numTrees; i++) {
        if (max < seedlings[i] + i + 2) max = seedlings[i] + i + 2;
    }
    
    cout << max << endl;
    
}
