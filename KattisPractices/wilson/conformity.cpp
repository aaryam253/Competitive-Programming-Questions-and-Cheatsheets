#include <iostream>
#include <stdio.h>
#include <stdarg.h>
#include <math.h>
#include <list>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <unordered_map>
#include <stack>
#include <algorithm>


using namespace std;

int main () {
    int num, num_1;
    map<set<int>, int> comparison;
    cin >> num;
    num_1 = num;
    while (num--) {
        set<int> myset;
        for (int i = 0; i < 5; i++) {
            int number; cin >> number;
            //myvec.push_back(number);
            //myset[number]++;
            myset.insert(number);
        }
        //sort(myvec.begin(), myvec.end());
        comparison[myset]++;
    }
    
    int max = 0;
    for (auto it : comparison) {
        if (it.second > max) {
            max = it.second;
        }
    }
    int count = 0;

    if (comparison.size() < num_1) {
        for (auto it : comparison) {
            if (it.second == max && it.second != 1) count+=max;
        }
    }
    
    if (comparison.size() < num_1) {
        cout << count << endl;
    }else {
        cout << num_1 << endl;
    }
    
    
}
