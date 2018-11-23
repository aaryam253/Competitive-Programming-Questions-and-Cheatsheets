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
    unordered_set<char> vowels = {'a','e','i','o','u','y'};
    while (true) {
        int words; cin >> words;
        if (!words) return 0;
        map<int, string> m;
        
        while (words--) {
            string input; cin >> input;
            int count = 0;
            for (int i = 0; i < input.length() - 1; i++) {
                if (input[i] == input[i+1]) {
                    if (vowels.find(input[i]) != vowels.end()) {
                        count++;
                    }
                }
            }
            m[count] = input;
        }
        cout << m.rbegin()->second << endl;
    }
}
