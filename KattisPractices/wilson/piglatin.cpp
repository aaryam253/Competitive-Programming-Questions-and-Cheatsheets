#include <stdio.h>
#include <iostream>
#include <sstream>

using namespace std;

bool checkVowel (char input) {
    char arr[] = {'a', 'e', 'i', 'o', 'u'};
    
    for (int i = 0; i < 5; i++) {
        if (arr[i] == input) return true;
    }
    return false;
}

string snap (string input, int start) {
    string output;
    
    for (int i = start; i < input.size(); i++) {
        output += input[i];
    }
    for (int i = 0; i < start; i++) {
        output += input[i];
    }
    return output;
}

int main () {
    string line;
    while (getline(cin, line)) {
        string output;
        istringstream iss (line);
        string token;
        while (getline(iss, token, ' ')) {
            //cout << token << endl; // Perform operations here
            if (checkVowel(token[0]) || token[0] == 'y') {
                output += token;
                output += "yay ";
            }
            else {
                for (int i = 1; i < token.size(); i++) {
                    if (checkVowel(token[i])) {
                        output += snap(token, i);
                        output += "ay ";
                        break;
                    }
                }
            }
        }
        output[output.size()-1] = '\0'; // Shave off the last space
        cout << output << endl;

    }
}
