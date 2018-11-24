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
const int TOTALMAX = 100001;

class FenwickTree {
private:
    vi ft;
public:
    FenwickTree () {
        ft.assign(2*TOTALMAX, 0);
    }
    
    FenwickTree(int n) {
        ft.assign(2*(n), 0);
    }
    
    inline int rsq(int a) {
        int sum = 0; for (; a; a -= LSOne(a)) sum += ft[a];
        return sum;
    }

    inline void update(int a, int v) {
        for (int i = a; i < 2*TOTALMAX; i += LSOne(i)) ft[i] += v;
    }
};

int main() {
    int t; cin >> t;
    unordered_map<int, int> pos;
    
    while (t--) {
        int m,r; cin >> m >> r;
        FenwickTree fw = FenwickTree();
        for (int i = 1; i <= m; i++) {
            fw.update(i, 1);
            pos[i] = m - i + 1;
        }
        
        for (int i = m+1; i <= m + r; i++) {
            int mov; cin >> mov;
            cout << m - fw.rsq(pos[mov]) << " ";
            fw.update(pos[mov], -1); fw.update(i, 1); pos[mov] = i;
        } cout << endl;
    }
    
    return 0;
}
