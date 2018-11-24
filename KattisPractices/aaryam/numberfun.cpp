#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <sstream>
#include <iterator>
#include <string>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <math.h>

typedef unsigned long long ull;
using namespace std;

int main (void) {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        float a,b,c;
        cin >> a >> b >> c;
        if (a+b == c || a-b == c || a*b == c || a/b == c || b-a == c || b/a == c) cout << "Possible" << endl;
        else cout << "Impossible" << endl;
    }
    
    return 0;
}
