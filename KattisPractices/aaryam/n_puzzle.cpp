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
    char nboard[4][4] = {{'A','E','I','M'},{'B','F','J','N'},{'C','G','K','O'},{'D','H','L','.'}};

    int scatter = 0;
    char t;
    
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cin >> t;
            
            for (int k = 0; k < 4; k++) {
                for (int m = 0; m < 4; m++) {
                    if (nboard[m][k] == t && t != '.') {
                        scatter += abs(i - k) + abs(j - m);
                    }
                }
            }
        }
    }
    
    cout << scatter << endl;
    
    return 0;
}
