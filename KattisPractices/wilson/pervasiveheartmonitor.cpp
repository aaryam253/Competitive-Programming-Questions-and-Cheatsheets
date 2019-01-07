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


int main () {
    string input;
    while (getline(cin, input)) {
        vector<string> name;
        istringstream iss (input);
        string token;
        double total = 0;
        int count = 0;
        while (getline(iss, token, ' ')) {
            if (!(token[0] <= '9' && token[0] >= '0')) {
                name.push_back(token);
            } else {
                total += stod(token);
                count++;
            }
        }
        cout << total/count << " ";
        for (auto it : name) {
            cout << it << " ";
        }
        cout << endl;
    }
}
