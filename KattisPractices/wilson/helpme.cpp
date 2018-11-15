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
    char mtx[100][100];
    
    priority_queue<pair<int, string>, vector<pair<int, string>>, greater<>> white;
    priority_queue<pair<int, string>, vector<pair<int, string>>, greater<>> black;
    
    unordered_map<char, int> whiteSet = {{'K',0}, {'Q', 1}, {'R', 2}, {'B', 3}, {'N', 4}, {'P', 5}};
    unordered_map<char, int> blackSet = {{'k',0}, {'q', 1}, {'r', 2}, {'b', 3}, {'n', 4}, {'p', 5}};

    for (int i = 0; i < 17; i++) {
        int count = 0;
        for (int j = 0; j < 33; j++) {
            cin >> mtx[i][j];
            if (mtx[i][j] == '|') {
                count++;
            }
            
            if (whiteSet.find(mtx[i][j]) != whiteSet.end()) {
                string combinedString = "";
                combinedString += mtx[i][j];
                combinedString += to_string((17-i)/2);
                combinedString += 'a' + count  - 1;
                white.push(make_pair(whiteSet[mtx[i][j]], combinedString));
                
            }
            
            if (blackSet.find(mtx[i][j]) != blackSet.end()) {
                string combinedString = "";
                combinedString += toupper(mtx[i][j]);
                combinedString += to_string(8 - (17-i)/2);
                combinedString += 'a' + count  - 1;
                black.push(make_pair(blackSet[mtx[i][j]], combinedString));

            }

            
        }
    }
    
//    for (int i = 0; i < 17; i++) {
//        for (int j = 0; j < 33; j++) {
//            cout << mtx[i][j];
//        }
//        cout << endl;
//    }
    
    cout << "White: ";
    while (!white.empty()) {
        string modifiedString = white.top().second;
        
        if (modifiedString[0] != 'P') {
            cout << modifiedString[0] << modifiedString[2] << modifiedString[1];
        } else {
            cout << modifiedString[2] << modifiedString[1];
        }
        if (white.size() == 1) {
        } else {
            cout << ",";
        }
        white.pop();
    }
    cout << endl;
    
    
    cout << "Black: ";
    while (!black.empty()) {
        string modifiedString = black.top().second;
        char convert = modifiedString[1];
        string convert_;
        convert_ += convert;
        int number = stoi(convert_);
        
        
        if (modifiedString[0] != 'P') {
            cout << modifiedString[0] << modifiedString[2] << 8 - number;
        } else {
            cout << modifiedString[2] << 8 - number;
        }
        if (black.size() == 1) {
        } else {
            cout << ",";
        }
        black.pop();
    }
    cout << endl;

}
