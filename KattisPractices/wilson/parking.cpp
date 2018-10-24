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
    int max = 0;
    int A, B, C; cin >> A >> B >> C;
    int arr[101] = {0};
    for (int i = 0; i < 3; i++) {
        int start, end; cin >> start >> end;
        start--;
        end--;
        for (int j = start; j < end; j++) {
            arr[j]++;
        }
        
        if (end > max) {
            max = end;
        }
    }
    long long total = 0;
    for (int i = 0; i < max; i++) {
        switch (arr[i]) {
            case 1:
                total += A;
                break;
            case 2:
                total += 2*B;
                break;
            case 3:
                total += 3*C;
                break;
        }
//        cout << arr[i] << " ";
    }
//    cout << endl;
    cout << total << endl;
}
