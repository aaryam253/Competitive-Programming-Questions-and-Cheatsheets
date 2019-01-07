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
        vector<int> numbers;
        istringstream iss (input);
        string token;
        while (getline(iss, token, ' ')) {
            numbers.push_back(stoi(token));
        }
        sort(numbers.rbegin(), numbers.rend());
        int n = numbers[0];
        vector<int> freq(n+1, 0);
        for (int i = 0; i < numbers.size(); i++) {
            for (int d = i+1; d < numbers.size(); d++) {
                freq[numbers[i]-numbers[d]]++;
            }
        }
        vector<int> missing;
        bool isNotRuler = false;
        for (int i = 1; i <= n; i++) {
            if (!freq[i]) {
                missing.push_back(i);
            } else if (freq[i] >= 2) {
                isNotRuler = true;
                break;
            }
        }
        if (!isNotRuler && missing.size() == 0) {
            cout << "perfect" << endl;
        } else if (isNotRuler) {
            cout << "not a ruler" << endl;
        } else if (missing.size() > 0) {
            cout << "missing ";
            for (auto it : missing) {
                cout << it << " ";
            }
            cout << endl;
        }
    }
}
