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

#define MAX 2147483646

using namespace std;


int main () {
    unordered_map<int, string> names = {{0,"zero"},
        {1,"one"},
        {2,"two"},
        {3,"three"},
        {4,"four"},
        {5,"five"},
        {6,"six"},
        {7,"seven"},
        {8,"eight"},
        {9,"nine"},
        {10,"ten"},
        {11,"eleven"},
        {12,"twelve"},
        {13,"thirteen"},
        {14,"fourteen"},
        {15,"fifteen"},
        {16,"sixteen"},
        {17,"seventeen"},
        {18,"eighteen"},
        {19,"nineteen"},
        {20,"twenty"},
        {30,"thirty"},
        {40,"forty"},
        {50,"fifty"},
        {60,"sixty"},
        {70,"seventy"},
        {80,"eighty"},
        {90,"ninety"}};

    string input;

    while (getline(cin, input)) {
        istringstream iss (input);
        string token;
        bool isFirst = true;
        while (getline(iss, token, ' ')) {
            if (token.size() == 1 && token[0] >= '0' && token[0] <= '9') {
                int number = stoi(token);
                string number_ = names[number];
                if (isFirst) {
                    number_[0] = toupper(number_[0]);
                    isFirst = false;
                }
                
                cout << number_ << " ";
                
            } else if (token.size() == 2 && token[1] <= '9' && token[1] >= '0') {
                // two digit number
                
                if (token[0] >= '2') {
                    int tenth_ = token[0] - '0';
                    tenth_ *= 10;
                    string tenth = names[tenth_];
                    if (isFirst) {
                        tenth[0] = toupper(tenth[0]);
                        isFirst = false;
                    }
                    
                    if (token[1] != '0') {
                        cout << tenth << "-";
                        int number = token[1] - '0';
                        string small_ = names[number];
                        cout << small_ << " ";
                    } else {
                        cout << tenth << " ";
                    }
                } else {
                    string number = names[stoi(token)];
                    if (isFirst) {
                        number[0] = toupper(number[0]);
                        isFirst = false;
                    }
                    cout << number << " ";
                }
                

            } else {
                cout << token << " ";
                isFirst = false;
            }
            
        }
        cout << endl;
    }
    
    

}
