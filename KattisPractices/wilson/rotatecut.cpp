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
    int C; cin >> C;
    while (C--) {
        long long cuts; cin >> cuts;
        string myString; cin >> myString;
        deque<char> myWord;
        for (auto it : myString) {
            myWord.push_back(it);
        }
        
        for (int i = 0; i < cuts; i++) {
            long long removal = myWord.size()/4;
            if (removal == 0) break;
            
            for (int j = 0; j < removal; j++) {
                if (!(i%2)) {
                    myWord.pop_front();
                } else {
                    myWord.pop_back();
                }
            }
        }
        
        for (auto it : myWord) {
            cout << it;
        }
        cout << endl;
    }
}
