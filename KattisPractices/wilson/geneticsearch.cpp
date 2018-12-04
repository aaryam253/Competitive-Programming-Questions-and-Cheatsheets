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

#define MAX 1e9

using namespace std;


int main () {
    string input;
    while (getline(cin, input)) {
        string s = "";
        string word;
        istringstream iss (input);
        string token;
        while (getline(iss, token, ' ')) {
            if (s == "") {
                if (token.compare("0") == 0) return 0;
                s = token;
            } else {
                word = token;
            }
        }
//        cout << s << endl;
        // type 1
        int type1 = 0;
        for (int i = 0; i < word.length() - s.length() + 1; i++) {
            if (word.substr(i, s.length()) == s) {
                type1++;
            }
        }
        cout << type1 << " ";
        
        unordered_set<string> uniqueStrings;
        for (int i = 0; i < s.length(); i++) {
            string temp = s.substr(0,i) + s.substr(i+1, s.length());
            uniqueStrings.insert(temp);
        }
        int type2 = 0;
        for (auto it : uniqueStrings) {
            for (int i = 0; i < word.length() - it.length() + 1; i++) {
                if (word.substr(i, it.length()) == it) {
                    type2++;
                }
            }
        }
        cout << type2 << " ";
        
        uniqueStrings.clear();
        string characters = "AGCT";
        
        for(int i = 0; i < s.size()+1; i++) {
            for(int j = 0; j < 4; j++) {
                string temp = s;
                temp.insert(i, 1, characters[j]);
                uniqueStrings.insert(temp);
            }
        }

        int type3 = 0;
        for (auto it : uniqueStrings) {
//            cout << it << endl;
            for (int i = 0; i < word.length() - it.length() + 1; i++) {
                if (word.substr(i, it.length()) == it) {
                    type3++;
                }
            }
        }
        cout << type3;
        
        cout << endl;
        
    }
}


