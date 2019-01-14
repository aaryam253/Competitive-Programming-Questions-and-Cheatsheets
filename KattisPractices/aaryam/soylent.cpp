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
#include <stack>
#include <cmath>
#include <utility>
#define LSOne(S) (S & (-S))
#define INTMAX 1000000001
using namespace std;

typedef unsigned long long ull;
typedef pair<int, string> ps;
typedef pair<int, int> ii;
typedef pair<double, double> pd;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef vector<vector<int>> vvi;
typedef vector<vector<ll>> vvll;
typedef priority_queue<int, vector<int>, greater<>> pqmin;


int main (void) {
    int t; scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        int cal; scanf("%d", &cal);
        cout << ceil((float)cal/400) << endl;
    }
    
    return 0;
}
