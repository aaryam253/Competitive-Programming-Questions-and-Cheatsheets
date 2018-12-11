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
    double input; cin >> input;
    int power; cin >> power;
    
    input /= pow(10, power);
    long long output = round(input) * pow(10, power);
    cout << output << endl;
}
