#include <iostream>
#include <stdio.h>
#include <unordered_set>
#include <string>

using namespace std;

int main () {
    int TC;
    cin >> TC;
    for (int i = 0; i < TC; i++) {
        int n;
        cin >> n;
        unordered_set<string> myset;
        for (int d = 0; d < n; d++) {
            string input;
            cin >> input;
            myset.insert(input);
        }
        
        cout << myset.size() << endl;
    }
}
