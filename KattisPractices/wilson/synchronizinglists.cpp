#include <stdio.h>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main () {
    int num;
    while (true) {
        vector<pair<int, int> > setA;
        vector<pair<int, int> > setB;
        vector<pair<int, int> > original;
        

        cin >> num;
        if (!num) return 0;
        for (int i = 0; i < num; i++) {
            int number;
            cin >> number;
            setA.push_back(make_pair(number, 0));
            original.push_back(make_pair(number, 0));
            
        }
        sort(setA.begin(), setA.end());
        for (int i = 0; i < num; i++) {
            setA[i].second = i;
        }
        // Match them up
        for (int i = 0; i < num; i++) {
            for (int d = 0; d < num; d++) {
                if (original[i].first == setA[d].first) original[i].second = setA[d].second;
            }
        }
        
        for (int i = 0; i < num; i++) {
            int number;
            cin >> number;
            setB.push_back(make_pair(number, 0));
        }
        
        sort(setB.begin(), setB.end());
        for (int i = 0; i < num; i++) {
            setB[i].second = i;
        }
        
        for (int i = 0; i < num; i++) {
            for (int d = 0; d < num; d++) {
                if (original[i].second == setB[d].second) cout << setB[d].first << endl;
            }
        }
        cout << endl;
    }
    
}

