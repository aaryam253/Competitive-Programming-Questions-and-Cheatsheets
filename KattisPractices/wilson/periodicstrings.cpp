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

bool isRotate (string input, string test) {
    // Rotate once
    string newString = input[input.length()-1] + input;
    newString = newString.substr(0, newString.length()-1);
    
    input = newString;
    if (test == newString) return true;
    
    return false;
}

int main () {
    string input; cin >> input;
    for (int i = 1; i <= input.length(); i++) {
        if (input.length() % i == 0) {
            int count = 0;
            string prev;
            bool can = true;
            while (count < input.length()) {
                string modified = input.substr(count, i);
//                cout << modified << endl;
                if (!count) {
                    prev = modified;
                } else {
//                    cout << modified << "=======" << endl;
                    if (!isRotate(prev, modified)) {
                        can = false;
                        break;
                    }
                }
                prev = modified;
                count += i;
            }
            if (can) {
                cout << i << endl;
                break;
            }
        }
    }
    
}
