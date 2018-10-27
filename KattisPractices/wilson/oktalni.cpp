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

#define MAX 2147483646

using namespace std;

int main () {
    unordered_map<string, string> binOctalMap = {{"000", "0"}, {"001", "1"}, {"010", "2"}, {"011", "3"}, {"100", "4"}, {"101", "5"}, {"110", "6"}, {"111", "7"}};
    
    string number; cin >> number;
    string newNumber = "";
    if (number.length() % 3){
        for (int i = 0; i < 3 - (number.length()%3); i++) {
            newNumber += "0";
        }
    }
    
    newNumber += number;
    string convertedNumb = "";
    
    for (int i = 0; i < newNumber.length(); i+=3) {
        convertedNumb += binOctalMap[newNumber.substr(i, 3)];
//        cout << newNumber.substr(i, 3) << endl;;
    }
    cout << convertedNumb << endl;
    
}
