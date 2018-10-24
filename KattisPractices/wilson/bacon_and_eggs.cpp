#include <stdio.h>
#include <iostream>
#include <set>
#include <map>
#include <sstream>

using namespace std;

int main () {
    
    while (true) {
        map<string, set<string> > breakfast;
        int num;
        cin >> num;
        if (!num) return 0;
        
        for (int i = 0; i < num; i++) {
            string name;
            cin >> name;
            string order;
            cin.ignore();
            getline(cin, order);
            istringstream iss (order);
            string token;
            
            while (getline(iss, token, ' '))
            {
                breakfast[token].insert(name);
            }
        }
        
        for (map<string, set<string > > :: iterator it = breakfast.begin(); it != breakfast.end(); it++) {
            cout << it->first << " ";
            for (auto it2 = it->second.begin(); it2 != it->second.end(); it2++) {
                cout << *it2 << " ";
            }
            cout << endl;
        }
        cout << endl;

    }
}

