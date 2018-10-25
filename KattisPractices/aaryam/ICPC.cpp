#include <bits/stdc++.h>
using namespace std;

unsigned long long operate(unsigned long long size, unsigned long long power, unsigned long long type) {
    switch (type) {
        case 1:
            for (int i = 1; i < size; i++) {
                size *= i;
                if (size > power) break;
            }
            return size;
            break;
        case 2:
            size = pow(2, size);
            return size;
            break;
        case 3:
            size = pow(size, 4);
            return size;
            break;
        case 4:
            size = pow(size, 3);
            return size;
            break;
        case 5:
            size = pow(size, 2);
            return size;
            break;
        case 6:
            size = size * log2(size);
            return size;
            break;
        default:
            return size;
    }
}



int main (void) {
    unsigned long long power, size, type;
    cin >> power >> size >> type;
    unsigned long long operations = operate(size, power, type);
    
    if (operations <= power) cout << "AC" << endl;
    else cout << "TLE" << endl;
    return 0;
}
