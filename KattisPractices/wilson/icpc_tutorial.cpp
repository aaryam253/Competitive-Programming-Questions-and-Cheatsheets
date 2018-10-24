#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;

double m;

int checkTLE (double current) {
    if (current > m) return  1;
    
    return 0;
}

int main () {
    int input;
    int type;
    scanf("%lf %d %d", &m, &input, &type);
    
    double answer;
    switch (type) {
        case 1:
            // factorial
            answer = input;
            for (long int i = input-1; i >= 1; i--) {
                answer *= i;
                if (checkTLE(answer)) {
                    printf("TLE\n");
                    return 0;
                }
            }
            printf("AC\n");
            break;
        case 2:
            // 2^n
            for (int i = 1; i <= input; i++) {
                answer = (int)pow(2, i);
                if (checkTLE(answer)) {
                    printf("TLE\n");
                    return 0;
                }
            }
            printf("AC\n");
            break;
        case 3:
            // n^4
            for (int i = 1; i <= 4; i++) {
                answer = (int)pow(input, i);
                if (checkTLE(answer)) {
                    printf("TLE\n");
                    return 0;
                }
            }
            printf("AC\n");
            break;
        case 4:
            // n^3
            for (int i = 1; i <= 3; i++) {
                answer = (int)pow(input, i);
                if (checkTLE(answer)) {
                    printf("TLE\n");
                    return 0;
                }
            }
            printf("AC\n");
            break;
        case 5:
            // n^2
            for (int i = 1; i <= 2; i++) {
                answer = (int)pow(input, i);
                if (checkTLE(answer)) {
                    printf("TLE\n");
                    return 0;
                }
            }
            printf("AC\n");
            break;
        case 6:
            // nlog2(n)
            for (int i = 1; i <= input; i++) {
                answer = i * log2(i);
                if (checkTLE(answer)) {
                    printf("TLE\n");
                    return 0;
                }
            }
            printf("AC\n");
            break;
        case 7:
            // n
            answer = input;
            if (checkTLE(answer)) {
                printf("TLE\n");
            }else{
                printf("AC\n");
            }
            break;
            
        default:
            break;
    }
    
}
