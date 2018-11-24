#include <bits/stdc++.h>
using namespace std;

int main () {
    int n; cin >> n;
    long long ans = pow(2,n) + 1;
    ans = pow(ans, 2);
    
    printf("%d\n", ans);
    return 0;
}
