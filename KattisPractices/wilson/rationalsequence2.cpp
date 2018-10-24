#include <iostream>
#include <stdio.h>
#include <stack>

using namespace std;


int main () {
    stack<pair<int, int > > nodes;
    int TC; cin >> TC;
    while (TC--) {
        int c; cin >> c;
        char dummy;
        
        int a, b;
        cin >> a >> dummy >> b;
        int a_ = a, b_ = b;
        while (a != 1 || b != 1) {
            if (a > b) {
                a -= b;
                nodes.push(make_pair(a, b));
            }
            else {
                b -= a;
                nodes.push(make_pair(a, b));
            }
        }
        long long index = 1;
        while (!nodes.empty()) {
            if (nodes.top().first > nodes.top().second) {
                // traverse right
                index = 2*index + 1;
            }else if (nodes.top().first < nodes.top().second){
                // Traverse left
                index = 2*index;
            }
            nodes.pop();
        }
        if (a_ != 1 || b_ != 1) {
            if (a_ > b_) index = 2*index + 1;
            else index = 2*index;
        }
        cout << c << " " << index << endl;
    }
}
