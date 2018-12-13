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
#define INTMAX 99999999
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
    int N, M;
    while (1) {
        cin >> N >> M;
        if (!N && !M) break;
        int So, De, S, D;
        vector<pair<int, int>> calls;
        
        for (int i = 0; i < N; i++) {
            cin >> So >> De >> S >> D;
            calls.push_back(make_pair(S, S + D - 1));
        }
        
        for (int i = 0; i < M; i++) {
            cin >> S >> D;
            int call = 0;
            for (auto j : calls) {
                if (!(S + D - 1 < j.first || S > j.second)) call++;
            }
            cout << call << endl;
        }

    }
    return 0;
}
