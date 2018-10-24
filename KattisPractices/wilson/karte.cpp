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


bool dupes (set<int> thisSet, int target) {
    if (thisSet.find(target) != thisSet.end()) {
        return true;
    }
    return false;
}


int main () {
    set<int> PSet, KSet, HSet, TSet;
    string input; cin >> input;
    
    for (int i = 0; i < input.length(); i += 3) {
//        cout << input.length() << " " << i << endl;
        char X = input[i], Y = input[i+1], Z = input[i+2];
        string num = "";
        num += Y;
        num += Z;
//        cout << stoi(num) << endl;
        switch (X) {
            case 'P':
                if (dupes(PSet, stoi(num))) {
                    cout << "GRESKA" << endl;
                    return 0;
                } else {
                    PSet.insert(stoi(num));
                }
                break;
            case 'K':
                if (dupes(KSet, stoi(num))) {
                    cout << "GRESKA" << endl;
                    return 0;
                } else {
                    KSet.insert(stoi(num));
                }
                
                break;
            case 'H':
                if (dupes(HSet, stoi(num))) {
                    cout << "GRESKA" << endl;
                    return 0;
                } else {
                    HSet.insert(stoi(num));
                }
                
                break;
                
            case 'T':
                if (dupes(TSet, stoi(num))) {
                    cout << "GRESKA" << endl;
                } else {
                    TSet.insert(stoi(num));
                }
                break;
                
        }

    }
    
    cout << 13 - PSet.size() << " ";
    cout << 13 - KSet.size() << " ";
    cout << 13 - HSet.size() << " ";
    cout << 13 - TSet.size() << endl;
    
}
