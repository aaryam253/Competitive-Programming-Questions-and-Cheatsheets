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
        int power;
        int numSnaps;
        cin >> power >> numSnaps;
        
        int r = ((1<<power)-1);
        
        if ((r & numSnaps) == r)
            cout << "Case #" << i << ": ON" << endl;
        else
            cout << "Case #" << i << ": OFF" << endl;

    }
    
}

