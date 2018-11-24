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
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vii;

int main (void) {
    string fraction;
    while (getline(cin, fraction)) {
        int p = 0;
        string last = fraction.substr(2, fraction.size() - 1);
        int n = stoi(last); int max = (n << 1) + 1;
        for (int x = n+1; x < max; x++) {
            int y = x*n; if (y % (x-n) == 0) p++;
        }
        
        cout << p << endl;
    }
    
    return 0;
}
