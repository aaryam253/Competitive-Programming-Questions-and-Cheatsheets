
#include <stdio.h>
#include <iostream>
#include <set>
#include <math.h>

using namespace std;


int main () {
    set<long long> myset;
    long long candy;
    cin >> candy;
    
    for (int i = 1; i <= ceil(sqrt(candy)); i++) {
        if (candy % i == 0) {
            myset.insert(i);
            myset.insert(candy/i);
        }

    }
    
    for (auto it = myset.begin(); it != myset.end() ; it++) {
        cout << *it-1 << " ";
    }
    cout << endl;
}

