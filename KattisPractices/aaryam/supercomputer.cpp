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
    FenwickTree() {}
    
    FenwickTree(int n) {
        ft.assign(n+1, 0);
    }
    
    inline int rsq(int b) {
        int sum = 0; for (int i = b; i > 0; i &= i-1) sum += ft[i-1];
        return sum;
    }

    inline int getval(int k) {
        return rsq(k+1) - rsq(k);
    }
    
    inline void adjust(int k, int v) {
        for (int i = k; i < ft.size(); i |= i+1) ft[i] += v; }
};

int main() {
    int n,k,i,l,r;
    char op;
    
    cin >> n >> k;
    FenwickTree fw(n);
    
    for (int j = 0; j < k; j++) {
        cin >> op;
        if (op == 'F') {
            cin >> i;
            
            int val = fw.getval(i);
            if (!val) val = 1;
            else val = -1;
            
            fw.adjust(i, val);
        }
        if (op == 'C') {
            cin >> l >> r;
            cout << fw.rsq(r+1) - fw.rsq(l) << endl;
        }
    }
    
    return 0;
}
