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


using namespace std;

int main () {
    int i = 1;
    while (true) {
        queue<string> aQueue;
        stack<string> bStack;
        bool toggle = true;
        int num; cin >> num;
        
        if (!num) return 0;
        
        while (num--) {
            string input; cin >> input;
            if (toggle) {
                aQueue.push(input);
                toggle = false;
            } else {
                bStack.push(input);
                toggle = true;
            }
        }
        cout << "SET " << i++ << endl;
        while (!aQueue.empty()) {
            cout << aQueue.front() << endl;
            aQueue.pop();
        }
        while (!bStack.empty()) {
            cout << bStack.top() << endl;
            bStack.pop();
        }

    }
    
}
