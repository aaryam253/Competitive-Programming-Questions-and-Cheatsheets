#include <iostream>
#include <stdio.h>
#include <stdarg.h>
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
#include <algorithm>


using namespace std;

int main () {
    int TC;
    unordered_map<char, int> codeMap;
    unordered_map<char, char> transposeMap;
    codeMap['0'] = 0;
    codeMap['1'] = 1;
    codeMap['2'] = 2;
    codeMap['3'] = 3;
    codeMap['4'] = 4;
    codeMap['5'] = 5;
    codeMap['6'] = 6;
    codeMap['7'] = 7;
    codeMap['8'] = 8;
    codeMap['9'] = 9;
    codeMap['A'] = 10;
    codeMap['C'] = 11;
    codeMap['D'] = 12;
    codeMap['E'] = 13;
    codeMap['F'] = 14;
    codeMap['H'] = 15;
    codeMap['J'] = 16;
    codeMap['K'] = 17;
    codeMap['L'] = 18;
    codeMap['M'] = 19;
    codeMap['N'] = 20;
    codeMap['P'] = 21;
    codeMap['R'] = 22;
    codeMap['T'] = 23;
    codeMap['V'] = 24;
    codeMap['W'] = 25;
    codeMap['X'] = 26;
    
    transposeMap['B'] = '8';
    transposeMap['G'] = 'C';
    transposeMap['I'] = '1';
    transposeMap['O'] = '0';
    transposeMap['Q'] = '0';
    transposeMap['S'] = '5';
    transposeMap['U'] = 'V';
    transposeMap['Y'] = 'V';
    transposeMap['Z'] = '2';
    
    string codeArray = "0123456789ACDEFHJKLMNPRTVWX";

    int multiplier [8] = {2, 4, 5, 7, 8, 10, 11, 13};
    cin >> TC;
    for (int i = 0 ; i < TC; i++) {
        int num; cin >> num;
        string input; cin >> input;
        int total = 0;
        long long sum = 0;

        for (int d = 0; d < 8; d++) {
            char target;
            if (transposeMap[input[d]] == 0) {
                target = input[d];
            } else {
                target = transposeMap[input[d]];
            }
            total += multiplier[d]*codeMap[target];
            sum += pow(27, 7-d) * codeMap[target];
            
        }
        cout << num << " ";
        if (codeArray[total % 27] == input[8]) {
            cout << sum << endl;
        } else {
            cout << "Invalid" << endl;
        }
    }
}
