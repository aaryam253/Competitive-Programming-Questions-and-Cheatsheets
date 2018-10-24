#include <iostream>
#include <vector>
#include <stdio.h>
#include <list>
#include <deque>
#include <algorithm>
#include <functional>
#include <unordered_map>
#include <stack>
#include <sstream>

using namespace std;

int main () {
    unordered_map<string, int> string_number;
    unordered_map<int, string> number_string;
    string instr;

    while (cin >> instr) {
        
        if (instr == "def") {
            string input;
            int number;
            cin >> input >> number;
            
            auto it = string_number.find(input);
            if (it != string_number.end()) {
                // Number exists, clear previous
                int old_val = string_number[input];
                string_number.erase(input);
                number_string.erase(old_val);
            }
            string_number[input] = number;
            number_string[number] = input;
        }
        else if (instr == "calc") {
            string line, var;
            char c;
            int sum = 0;
            int mult = 1;
            string ans = "";
            
            getline(cin, line);
            istringstream iss(line.substr(1));
            
            while(iss >> var){
                if(string_number.find(var) == string_number.end()){
                    ans = "unknown";
                    break;
                } else {
                    sum += mult*string_number[var];
                }
                iss >> c;
                if(c == '+'){
                    mult = 1;
                } else if(c == '-'){
                    mult = -1;
                } else { //=
                    if(number_string.find(sum) != number_string.end()){
                        ans = number_string[sum];
                    } else {
                        ans = "unknown";
                    }
                    break;
                }
            }
            cout << line.substr(1) << " " << ans << endl;
        }
        
        else if (instr == "clear") {
            string_number.clear();
            number_string.clear();
        }
        
    }
    
}

// TODO: Find a test case that breaks this prog
