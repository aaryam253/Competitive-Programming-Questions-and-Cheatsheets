#include <iostream>
#include <fstream>
#include <iomanip>
#include <map>
#include <set>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <sstream>
#include <iterator>
#include <list>
#include <string>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <stack>
#include <cmath>
#include <utility>
#define LSOne(S) (S & (-S))
#define INTMAX 1e9
using namespace std;

typedef unsigned long long ull;
typedef pair<int, string> ps;
typedef pair<int, int> ii;
typedef pair<double, double> pd;
typedef tuple<int, int, int> iii;
typedef tuple<int, int, int, int> iiii;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef vector<vector<int>> vvi;
typedef vector<vector<ll>> vvll;
typedef priority_queue<int, vector<int>, greater<>> pqmin;

void file() {
    auto a = freopen("input.in",  "r", stdin);
    auto b = freopen("output.out", "w", stdout);
    if(!a || !b) cout << "Something wrong with your files :(" << endl;
}

int main() {
    int n; scanf("%d", &n);
    list<string> strings[n];
    
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        strings[i].push_back(s);
    }
    
    int a = 0,b;
    for (int i = 0; i < n-1; i++) {
        scanf("%d %d", &a, &b);
        a--; b--;
        strings[a].splice(strings[a].end(), strings[b]);
    }
    
    for (auto &s : strings[a]) cout << s;
    cout << endl;
    
    return 0;
}
