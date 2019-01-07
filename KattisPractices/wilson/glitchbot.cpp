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

using namespace std;

tuple<int, int, int> getPosition (tuple<int, int, int> currPosition, string instruction) {
    if (instruction == "Forward") {
        if (get<2>(currPosition) == 0) {
            currPosition = {get<0>(currPosition), get<1>(currPosition)+1, get<2>(currPosition)};
        } else if (get<2>(currPosition) == 90) {
            currPosition = {get<0>(currPosition)+1, get<1>(currPosition), get<2>(currPosition)};
        } else if (get<2>(currPosition) == 180) {
            currPosition = {get<0>(currPosition), get<1>(currPosition)-1, get<2>(currPosition)};
        } else if (get<2>(currPosition) == 270) {
            currPosition = {get<0>(currPosition)-1, get<1>(currPosition), get<2>(currPosition)};
        }
    } else if (instruction == "Left") {
        if (get<2>(currPosition) == 0) {
            currPosition = {get<0>(currPosition), get<1>(currPosition), 270};
        } else if (get<2>(currPosition) == 90) {
            currPosition = {get<0>(currPosition), get<1>(currPosition), 0};
        } else if (get<2>(currPosition) == 180) {
            currPosition = {get<0>(currPosition), get<1>(currPosition), 90};
        } else if (get<2>(currPosition) == 270) {
            currPosition = {get<0>(currPosition), get<1>(currPosition), 180};
        }
    } else if (instruction == "Right") {
        if (get<2>(currPosition) == 0) {
            currPosition = {get<0>(currPosition), get<1>(currPosition), 90};
        } else if (get<2>(currPosition) == 90) {
            currPosition = {get<0>(currPosition), get<1>(currPosition), 180};
        } else if (get<2>(currPosition) == 180) {
            currPosition = {get<0>(currPosition), get<1>(currPosition), 270};
        } else if (get<2>(currPosition) == 270) {
            currPosition = {get<0>(currPosition), get<1>(currPosition), 0};
        }
    }
    return currPosition;
}


int main () {
    vector<string> instructions;
//    vector<tuple<int, int, int>> currPositions; // x, y, position (0 - 270)
    tuple<int, int, int> currPosition;
    string instructionSet[3] = {"Left", "Forward", "Right"};
    int destX, destY; cin >> destX >> destY;
    int n; cin >> n;
    while (n--) {
        string input; cin >> input;
        instructions.push_back(input);
    }

    for (int i = 0; i < instructions.size(); i++) {
        // We store the current position first based on original instructions

        // For each we will try different instructions
        for (int c = 0; c < 3; c++) {
            string currInstr = instructionSet[c];
            tuple<int, int,int> tempCurrPosition = getPosition(currPosition, currInstr);
            for (int d = i+1; d < instructions.size(); d++) {
                tempCurrPosition = getPosition(tempCurrPosition, instructions[d]);
            }
            if (get<0>(tempCurrPosition) == destX && get<1>(tempCurrPosition) == destY) {
                cout << i+1 << " ";
                cout << currInstr << endl;
                return 0;
            }
        }
        
        currPosition = getPosition(currPosition, instructions[i]);
//        cout << get<0>(currPosition) << " " << get<1>(currPosition) << endl;
    }
    
}
