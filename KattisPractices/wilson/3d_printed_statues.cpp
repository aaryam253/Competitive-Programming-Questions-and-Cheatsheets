#include <stdio.h>
#include <iostream>
#include <math.h>


using namespace std;

int count_printers (int num_days) {
    int num_printers = 1, i;
    for (i = 0; i < num_days; i++) {
        if (i == 0) {
            // Day zero
            num_printers++;
        }else {
            num_printers += pow(2, i);
        }
    }
    
    return num_printers;
}


int main () {
    int num, i;
    scanf("%d", &num);

    for (i = 0; i < num; i++) {
        if (count_printers(i) >= num) break;
    }
    
    printf("%d\n", i+1);
}
