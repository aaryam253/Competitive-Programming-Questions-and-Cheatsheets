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
#define LSOne(S) (S & (-S))
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<int>> vii;
typedef vector<vector<ll>> vvll;

class FenwickTree {
private:
    vi ft;
public:
    FenwickTree () {}
    
    FenwickTree(int n) {
        ft.assign(n+1, 0);
    }
    
    inline int rsq(int a) {
        int sum = 0; for (; a; a -= LSOne(a)) sum += ft[a];
        return sum;
    }
    
    inline int rsq(int a, int b) {
        return rsq(b) - (a == 1 ? 0 : (rsq(a-1)));
    }

    inline void update(int a, int v) {
        for (int i = a; i < ft.size(); i += LSOne(i)) ft[i] += v;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, element; cin >> n;
    unordered_map<int, int> pos;
    FenwickTree fw(n);
    
    for (int i = 1; i <= n; i++) {
        cin >> element; pos[element] = i;
        fw.update(i, 1);
    }
    
    int start = 1, end = n;
    
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            fw.update(pos[start], -1); cout << fw.rsq(1, pos[start++] - 1) << endl;
        } else {
            fw.update(pos[end], -1); cout << fw.rsq(pos[end--] + 1, n) << endl;
        }
    }
    
    return 0;
}
