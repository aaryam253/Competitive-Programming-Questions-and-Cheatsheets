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

class UnionFind {
private:
    vi p, rank, setSize;
    int numSets;
public:
    UnionFind(int N) {
        setSize.assign(N, 1);
        numSets = N;
        rank.assign(N, 0);
        p.assign(N, 0);
        for (int i = 0; i < N; i++) p[i] = i;
    }
    int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
    
    bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
    
    void unionSet(int i, int j) {
        if (!isSameSet(i, j)) { numSets--;
            int x = findSet(i), y = findSet(j);
            
            if (rank[x] > rank[y]) { p[y] = x; setSize[x] += setSize[y]; }
            else                   { p[x] = y; setSize[y] += setSize[x];
                if (rank[x] == rank[y]) rank[y]++; } } }
};

int main (void) {
    int N,L,a,b; cin >> N >> L;
    UnionFind uf(L+1);
    vi empty(L+1, 1);
    
    for (int i = 0; i < N; i++) {
        cin >> a >> b;
        
        //combine the sets containing a and b
        if (!uf.isSameSet(a, b)) {
            int filled = empty[uf.findSet(a)] + empty[uf.findSet(b)];
            uf.unionSet(a, b); empty[uf.findSet(a)] = filled;
        }
        
        //is still empty, can be placed
        if (empty[uf.findSet(a)]) {
            empty[uf.findSet(a)]--;
            cout << "LADICA" << endl;
        }
        //cannot be placed, drawer is full
        else {
            cout << "SMECE" << endl;
        }
    }
    
    return 0;
}
