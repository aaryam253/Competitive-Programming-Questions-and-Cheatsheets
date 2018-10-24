#include <iostream>
#include <stdio.h>
#include <unordered_map>
#include <unordered_set>

using namespace std;


int main () {
    int numCases;
    cin >> numCases;
    for (int i = 1; i <= numCases; i++) {
        int pax, pax_count = 0;
        cin >> pax;
        pax_count = pax;
        unordered_map<int, int> map;
        unordered_set<int> singles;
        for (int d = 0; d < pax; d++) {
            int num;
            cin >> num;
            singles.insert(num);
            map[num]++;
            if (map[num] == 2) {
                singles.erase(singles.find(num)); // Will finding take very long?
            }
        }
        cout << "Case #" << i << ": ";
        cout << *singles.begin() << endl;
    }
}

