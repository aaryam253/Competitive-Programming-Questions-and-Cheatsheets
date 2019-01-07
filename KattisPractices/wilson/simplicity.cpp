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
    string input; cin >> input;
    unordered_map<char, int> m;
    for (auto it : input) {
        m[it]++;
    }
//    cout << m.size() << endl;
    vector<int> nums;
    for (auto it : m) {
        nums.push_back(it.second);
    }
    sort(nums.begin(), nums.end());
    int count = 0;
    
    for (int i = 0; i < nums.size(); i++) {
        if (nums.size() - i <= 2) break;
        count += nums[i];
    }
    cout << count << endl;
}
