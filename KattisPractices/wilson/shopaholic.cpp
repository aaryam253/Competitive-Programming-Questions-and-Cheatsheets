#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int main () {
    vector<int> list;
    int num;
    scanf("%d", &num);
    
    for (int i = 0; i < num; i++) {
        int input;
        scanf("%d", &input);
        list.push_back(input);
    }
    
    sort(list.begin(), list.end());
    int count = 0;
    unsigned long long totalDisc = 0;
    for (int i = num-1; i >= 0; i--) {
        count++;
        if (count >= 3) {
            count = 0;
            totalDisc += list[i];
        }
    }
    
    cout << totalDisc << endl;
    
}
