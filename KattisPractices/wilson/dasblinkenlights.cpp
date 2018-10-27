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

int LCM(int n1, int n2) {
    int max;
    // maximum value between n1 and n2 is stored in max
    max = (n1 > n2) ? n1 : n2;
    do
    {
        if (max % n1 == 0 && max % n2 == 0)
        {
            return max;
            break;
        }
        else
            ++max;
    } while (true);
}


int main () {
    int p, q, s;
    cin >> p >> q >> s;
    
    if (LCM(p, q) <= s)
        cout << "yes" << endl;
    else
        cout << "no" << endl;
}
