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

#define MAX 2147483646

using namespace std;


int main () {
    int num; cin >> num;
    unordered_map<int, int> freq;
    unordered_map<int, int> numberIndex;
    vector<pair<int, int>> array;
    int count = 0;
    while (num--) {
        int thisNum; cin >> thisNum;
        freq[thisNum]++;
        numberIndex[thisNum] = count;
        count++;
    }
    
    for (auto it : freq) {
        array.push_back(make_pair(it.second, it.first));
    }
    
    sort(array.begin(), array.end());
    
    pair<int, int> prev = {-1,-1};
    for (auto it : array) {
        if (it.first > 1) {
            break;
        }
        prev = it;
    }
    
    if (prev.first == -1) {
        cout << "none" << endl;
    } else {
        cout << numberIndex[prev.second] + 1 << endl;
    }
}
