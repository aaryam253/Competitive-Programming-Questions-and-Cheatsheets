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

long long counts = 0;

void primeFactors(long long n)
{
    // Print the number of 2s that divide n
    while (n%2 == 0)
    {
//        printf("%d ", 2);
        counts++;
        n = n/2;
    }
    
    // n must be odd at this point.  So we can skip
    // one element (Note i = i +2)
    for (long long i = 3; i <= sqrt(n); i = i+2)
    {
        // While i divides n, print i and divide n
        while (n%i == 0)
        {
//            printf("%d ", i);
            counts++;
            n = n/i;
        }
    }
    
    // This condition is to handle the case when n
    // is a prime number greater than 2
    if (n > 2)
//        printf ("%d ", n);
        counts++;
}

int main () {
    long long input; cin >> input;
    primeFactors(input);
    cout << counts << endl;
}
