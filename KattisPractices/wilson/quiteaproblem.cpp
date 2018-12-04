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
    string input;
    while (getline(cin, input)) {
        for (auto &c : input) {
            c = tolower(c);
        }
        
        if (input.find("problem") != string::npos) {
            cout << "yes" << endl;
        } else {
            cout << "no" << endl;
        }
    }
}


