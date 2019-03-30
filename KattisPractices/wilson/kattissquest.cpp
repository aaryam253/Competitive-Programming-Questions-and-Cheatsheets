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

#define MAX 2147483646

#ifdef _WIN32
#define getchar_unlocked getchar
#endif
// DO NOT REMOVE THE CODE ABOVE
#include <cstdio>

using namespace std;



int main () {
    multiset<pair<int, int>> mymap; // Use a multiset to handle duplicates
    int N; cin >> N;
    
    while (N--) {
        string cmd; cin >> cmd;
        
        if (cmd == "add") {
            int a, b; cin >> a >> b;
            mymap.insert({a,b});
        } else {
            int x; cin >> x;
            long long total = 0; // Most students forgot to use long long 
            
            auto it = mymap.upper_bound({x, MAX}); // Trick, we wanna find the maximum gold if energy values are the same
            
            if (it != mymap.begin())
                it = prev(it); // If our iterator is not begin, we decrement by one
            
            while (!mymap.empty()) {
                if (x < (*it).first) {
                    break;
                }
                
                total += (*it).second;
                x -= (*it).first;
                mymap.erase(it); // Make sure to erase the element
                
                
                it = mymap.upper_bound({x, MAX});
                if (it != mymap.begin())
                    it = prev(it); // If our iterator is not begin, we decrement here by one as well
            }
            
            
            cout << total << endl;
        }
    }
    
}
