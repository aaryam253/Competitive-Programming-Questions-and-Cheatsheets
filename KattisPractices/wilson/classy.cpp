#include <iostream>
#include <stdio.h>
#include <map>
#include <sstream>
#include <vector>
#include <algorithm>
#include <map>


using namespace std;


int main () {
    
    int TC, pax;
    cin >> TC;
    while (TC--) {
        //vector<pair<unsigned long, string> > my_names;
        vector<pair<unsigned long long, string >> my_names;
        cin >> pax;
        while (pax--) {
            string name;
            string classes;
            string dump;
            cin >> name >> classes >> dump;
            name[name.size()-1] = '\0';
            
            cin.ignore();
            istringstream iss (classes);
            string token;
            string number;
            while (getline(iss, token, '-')) {
                if (token == "upper") {
                    number.push_back('1');
                }else if (token == "middle") {
                    number.push_back('2');
                }else if (token == "lower"){
                    number.push_back('3');
                }
            }
            
            while (number.length() != 10) {
                number.push_back('2');
            }
            unsigned long long value = 0;
            for(auto it = number.begin(); it != number.end(); ++it){
                value *= 10;
                value += *it-'0';
            }
            my_names.push_back(make_pair(value, name));
        }
        
        sort(my_names.begin(), my_names.end());

        
        // TODO: Fix the sorting of names as reversing it will only reverse the order of the names
        for (auto it : my_names) {
            cout << it.second << endl;
        }
        cout << "==============================" << endl;
        
    }
}

