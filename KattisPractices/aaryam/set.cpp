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
    vector<string> cards;
    vector<string> triplets;
    
    string line, card;
    for (int i = 0; i < 4; i++) {
        getline(cin, line);
        istringstream iss(line);
        
        while (iss >> card) cards.push_back(card);
    }
    
    for (int i = 0; i < 10; i++) {
        for (int j = i+1; j < 11; j++) {
            for (int k = j+1; k < 12; k++) {
                int diffat = 0, sameat = 0;
                for (int s = 0; s < 4; s++) {
                    if (cards[i][s] == cards[j][s] && cards[i][s] == cards[k][s]) sameat++;
                    if (cards[i][s] != cards[j][s] && cards[j][s] != cards[k][s] && cards[k][s] != cards[i][s]) diffat++;
                }
                if (diffat + sameat == 4) triplets.push_back(to_string(i+1) + ' ' + to_string(j+1) + ' ' + to_string(k+1));
            }
        }
    }

    if (triplets.size() == 0) cout << "no sets" << endl;
    for (auto ans : triplets) cout << ans << endl;
    
    return 0;
}
