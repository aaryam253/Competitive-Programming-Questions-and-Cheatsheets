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
    string s, n; cin >> s >> n;
    long long numZeroes = n.length()-1;
    for (long long i = s.length()-1; i >= 0; i--) {
        if (s[i] == '0' && numZeroes >= 1) {
            s.pop_back();
            numZeroes--;
        } else {
            break;
        }
    }
    if (numZeroes > 0) {
        long long pointer = s.length();
        while (numZeroes--) {
            pointer--;
        }
        
        string newStr;
        if (pointer >= 1) {
            newStr = s.substr(0,pointer);
            newStr += '.';
            newStr += s.substr(pointer,s.length()-1);
        } else {
            newStr += "0.";
            pointer = abs(pointer);
            for (long long i = 0; i < pointer; i++) {
                newStr += '0';
            }
            newStr += s;
        }
        
        cout << newStr << endl;
    } else {
        cout << s << endl;
    }
    
}
