#include <map>
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

int main () {
    int people;
    while (1) {
        cin >> people; if (people == 0) break;
        map<string, vector<string>> food_to_name;
        string name, food, order;
        for (int i = 0; i < people; i++) {
            cin >> name;
            getline(cin, order);
            istringstream b(order);
            while (!b.eof()) {
                b >> food;
                food_to_name[food].push_back(name);
            }
        }
        
        for (auto i = food_to_name.begin(); i != food_to_name.end(); i++) {
            sort(i->second.begin(), i->second.end());
        }
        
        for (auto i = food_to_name.begin(); i != food_to_name.end(); i++) {
            cout << i->first << " ";
            for (auto j = i->second.begin(); j != i->second.end(); j++) {
                cout << *j << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}

 
