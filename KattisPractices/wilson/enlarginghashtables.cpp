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

#define MAX 2147483640

using namespace std;

bool isPrime (long long num) {
    if (num == 2) return true;
    for(long long i=2; i < sqrt(num)+1; i++)
        if (num % i == 0)
            return false;
    
    return true;
}

int main () {
//    cout << isPrime(5) << endl;
    while (true) {
        long long num; cin >> num;
        if (!num) break;
        if (!isPrime(num)) {
            long long i = num*2;
            while (true) {
                if (isPrime(i)) {
                    // print here
                    cout << i << " (" << num << " is not prime)" << endl;
                    break;
                } else {
                    i++;
                }
            }
        } else {
            long long i = num*2;
            while (true) {
                if (isPrime(i)) {
                    // print here
                    cout << i << endl;
                    break;
                } else {
                    i++;
                }
            }

        }
    }
}
