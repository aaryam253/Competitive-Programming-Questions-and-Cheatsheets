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
    int N, Y; cin >> N >> Y;
    unordered_set<int> s;
    while (Y--) {
        int input; cin >> input;
        s.insert(input);
    }
    for (int i = 0; i <N; i++) {
        if (s.find(i) == s.end()) {
            cout << i << endl;
        }
    }
    cout << "Mario got " << s.size() <<  " of the dangerous obstacles." << endl;
}
