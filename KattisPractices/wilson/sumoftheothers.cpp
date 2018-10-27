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

#define MAX 2147483646

using namespace std;

int main () {
    string input;
    while (getline(cin, input)) {
        vector<int> integers;
        char inputChar[1000];
        const char s[2] = " ";
        char *token;
        /* get the first token */
        strcpy(inputChar, input.c_str());
        
        token = strtok(inputChar, s);
        
        /* walk through other tokens */
        while( token != NULL ) {
            // Do fancy functions here, token is a string
            integers.push_back(stoi(token));
            token = strtok(NULL, s);
        }
        
        for (int i = 0; i < integers.size(); i++) {
            int target = integers[i];
            int sum = 0;
            for (int j = 0; j < integers.size(); j++) {
                if (j != i) {
                    sum += integers[j];
                }
            }
            if (target == sum) {
                cout << sum << endl;
                break;
            }
        }
        
    }
    
}
