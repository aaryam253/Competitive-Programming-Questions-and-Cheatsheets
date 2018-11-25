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

int main() {
    int n,k,c1,c2;
    string p1,p2;
    
    cin >> n >> k;
    vector<string> cards(n, "unknown");
    
    for (int i = 0; i < k; i++) {
        cin >> c1 >> c2 >> p1 >> p2;
        
        if (p1 == p2) {
            cards[c1-1] = "taken";
            cards[c2-1] = "taken";
        }
        
        if (cards[c1-1] == "unknown") cards[c1-1] = p1;
        
        if (cards[c2-1] == "unknown") cards[c2-1] = p2;
    }
    
    int pairs = 0;
    for (int i = 0; i < cards.size(); i++) {
        for (int j = 0; j < cards.size(); j++) {
            if (j == i) continue;
            if (cards[j] == cards[i] && (cards[j] != "unknown" && cards[i] != "unknown") && (cards[j] != "taken" && cards[i] != "taken")) {
                cards[j] = "repeated";
                cards[i] = "repeated";
            }
        }
    }
    
    int rep = 0, unique = 0, unknown = 0;
    for (int i = 0; i < cards.size(); i++) {
        if (cards[i] == "repeated") rep++;
        else if (cards[i] == "unknown") unknown++;
        else if (cards[i] != "taken") unique++;
    }
    
    pairs += rep/2;
    if (unique >= unknown) pairs += unique;
    else if (unknown == 2) pairs += 1;
    
    cout << pairs << endl;
    
    return 0;
}
