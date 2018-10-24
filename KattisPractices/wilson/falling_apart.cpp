#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;


int main () {
    
    int num;
    vector<int> numbers;
    cin >> num;
    for (int i = 0; i < num; i++) {
        int number;
        cin >> number;
        numbers.push_back(number);
    }
    
    sort(numbers.begin(), numbers.end());
    
    bool toggle = true;
    
    int Alice = 0, Bob = 0;
    for (int i = numbers.size()-1; i >= 0; i--) {
        if (toggle) {
            Alice += numbers[i];
            toggle = false;
        }else {
            Bob += numbers[i];
            toggle = true;
        }
        
    }
    
    cout << Alice << " " << Bob << endl;
    
}

