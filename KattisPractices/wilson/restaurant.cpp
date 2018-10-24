#include <stdio.h>
#include <iostream>
#include <stack>

using namespace std;



int main () {
    
    int num;
    while (1) {
       stack<int> first, second;
       int current = 1;
        cin >> num;
        for (int i = 0; i < num; i++) {
            int d;
            string command;
            cin >> command;
            
            if (command == "TAKE") {
                int amount;
                cin >> amount;
                
                // Transfer over first
                if (first.empty()) {
                    int size = second.size();
                    for (d = 0; d < size; d++) {
                        first.push(second.top());
                        //cout << "Transferred: " << first.top() << endl;
                        second.pop();
                    }
                    cout << "MOVE 2->1 " << d << endl;
                }
                
                if (first.size() < amount) {
                    // Transfer over
                    // Remove first before transferring
                    int firstSize = first.size();
                    for (d = 0; d < firstSize; d++) {
                        //cout << "Removed: " << first.top() << endl;
                        first.pop();
                        amount--;
                    }
                    cout << "TAKE 1 " << d << endl;
                    int size = second.size();
                    for (d = 0; d < size; d++) {
                        first.push(second.top());
                        //cout << "Transferred: " << first.top() << endl;
                        second.pop();
                    }
                    cout << "MOVE 2->1 " << d << endl;
                    
                    for (d = 0; d < amount; d++) {
                        //cout << "Removed: " << first.top() << endl;
                        first.pop();
                    }
                    cout << "TAKE 1 " << d << endl;
                    
                    
                }else {
                    for (d = 0; d < amount; d++) {
                        //cout << "Removed: " << first.top() << endl;
                        first.pop();
                    }
                    cout << "TAKE 1 " << d << endl;
                    
                }
            }
            
            else if (command == "DROP") {
                int amount,d;
                cin >> amount;
                
                for (d = 0; d < amount; d++) {
                    //cout << "Pushed " << current << endl;
                    second.push(current++);
                }
                cout << "DROP 2 " << d << endl;
            }
        }
        if (!num) return 0;
        cout << endl;

    }
}
