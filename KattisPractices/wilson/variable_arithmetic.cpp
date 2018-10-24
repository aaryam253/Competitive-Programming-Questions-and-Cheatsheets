#include <iostream>
#include <stdio.h>
#include <unordered_map>
#include <sstream>
#include <deque>
#include <string>

using namespace std;

string itos(int i)  // convert int to string
{
    stringstream s;
    s << i;
    return s.str();
}


int main () {
    unordered_map<string, int> string_number;
    while (true) {
        deque<string> myDeque;
        string input;
        getline(cin, input);
        int number = 0;
        
        if (input == "0") break;
        
        istringstream iss (input);
        string token;
        int flag = 0;
        string word_number;
        int special_num = 0;
        while (getline(iss, token, ' '))
        {
            if (token != "+" && token != "=") {
                if (token[0] <= '9' && token[0] >= '0') {
                    special_num = stoi(token);
                    number += stoi(token);
                }
                else if (string_number.find(token) != string_number.end()) {
                    word_number = token;
                    number += string_number[token];
                }else {
                    word_number = token;
                    myDeque.push_back(token);
                }
            }else if (token == "=") {
                flag = 1;
            }
        }
        string output;
        if (flag) {
            flag = 0;
            string_number[word_number] = special_num;
        }else {
            if (number) {
                output += itos(number);
                output += " + ";
            }
            while (!myDeque.empty()) {
                output += myDeque.front();
                output += " + ";
                myDeque.pop_front();
            }
            
            
            output[output.size()-1] = '\0';
            output[output.size()-2] = '\0';
            output[output.size()-3] = '\0';
            cout << output << endl;
        }
    }
    
}


