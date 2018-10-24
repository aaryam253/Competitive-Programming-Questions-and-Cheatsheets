#include <iostream>
#include <stdio.h>
#include <stdarg.h>
#include <math.h>
#include <list>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <unordered_set>
#include <stack>
#include <algorithm>


using namespace std;

int main () {
    unordered_set<string> store;
    int num;
    cin >> num;
    while (num--) {
        string command, name;
        cin >> command >> name;
        if (command == "entry") {
            if (store.find(name) == store.end()) {
                cout << name << " entered" << endl;
                store.insert(name);
            }else {
                cout << name << " entered (ANOMALY)" << endl;
            }
        }else {
            if (store.find(name) != store.end()) {
                store.erase(name);
                cout << name << " exited" << endl;
            }else {
                cout << name << " exited (ANOMALY)" << endl;
            }
        }
    }
}
