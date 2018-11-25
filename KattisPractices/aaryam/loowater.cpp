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
#include <utility>
#define LSOne(S) (S & (-S))
using namespace std;

typedef unsigned long long ull;
typedef pair<int, string> ps;
typedef pair<int, int> p;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<int>> vii;
typedef vector<vector<ll>> vvll;
typedef priority_queue<int, vector<int>, greater<>> pqmin;

int main() {
    int n,m,d,h;
    
    while (cin >> n >> m) {
        if (!n && !m) break;
        
        pqmin heads;
        pqmin knights;
        
        for (int i = 0; i < n; i++) {
            cin >> d; heads.push(d);
        }
        
        for (int i = 0; i < m; i++) {
            cin >> h; knights.push(h);
        }
        
        int price = 0;
        while (1) {
            if (heads.size() == 0) {
                cout << price << endl; break;
            }
            
            if (knights.size() == 0 && heads.size() > 0) {
                cout << "Loowater is doomed!" << endl; break;
            }
            
            while (knights.top() < heads.top()) knights.pop();
            
            if (knights.size() == 0 && heads.size() > 0) {
                cout << "Loowater is doomed!" << endl; break;
            }
            
            price += knights.top(); heads.pop(); knights.pop();
        }
    }

    return 0;
}
