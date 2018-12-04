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
    long long int input; cin >> input;
    int bits; cin >> bits;
    long long int multiplier = pow(2, bits + 1) - 1;
    
    if (multiplier < input) cout << "no" << endl;
    else cout << "yes" << endl;
}


