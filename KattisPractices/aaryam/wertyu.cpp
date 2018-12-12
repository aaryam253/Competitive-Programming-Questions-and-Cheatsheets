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
    unordered_map<char, char> keyboard = {{'1','1'}, {'2','1'}, {'3','2'}, {'4','3'}, {'5','4'}, {'6','5'},
        {'7','6'},{'8','7'},{'9','8'},{'0','9'},{'-','0'},{'=','-'},{'W','Q'},{'E','W'},{'R','E'},{'T','R'},
        {'Y','T'},{'U','Y'},{'I','U'},{'O','I'},{'P','O'},{'[','P'},{']','['},{'\\',']'},{'S','A'},{'D','S'},
        {'F','D'},{'G','F'},{'H','G'},{'J','H'},{'K','J'},{'L','K'},{';','L'},{'\'',';'},{'X','Z'},{'C','X'},
        {'V','C'},{'B','V'},{'N','B'},{'M','N'},{',','M'},{'.',','},{'/','.'}};
    
    string line;
    while (getline(cin, line)) {
        for (int i = 0; i < line.size(); i++) {
            if (line[i] == ' ') cout << ' ';
            else cout << keyboard[line[i]];
        } cout << endl;
    }
    
    return 0;
}
