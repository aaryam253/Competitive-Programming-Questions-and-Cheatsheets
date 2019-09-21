#include <iostream>
#include <math.h>
using namespace std;

int main(void) {
    int printers = 1, statues, days = 0;
    
    cin >> statues;
    
    while (1) {
        if (statues == 1) {
            days = 1;
            break;
        }
        else if (printers >= statues) {
            days++;
            break;
        }
        
        printers += printers;
        days++;
    }
    
    cout << days << endl;
    
    return 0;
}
