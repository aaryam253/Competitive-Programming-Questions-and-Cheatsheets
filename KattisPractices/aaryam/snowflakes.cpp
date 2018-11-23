#include <iostream>
#include <map>
#include <set>
#include <utility>
#include <string>
#include <queue>
#include <list>
#include <vector>
#include <stack>
#include <unordered_set>
#include <unordered_map>
#include <string.h>
#include <cctype>
#include <cstring>
using namespace std;

int main(int argc, const char * argv[]) {
    int t,n,size;
    unordered_map<int, bool> duplicate;
    
    cin >> t;
    while (t--) {
        cin >> n;
        int max = 0;
        queue<int> LIS;
        
        for (int i = 0; i < n; i++) {
            cin >> size;
            if (duplicate[size]) {
                while (LIS.front() != size) {
                    duplicate[LIS.front()] = false; LIS.pop();
                } LIS.pop();
            } else duplicate[size] = true;
            LIS.push(size);
            
            if (LIS.size() > max) max = LIS.size();
        }
        
        while (!LIS.empty()) {
            duplicate[LIS.front()] = false; LIS.pop();
        }
        
        cout << max << endl;
        
    }
    
    
    return 0;
}