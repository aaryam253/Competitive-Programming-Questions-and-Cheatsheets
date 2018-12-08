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
#define NOTHING -1
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
    int w,l;
    int house = 0;
    
    while (cin >> w >> l) {
        house++;
        if (!w && !l) break;
        int x,y, startx = 0, starty = 0, startdir = 0, dir;
        char area[l][w];
        
        for (int i = 0; i < l; i++) {
            for (int j = 0; j < w; j++) {
                cin >> area[i][j];
                if (area[i][j] == '*') {
                    if (i == 0) startdir = 2;
                    if (i == l-1) startdir = 0;
                    if (j == 0) startdir = 1;
                    if (j == w-1) startdir = 3;
                    startx = j; starty = i;
                }
            }
        }
        
        x = startx; y = starty; dir = startdir;
  
        while (area[y][x] != 'x') {
            if (dir == 0) y--;
            if (dir == 1) x++;
            if (dir == 2) y++;
            if (dir == 3) x--;
            
            if (area[y][x] == '/') {
                if (dir == 0) dir = 1;
                else if (dir == 1) dir = 0;
                else if (dir == 2) dir = 3;
                else if (dir == 3) dir = 2;
            }
            
            if (area[y][x] == '\\') {
                if (dir == 0) dir = 3;
                else if (dir == 1) dir = 2;
                else if (dir == 2) dir = 1;
                else if (dir == 3) dir = 0;
            }
        }
        
        area[y][x] = '&';
        
        cout << "HOUSE " << house << endl;
        for (int i = 0; i < l; i++) {
            for (int j = 0; j < w; j++) {
                cout << area[i][j];
            } cout << endl;
        }
    }
    return 0;
}
