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

#define MAX 1e9

using namespace std;


int main () {
    int num, d; cin >> num >> d;
    for (int i = 0; i < num; i++) {
        int number; cin >> number;
        if (number <= d) {
            cout << "It hadn't snowed this early in " << i << " years!" << endl;
            return 0;
        }

    }
    
    cout << "It had never snowed this early!" << endl;
}


