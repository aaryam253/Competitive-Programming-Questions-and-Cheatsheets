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
    int TC; cin >> TC;

    cin.ignore();
    while (TC--) {
        unordered_set<char> alphabetSet;
        string input;
        getline(cin, input);

        for (auto it : input) {
            if (isalpha(it)) {
                alphabetSet.insert(tolower(it));
            }
        }
        //    cout << alphabetSet.size() << endl;
        
        if (alphabetSet.size() < 26) {
            cout << "missing ";
            for (char i = 'a'; i <= 'z'; i++) {
                if (alphabetSet.find(i) == alphabetSet.end()) {
                    cout << i;
                }
            }
            cout << endl;
            
        } else {
            cout << "pangram" << endl;
        }

    }

}
