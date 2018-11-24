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
typedef vector<vector<int>> vii;
typedef vector<ll> vll;

class FenwickTree {
private:
    vll ft;
public:
    FenwickTree() {}
    
    FenwickTree(int n) {
        ft.assign(n+1, 0);
    }
    
    inline long long rsq(int b) {
        long long sum = 0; for (; b; b -= LSOne(b)) sum += ft[b];
        return sum;
    }

    inline void update(int k, long long v) {
        for(; k < (int)ft.size(); k += LSOne(k)) ft[k] += v;
    }
};

int main() {
    int n,q,i; long long upd;
    char op;
    scanf("%d%d", &n, &q);
    FenwickTree fw(n);
    for (; q; q--) {
        scanf(" %c ", &op);
        if (op == '+') {
            scanf("%d%lld", &i, &upd);
            fw.update(i+1, upd);
        } else {
            scanf("%d", &i);
            if (!i) printf("0\n");
            else printf("%lld\n", fw.rsq(i));
        }
    }
    
    return 0;
}
