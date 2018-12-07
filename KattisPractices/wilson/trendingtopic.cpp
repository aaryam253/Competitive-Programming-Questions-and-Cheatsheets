#include <iostream>
#include <stdio.h>
#include <math.h>
#include <list>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <algorithm>
#include <tuple>
#include <string.h>
#include <sstream>

#define MAX 2147483640

using namespace std;

int query (string input) {
    istringstream iss (input);
    string token;
    bool isQuery = false;
    int number = -1;
    
    while (getline(iss, token, ' ')) {
        if (token == "<top") {
            isQuery = true;
        }
        else if (isQuery) {
            if (isalnum(token[0])) {
                number = stoi(token);
            }
            return number;
        }
    }
    return number;
}

int main () {
    string input;
    bool record = false;
    //    queue<unordered_map<string, int>> q;
    
    list<unordered_map<string, int>> q;
//    q.push_front({});
    while (getline(cin, input)) {
        
        if (input == "<text>") {
            record = true;
            q.push_front({});
        } else if (input == "</text>") {
            record = false;
        } else if (record) {
            istringstream iss (input);
            string token;
            while (getline(iss, token, ' ')) {
                if (token.size() >= 4) {
                    //                    cout << token << endl; // Perform operations here
                    q.front()[token]++;
                }
            }
        } else if (query(input) != -1) {
            //            cout << query(input) << endl;
            int count = 0;
            map<int, set<string>, greater<>> m;
            map<string, int> compiled;
            
            for (auto it : q) {
                if (count >= 7) break;
                for (auto it2 : it) {
                    //                    m[it2.second].insert(it2.first);
                    compiled[it2.first] += it2.second;
                }
                count++;
            }
            
            for (auto it : compiled) {
                m[it.second].insert(it.first);
            }
            
            cout << "<top" << " " << query(input) << ">" << endl;;
            count = 0;
            for (auto it : m) {
                if (count >= query(input)) break;
                for (auto it2 : it.second) {
                    cout << it2 << " " << it.first << endl;
                    count++;
                }
            }
            cout << "</top>" << endl;
        }
    }
}
