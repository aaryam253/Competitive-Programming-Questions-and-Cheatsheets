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
    string input;
    map<string, int> freq;
    long count = 0;
    while (getline(cin, input)) {
        freq[input]++;
        count++;
//        if (count == 29) break;
    }
    
    for (auto it : freq) {
        cout << it.first << " ";
        printf("%0.6lf\n", ((double)it.second/count)*100);
    }
}
