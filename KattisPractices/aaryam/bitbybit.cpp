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
#include <algorithm>
#include <math.h>
using namespace std;

int main (void) {
    while (1) {
        int n; cin >> n;
        if (!n) break;
        
        char bits[32]; for (int i = 0; i < 32; i++) bits[i] = '?';
        
        while (n--) {
            string op; cin >> op;
            if (op == "CLEAR") {
                int i; cin >> i;
                bits[i] = '0';
            }
            else if (op == "SET") {
                int i; cin >> i;
                bits[i] = '1';
            }
            else if (op == "OR") {
                int i,j; cin >> i >> j;
                if (bits[i] == '1' || bits[j] == '1') bits[i] = '1';
                else if (bits[i] == '?' || bits[j] == '?') bits[i] = '?';
                else bits[i] = '0';
            }
            else if (op == "AND") {
                int i,j; cin >> i >> j;
                if (bits[i] == '0' || bits[j] == '0') bits[i] = '0';
                else if (bits[i] == '?' || bits[j] == '?') bits[i] = '?';
                else bits[i] = '1';
            }
        }
        
        for (int i = 31; i >= 0; i--) cout << bits[i];
        cout << endl;
    }
    
    return 0;
}