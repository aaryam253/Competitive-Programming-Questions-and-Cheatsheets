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
    string pass, sentence; cin >> pass >> sentence;
    
    int index = 0;
    for (int i = 0; i < sentence.length(); i++) {
        if (sentence[i] == pass[index]) {
            index++;
            continue;
        }
        for (int j = index + 1; j < pass.length(); j++) {
            if (sentence[i] == pass[j]) {
                cout << "FAIL" << endl;
                return 0;
            }
        }
    }
    
    if (index == pass.length()) cout << "PASS" << endl;
    else cout << "FAIL" << endl;
}


