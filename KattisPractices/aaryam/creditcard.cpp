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

ll add(ll r, ll b) {
    ll addition = r*b;
    bool up = addition % 10000 >= 5000;
    
    return addition / 10000 + up;
}

int main() {
    int t, payments = 0;
    double R,B,M;
    
    cin >> t;
    while (t--) {
        cin >> R >> B >> M; payments = 0;
        ll b = (B * 100.0 + 0.5), m = (M * 100.0 + 0.5), r = (R * 100.0 + 0.5);
        
        while (1) {
            if (payments > 1199) {
                cout << "impossible" << endl; break;
            }
            
            b += add(r, b);
            b -= m;
            
            payments++;
            
            if (b <= 0) {
                cout << payments << endl; break;
            }
        }
    }
    
    return 0;
}
