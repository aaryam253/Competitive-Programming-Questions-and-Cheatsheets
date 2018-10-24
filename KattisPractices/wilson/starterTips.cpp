#include <iostream>
#include <vector>
#include <stdio.h>
#include <sstream>
#include <map>
#include <unordered_map>

using namespace std;

int main () {
    
    unordered_map<int, char> keyboard;
    unordered_map<char, int> keyboard_map;
    int index = 0;
    // QWERTY dump
    keyboard_map['`'] = index;
    keyboard[index++] = '`';
    
    for (int i = 1; i <= 9; i++) {
        keyboard_map[i+'0'] = index;
        keyboard[index++] = i+'0';
    }
    
    keyboard_map['0'] = index;
    keyboard[index++] = '0';
    keyboard_map['-'] = index;
    keyboard[index++] = '-';
    keyboard_map['='] = index;
    keyboard[index++] = '=';
    string input = "QWERTYUIOP[]";
    
    for (int i = 0; i < input.size(); i++) {
        keyboard_map[input[i]] = index;
        keyboard[index++] = input[i];
    }
    
    keyboard_map[92] = index;
    keyboard[index++] = 92;


    input = "ASDFGHJKL;'";
    for (int i = 0; i < input.size(); i++) {
        keyboard_map[input[i]] = index;
        keyboard[index++] = input[i];
    }
    
    input = "ZXCVBNM,./";
    for (int i = 0; i < input.size(); i++) {
        keyboard_map[input[i]] = index;
        keyboard[index++] = input[i];
    }
    
    string line;
    
    getline (cin, line);
    istringstream iss (line);
    string token;
    while (getline(iss, token, ' '))
    {
        for (int i = 0; i < token.size(); i++) {
            if (keyboard_map.find(token[i]) != keyboard_map.end() && token[i] != 'Q' && token[i] != 'A' && token[i] != 'Z' && token[i] != '`') {
                int number = keyboard_map[token[i]];
                cout << keyboard[--number];
            }else {
                cout << token[i];
            }
        }
        cout << " ";
    }
    cout << '\n';
}

