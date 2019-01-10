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
    int A, B, C; cin >> A >> B >> C;
    int I, J, K; cin >> I >> J >> K;
    
    double a, b, c;
    a = A/(double)I;
    b = B/(double)J;
    c = C/(double)K;
    
    if (a <= b && a <= c) {
        double minimum = a;
        cout << A - minimum*I << " ";
        cout << B - minimum*J << " ";
        cout << C - minimum*K << endl;
    } else if (b <= c && b <= a) {
        double minimum = b;
        cout << A - minimum*I << " ";
        cout << B - minimum*J << " ";
        cout << C - minimum*K << endl;

    } else if (c <= a && c <= b) {
        double minimum = c;
        cout << A - minimum*I << " ";
        cout << B - minimum*J << " ";
        cout << C - minimum*K << endl;
    }
    
}
