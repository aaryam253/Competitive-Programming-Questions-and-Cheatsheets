#include <iostream>
#include <stdio.h>
#include <math.h>
#include <list>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <algorithm>
#include <tuple>
#include <string.h>
#include <sstream>

using namespace std;

#define LSOne(S) ((S) & -(S))

/**
 * ================ Some general notes =====================
 * We use LSOne to step up or down from the indexes and which one to update eg i + LSOne(i) to move to the next index to update
 * All operations are done in O(Log(n))
 * We ignore the 1st index aka. 0th index
 */

typedef vector<int> vi;

class FenwickTree {
private:
    vi ft;
    int n;
    
    
public:
    FenwickTree(int _n) : n(_n) {
        ft.assign(n+1, 0); // n+1 zeroes
    }
    
    FenwickTree(const vi& f) : n(f.size()-1) {
        ft.assign(n+1, 0);
        for (int i = 1; i <= n; i++) {                                  // O(n)
            ft[i] += f[i];                                      // add this value
            
            if (i+LSOne(i) <= n)    // if index i has parent in the updating tree
                ft[i+LSOne(i)] += ft[i]; // add this value to that parent
        }
    }
    
    // returns RSQ(1, j)
    int rsq(int j) {
        int sum = 0;
        for (; j; j -= LSOne(j)) // Traverse down the indexes using LSOne
            sum += ft[j];
        
        return sum;
    }
    
    // returns RSQ(i, j)
    int rsq(int i, int j) {
        return rsq(j) - rsq(i-1);
    }
    
    // updates value of the i-th element by v (v can be +ve/inc or -ve/dec)
    void update(int i, int v) {
        // Since updating a lower index with +v will affect the higher indexes equally, we just add them equally to all the higher indexes
        for (; i <= n; i += LSOne(i)) {
            cout << i << " + " << LSOne(i) << endl;
            ft[i] += v;
        }
        // note: n = ft.size()-1
    }
    
    // O(log^2 n)
    int select(int k) {
        int lo = 1, hi = n;
        for (int i = 0; i < 30; i++) { // 2^30 > 10^9 > usual Fenwick Tree size
            int mid = (lo+hi) / 2;                    // Binary Search the Answer
            (rsq(1, mid) < k) ? lo = mid : hi = mid; }
        return hi; }
};


class RUPQ : FenwickTree {    // RUPQ variant is a simple extension of PURQ
public:
    RUPQ(int n) : FenwickTree(n) {}
    
    int point_query(int i) {
        return rsq(i);
    }
    
    void range_update(int i, int j, int v) {
        update(i, v), update(j+1, -v);
    }
    
};


int main() {
    // idx   0 1 2 3 4 5 6 7  8 9 10, no index 0!
    FenwickTree ft1(10);     // ft = {-,0,0,0,0,0,0,0, 0,0,0}
    ft1.update(1, 1);        // ft = {-,0,1,0,1,0,0,0, 1,0,0}, idx 2,4,8 => +1
    
    printf("%d\n", ft1.rsq(1, 1));  // 0 => ft[1] = 0
    
    
    cout << "===============================" << endl;

    RUPQ rupq(10) ;                        // empty Fenwick Tree with 10 keys
    rupq.range_update(2, 9, 7);     // indices in [2, 3, .., 9] updated by +7
    cout << rupq.point_query(4) << endl; // We just check for that one point - will return 7
    cout << rupq.point_query(9) << endl; // returns 7
    
    return 0;
}
