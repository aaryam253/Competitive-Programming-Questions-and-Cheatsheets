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
        string hex = "";
        bool flag = false;
        for (int i = 0; i < input.length(); i++) {
            if (input.length() - 1 - i > 2) {
                if (input[i] == '0' && (input[i+1] == 'X' || input[i+1] == 'x')) {
                    hex += input[i];
                    hex += input[i+1];
                    i = i + 2;
                    flag = true;
                }
            }
            if (flag) {
                if (toupper(input[i]) >= 'A') {
                    if (toupper(input[i]) > 'F') {
                        flag = false;
                        cout << hex << " ";
                        transform(hex.begin(), hex.end(), hex.begin(), ::tolower);
                        cout << stoul(hex, nullptr, 16) << endl;
                        hex = "";
                    }
                } else if (input[i] > '9' || input[i] < '0'){
                    flag = false;
                    cout << hex << " ";
                    transform(hex.begin(), hex.end(), hex.begin(), ::tolower);
                    cout << stoul(hex, nullptr, 16) << endl;
                    hex = "";
                }
            }

            
            if (flag) {
                string temp = hex;
                transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
                if (stoul(temp, nullptr, 16) > 4294967295) {
                    flag = false;
                    cout << hex << " " << stoul(temp, nullptr, 16) << endl;
                    hex = "";
                } else {
                    hex += input[i];
                }
            }
        }
        
        if (flag) {
            cout << hex << " " << stoul(hex, nullptr, 16) << endl;
        }
        
    }
}
