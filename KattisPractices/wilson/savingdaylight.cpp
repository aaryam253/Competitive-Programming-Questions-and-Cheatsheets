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
        istringstream iss (input);
        string token;
        int count = 0;
        while (getline(iss, token, ' ')) {
            int a, b;
            if (count <= 2) {
                cout << token << " ";
            } else if (count == 3) {
                int count2 = 0;
                istringstream iss2 (token);
                string token2;
                int minutes = 0;
                while (getline(iss2, token2, ':')) {
                    if (!count2) {
                        minutes = stoi(token2)*60;
                    } else {
                        minutes += stoi(token2);
                    }
                    count2++;
                }
                a = minutes;
            } else {
                int count2 = 0;
                istringstream iss2 (token);
                string token2;
                int minutes = 0;
                while (getline(iss2, token2, ':')) {
                    if (!count2) {
                        minutes = stoi(token2)*60;
                    } else {
                        minutes += stoi(token2);
                    }
                    count2++;
                }
                b = minutes;
                int diff = (b - a)/60;
                int minu = (b-a) % 60;
                cout << diff << " hours " << minu << " minutes";
            }
            count++;
        }
        cout << endl;
    }
}


