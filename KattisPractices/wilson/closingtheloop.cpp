#include <iostream>
#include <stdio.h>
#include <math.h>
#include <list>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <algorithm>
#include <tuple>
#include <string.h>
#include <sstream>
#include <iomanip>

#define MAX 2147483640

using namespace std;

int main() {
    int T; cin >> T;
    int count = 1;
    while (T--) {
        vector<int> red;
        vector<int> blue;
        
        
        int numRopes; cin >> numRopes;
        while (numRopes--) {
            string input; cin >> input;
            if (input[input.length()-1] == 'R') {
                // Red
                int l = stoi(input.substr(0, input.length()-1));
                red.push_back(l);
            } else {
                // Blue
                int l = stoi(input.substr(0, input.length()-1));
                blue.push_back(l);
            }
        }
        sort(red.rbegin(), red.rend());
        sort(blue.rbegin(), blue.rend());
        
        long long length = 0;
        for (int i = 0; i < red.size() && i < blue.size(); i++) {
            length += (red[i] + blue[i] - 2); // -2 because we account for chaining this pair to the main loop
        }
        cout << "Case #" << count++ << ": " << length << endl;

    }
    
}
