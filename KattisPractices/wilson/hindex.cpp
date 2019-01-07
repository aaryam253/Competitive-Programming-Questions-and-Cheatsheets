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

using namespace std;


int main () {
    int N; cin >> N;
    vector<unsigned long long> arr;
    for (int i = 0; i < N; i++) {
        unsigned long long input; cin >> input;
        arr.push_back(input);
    }
    
    sort(arr.rbegin(), arr.rend());
    vector<unsigned long long> arr2(arr.size(), 0);
    arr2[0] = arr[0];
    int count = 1;
    // Find minimum at each point
    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] < arr[i-1]) {
            arr2[i] = arr[i];
        } else {
            arr2[i] = arr2[i-1];
        }
    }
    int i;
    for (i = 0; i < arr2.size(); i++) {
        if ((i+1) > arr2[i]) {
            break;
        }
    }
    cout << i << endl;
}
