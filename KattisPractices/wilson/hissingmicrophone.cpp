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

using namespace std;


int main () {
    string input; cin >> input;
    for (int i = 1; i < input.size(); i++) {
        if (input[i - 1] == 's' && input[i] == 's') {
            cout << "hiss" << endl;
            return 0;
        }
    }
    
    cout << "no hiss" << endl;
}
