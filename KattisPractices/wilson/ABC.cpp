#include <iostream>
#include <stdio.h>
#include <set>

using namespace std;

int main () {
    set<int> numbers;
    for (int i = 0; i < 3; i++) {
        int num;
        cin >> num;
        numbers.insert(num);
    }
    
    for (int i = 0; i < 3; i++) {
        char a;
        cin >> a;
        if (a == 'A') {
            cout << *numbers.begin() << " ";
        }
        else if (a == 'B') {
            cout << *(next(numbers.begin())) << " ";
        }
        
        else if (a == 'C') {
            cout << *(next(numbers.begin(), 2)) << " ";
        }
    }
    cout << endl;
}
