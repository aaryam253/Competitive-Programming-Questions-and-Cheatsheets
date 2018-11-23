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
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vii;

int main() {
    //total depth of the BST
    ull totalheight = 0;
    int n, point, depth = 0; cin >> n;
    //keeps track of order of points, as well as their heights
    set<int> visited; vector<int> height(n+2,0);
    
    for (int i = 0; i < n; i++) {
        cin >> point;
        visited.insert(point);
        
        auto it = visited.find(point);
        
        //conditions to check the depth of the point
        if (it != visited.begin()) {
            it--; if (height[*(it)] > depth) depth = height[*(it)];
        }
        
        it = visited.find(point);
        
        if (it != visited.end()) {
            it++; if (it != visited.end()) {
               if (height[*(it)] > depth) depth = height[*(it)];
            }
        }
        
        totalheight += depth;
        cout << totalheight << endl;
        
        //increment depth of the point by 1 after the addition
        height[point] = depth+1; depth = 0;
    }
    
    return 0;
}