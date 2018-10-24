#include <stdio.h>
#include <iostream>
#include <sstream>
#include <map>
#include <algorithm>

using namespace std;

int main () {
    int index = 1;
    while (true) {
        map<string, int> species;
        int num; cin >> num;
        if (!num) return 0;
        
        cin.ignore();
        while (num--) {
            //cin.ignore();
            string input;
            getline(cin, input);
            
            istringstream iss (input);
            string token;
            string last;
            while (getline(iss, token, ' '))
            {
                last = token;
            }
            transform(last.begin(), last.end(), last.begin(), ::tolower);
            
            species[last]++;
        }
        cout << "List " << index << ":" << endl;
        
        for (auto it : species) {
            cout << it.first << " | " << it.second << endl;
        }
        index++;

    }
}

