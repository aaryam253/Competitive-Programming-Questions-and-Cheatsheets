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

#define MAX 2147483640

using namespace std;


int main () {
    int mtx[1001] = {};
    int size; cin >> size;
    
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            int num; cin >> num;
            mtx[i] |= num;
        }
    }
    
    for (int i = 0; i < size; i++) {
        cout << mtx[i] << " ";
    }
    cout << endl;
}
