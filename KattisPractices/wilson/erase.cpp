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


bool checkInverse (string a, string b) {
    int totalCount = 0;
    for (int i = 0; i < a.length(); i++) {
        if (a[i] == '1' && b[i] == '0') {
            totalCount++;
        } else if (a[i] == '0' && b[i] == '1') {
            totalCount++;
        }
    }
    
    if (totalCount == a.length()) return true;
    return false;
}

int main () {
    int N; cin >> N;
    string A, B; cin >> A >> B;
    
    if (N%2){
        if (checkInverse(A, B)) cout << "Deletion succeeded" << endl;
        else cout << "Deletion failed" << endl;
    } else {
        if (A == B) cout << "Deletion succeeded" << endl;
        else cout << "Deletion failed" << endl;
    }
    
    
}
