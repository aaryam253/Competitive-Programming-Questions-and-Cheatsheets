#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <queue>
#include <stack>
#include <math.h>
using namespace std;

int main (void) {
    int n; cin >> n;
    int points = 0;
    int startf = 2;
    
    while (startf * startf <= n) {
        if (n % startf == 0) {
            n /= startf;
            points++;
        }
        else startf++;
    }
    
    cout << points + 1 << endl;
    
    return 0;
}
