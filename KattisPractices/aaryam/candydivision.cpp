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
#include <cmath>
#include <utility>
#define LSOne(S) (S & (-S))
#define NOTHING -1
#define INTMAX 9999999999
using namespace std;

typedef unsigned long long ull;
typedef pair<int, string> ps;
typedef pair<int, int> p;
typedef pair<double, double> pd;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<int>> vii;
typedef vector<vector<ll>> vvll;
typedef priority_queue<int, vector<int>, greater<>> pqmin;

int main() {
    set<long long> friends;
    long long N, sqr; cin >> N;
    sqr = sqrt(N);

    for (int i = 1; i <= sqr; i++) {
        if (N % i == 0) {
            friends.insert(i-1);
            if (i != (N/i)) friends.insert((N/i) - 1);
        }
    }

    for (auto i : friends) cout << i << " ";
    return 0;
}
