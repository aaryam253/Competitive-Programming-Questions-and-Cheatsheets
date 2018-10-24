#include <stdio.h>

using namespace std;

int main () {
    long long arr[100000];
    long long smallest [100000] = {0};
    long long largest [100000] = {0};
    int num;
    scanf("%d", &num);
    for (int i = 0; i < num; i++) {
        scanf("%llu", &arr[i]);
        if (!i) {
            largest[i] = arr[i];
        }else {
            if (arr[i] > largest[i-1]) {
                largest[i] = arr[i];
            }else {
                largest[i] = largest[i-1];
            }
        }
    }
    
    for (int i = num-1; i >= 0  ; i--) {
        if (i == num-1) {
            smallest[i] = arr[i];
        }else {
            if (arr[i] < smallest[i+1]) {
                smallest[i] = arr[i];
            }else {
                smallest[i] = smallest[i+1];
            }
        }
    }
    
    int count = 0;
    // Count possible pivots here
    for (int i = 0; i < num; i++) {
        if (arr[i] < largest[i] || arr[i] > smallest[i]) continue;
        else count++;
    }
    
    printf("%d\n", count);
}
