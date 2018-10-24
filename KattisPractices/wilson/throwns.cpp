#include <iostream>
#include <stdio.h>
#include <deque>
#include <string>

using namespace std;


int main () {
    deque<int> command_stack;
    
    int num_students, commands;
    cin >> num_students >> commands;
    
    int curr = 0;
    while (commands--) {
        string input;
        cin >> input;
        if (input == "undo") {
            int amt;
            cin >> amt;
            while (amt--) {
                command_stack.pop_back();
            }
        }else {
            int move = stoi(input);
            command_stack.push_back(move);
        }
    }
    for (auto it : command_stack) {
        curr += it;
        curr %= num_students;
        while(curr < 0) {
            curr += num_students;
        }
    }
    cout << curr << endl;
}
