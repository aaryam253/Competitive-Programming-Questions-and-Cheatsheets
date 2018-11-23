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

//faster UFDS algorithm that optimises in certain areas
class UnionFindFast {
private:
    //only consider the set and its rank
    vi p, rank;
public:
    //construct the UFDS
    UnionFindFast(int N) {
        p.assign(N, 0); rank.assign(N, 0);
        for (int i = 0; i < N; i++) { p[i] = i; rank[i] = 0;}
    }
    
    //use a base function, which resembles the representative root of each set
    bool isSameSet(int a, int b) {return base(a) == base(b);}
    
    //union of two sets
    void unionSet(int a, int b) {
        int i = base(a); int j = base(b);
        if (i == j) return;
        
        //check rank to see which tree will be appended on to another tree
        if (rank[i] < rank[j]) p[i] = j;
        else if (rank[i] > rank[j]) p[j] = i;
        else {p[j] = i; rank[i] = rank[i] + 1;}
    }
    
    //find the representation root of each set
    int base(int a) {
        while (a != p[a]) a = p[a];
        return a;
    }
};

int main (void) {
    int n,q,a,b;
    char op[2];
    scanf("%d%d",&n,&q);
    
    UnionFindFast UF(n);
    for (int i = 0; i < q; i++) {
        scanf("%2s%d%d",op,&a,&b);

        if (op[0] == '=') UF.unionSet(a, b);
        else {
            if (UF.isSameSet(a, b)) cout << "yes" << endl;
            else cout << "no" << endl;
        }
    }
    
    return 0;
}