#include <iostream>
#include <stdio.h>


using namespace std;

int main () {
    int a, b, c;
    cin >> a >> b >> c;
    int groups = b / c;
    int i = 0;
    while (a > 1) {
        a -= groups;
        i++;
    }
    cout << i << endl;
}
