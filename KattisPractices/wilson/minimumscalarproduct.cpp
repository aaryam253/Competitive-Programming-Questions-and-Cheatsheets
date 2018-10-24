#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int main () {
    int numCases;
    cin >> numCases;
    
    for (int i = 1; i <= numCases; i++) {
        int size;
        cin >> size;
        vector<long long> v1, v2;
        for (int d = 0; d < size; d++) {
            int num;
            cin >> num;
            v1.push_back(num);
        }
        for (int d = 0; d < size; d++) {
            int num;
            cin >> num;
            v2.push_back(num);
        }
        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());
        reverse(v2.begin(), v2.end());
        
        long long total = 0;
        for (int d = 0; d < size; d++) {
            total += v1[d]*v2[d];
        }
        
        cout << "Case #" << i << ": " << total << endl;
        
        
    }
}

