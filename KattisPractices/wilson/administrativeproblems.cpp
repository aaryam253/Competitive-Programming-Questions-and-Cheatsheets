#include <iostream>
#include <stdio.h>
#include <stdarg.h>
#include <math.h>
#include <list>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <unordered_map>
#include <stack>
#include <algorithm>


using namespace std;



int main () {
    int TC; cin >> TC;
    while (TC--) {
        unordered_map<string, tuple<int, int, int> > cars;
        unordered_map<string, string > spies;
        map<string, long long > spy_prices;
        
        int numcars, numevents; cin >> numcars >> numevents;
        while (numcars--) {
            string name;
            int a, b, c;
            cin >> name >> a >> b >> c;
            cars[name] = make_tuple(a, b, c);
        }


        while (numevents--) {
            int t, arg;
            char type;
            string name, carname;
            cin >> t >> name >> type;
            
            if (spies.find(name) == spies.end()) {
                spies[name] = "empty";
                spy_prices[name] = 0;
            }
            
            if (type == 'p') {
                cin >> carname;
                // Add in inconsistence checks
                if (spies[name] != "empty") spy_prices[name] = -1;
                
                else if (spy_prices[name] != -1 ){
                    spies[name] = carname;
                    spy_prices[name] += get<1>(cars[carname]);
                }
                
            }else if (type == 'r') {
                cin >> arg;
                // Add inconsistent checks
                if (spies[name] == "empty") spy_prices[name] = -1;
                else if (spy_prices[name] != -1){
                    spy_prices[name] += arg*get<2>(cars[spies[name]]);
                    //cout << get<2>(cars[carname]) << endl;
                    spies[name] = "empty";
                }
            }else if (type == 'a') {
                cin >> arg;
                if (spies[name] == "empty") spy_prices[name] = -1;
                else if (spy_prices[name] != -1){
                    //cout << spy_prices[name] << endl;
                    carname = spies[name];
                    //double percent = arg/100.0;
                    //percent *= get<0>(cars[spies[name]]);
                    //cout << name << " " << percent << endl;
                    spy_prices[name] += (arg * get<0>(cars[carname]) + 99) / 100;
                    
                    //cout << spy_prices[name] << endl;
                }
            }
        }
        
        for (auto it : spy_prices) {
            cout << it.first << " ";
            if (it.second == -1 || spies[it.first] != "empty") {
                cout << "INCONSISTENT";
            }else {
                cout << it.second;
            }
            cout << endl;
        }
    }
    
}
