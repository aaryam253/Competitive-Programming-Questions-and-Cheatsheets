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

char board[17][34] = {
    {"+---+---+---+---+---+---+---+---+"},
    {"|...|:::|...|:::|...|:::|...|:::|"},
    {"+---+---+---+---+---+---+---+---+"},
    {"|:::|...|:::|...|:::|...|:::|...|"},
    {"+---+---+---+---+---+---+---+---+"},
    {"|...|:::|...|:::|...|:::|...|:::|"},
    {"+---+---+---+---+---+---+---+---+"},
    {"|:::|...|:::|...|:::|...|:::|...|"},
    {"+---+---+---+---+---+---+---+---+"},
    {"|...|:::|...|:::|...|:::|...|:::|"},
    {"+---+---+---+---+---+---+---+---+"},
    {"|:::|...|:::|...|:::|...|:::|...|"},
    {"+---+---+---+---+---+---+---+---+"},
    {"|...|:::|...|:::|...|:::|...|:::|"},
    {"+---+---+---+---+---+---+---+---+"},
    {"|:::|...|:::|...|:::|...|:::|...|"},
    {"+---+---+---+---+---+---+---+---+"},
};

int main() {
    string white;
    string black;
    
    getline(cin, white);
    getline(cin, black);
    
    string wpieces = white.substr(7, white.size() - 1);
    string bpieces = black.substr(7, black.size() - 1);
    
    vector<string> w;
    stringstream iss(wpieces);
    string i;
    while (getline(iss, i, ',')) {
        w.push_back(i);
    }
    
    vector<string> b;
    stringstream iss2(bpieces);
    string j;
    while (getline(iss2, j, ',')) {
        b.push_back(j);
    }

    for (int i = 0; i < w.size(); i++) {
        if (w[i].size() == 2) {
            int row = 16 - ((2 * (w[i][1] - '0')) - 1);
            int col = 4*(w[i][0] - 'a') + 2;
            
            board[row][col] = 'P';
        } else {
            int row = 16 - ((2 * (w[i][2] - '0')) - 1);
            int col = 4*(w[i][1] - 'a') + 2;
            
            board[row][col] = w[i][0];
        }
    }
    
    for (int i = 0; i < b.size(); i++) {
        if (b[i].size() == 2) {
            int row = 16 - ((2 * (b[i][1] - '0')) - 1);
            int col = 4*(b[i][0] - 'a') + 2;
            
            board[row][col] = 'p';
        } else {
            int row = 16 - ((2 * (b[i][2] - '0')) - 1);
            int col = 4*(b[i][1] - 'a') + 2;
            
            board[row][col] = tolower(b[i][0]);
        }
    }
    
    for (int i = 0; i < 17; i++) {
        for (int j = 0; j < 33; j++) {
            cout << board[i][j];
        }
        cout << endl;
    }
    
    return 0;
}
