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

#define MAX 2147483646

using namespace std;


int main () {
    int groups; cin >> groups;
    while (groups--) {
        int num; cin >> num;
        int total = num;
        int i = 0;
        vector<int> gnomes;
        
        while (num--) {
            int input; cin >> input;
            gnomes.push_back(input);
        }
//        cout << gnomes.size() << endl;
        for (i = 1; i < total; i++) {
            if (gnomes[i] - gnomes[i-1] == 1) {
            } else {
//                cout << gnomes[i] << endl;
                break;
            }
        }
        
        cout << i+1 << endl;
    }
    
}
