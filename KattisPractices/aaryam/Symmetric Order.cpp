//
//  main.cpp
//  Symmetric Order
//
//  Created by Aaryam Srivastava on 19/2/2018.
//  Copyright © 2018 Developers. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, const char * argv[]) {
    int N, set = 1; string name;
    
    while (1) {
        cin >> N; if (N == 0) break;
        vector<string> odd, even;
        
        for (int i = 1; i <= N; i++) {
            cin >> name;
            if (i % 2) odd.push_back(name);
            else even.push_back(name);
        }
        
        reverse(even.begin(), even.end());
        cout << "SET " << set << endl;
        for (auto i : odd) cout << i << endl;
        for (auto j : even) cout << j << endl;
        set++;
        
    }
    
    return 0;
}
